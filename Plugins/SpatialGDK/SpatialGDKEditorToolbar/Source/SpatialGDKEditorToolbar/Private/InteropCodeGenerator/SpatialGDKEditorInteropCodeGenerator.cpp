// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SpatialGDKEditorInteropCodeGenerator.h"

#include "GenericPlatform/GenericPlatformFile.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "SchemaGenerator.h"
#include "TypeBindingGenerator.h"
#include "TypeStructure.h"
#include "SpatialGDKEditorUtils.h"
#include "Utils/CodeWriter.h"
#include "Utils/ComponentIdGenerator.h"
#include "Utils/DataTypeUtilities.h"

#include "Misc/FileHelper.h"

DEFINE_LOG_CATEGORY(LogSpatialGDKInteropCodeGenerator);

namespace
{

int GenerateCompleteSchemaFromClass(const FString& SchemaPath, const FString& ForwardingCodePath, int ComponentId, UClass* Class, const TArray<FString>& TypeBindingHeaders, bool bIsSingleton)
{
	FCodeWriter OutputSchema;
	FCodeWriter OutputHeader;
	FCodeWriter OutputSource;

	FString SchemaFilename = FString::Printf(TEXT("Unreal%s"), *UnrealNameToSchemaTypeName(Class->GetName()));
	FString TypeBindingFilename = FString::Printf(TEXT("SpatialTypeBinding_%s"), *Class->GetName());

	// Parent and static array index start at 0 for checksum calculations.
	TSharedPtr<FUnrealType> TypeInfo = CreateUnrealTypeInfo(Class, 0, 0, false);

	// Generate schema.
	int NumComponents = GenerateTypeBindingSchema(OutputSchema, ComponentId, Class, TypeInfo, SchemaPath);
	OutputSchema.WriteToFile(FString::Printf(TEXT("%s%s.schema"), *SchemaPath, *SchemaFilename));

	// Generate forwarding code.
	GenerateTypeBindingHeader(OutputHeader, SchemaFilename, TypeBindingFilename, Class, TypeInfo);
	GenerateTypeBindingSource(OutputSource, SchemaFilename, TypeBindingFilename, Class, TypeInfo, TypeBindingHeaders, bIsSingleton);
	OutputHeader.WriteToFile(FString::Printf(TEXT("%s%s.h"), *ForwardingCodePath, *TypeBindingFilename));
	OutputSource.WriteToFile(FString::Printf(TEXT("%s%s.cpp"), *ForwardingCodePath, *TypeBindingFilename));

	return NumComponents;
}

bool CheckClassNameListValidity(const ClassHeaderMap& Classes)
{
	// Pull out all the class names from the map. (These might contain underscores like "One_TwoThree" and "OneTwo_Three").
	TArray<FString> ClassNames;
	Classes.GetKeys(ClassNames);

	// Remove all underscores from the class names, check for duplicates.
	for (int i = 0; i < ClassNames.Num() - 1; ++i)
	{
		const FString& ClassA = ClassNames[i];
		const FString SchemaTypeA = UnrealNameToSchemaTypeName(ClassA);

		for (int j = i + 1; j < ClassNames.Num(); ++j)
		{
			const FString& ClassB = ClassNames[j];
			const FString SchemaTypeB = UnrealNameToSchemaTypeName(ClassB);

			if (SchemaTypeA.Equals(SchemaTypeB))
			{
				UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Class name collision after removing underscores: '%s' and '%s' - schema not generated"), *ClassA, *ClassB);
				return false;
			}
		}
	}
	return true;
}
}// ::

// Handle Unreal's naming of blueprint C++ files which are appended with _C.
// It is common for users to not know about this feature and simply add the blueprint name to the DefaultSpatialGDK.ini ClassesToGenerate section
// As such, when the passed in ClassName is invalid, we will add '_C' to the user provided ClassName if that gives us a valid class.
bool CheckClassExistsWithCorrectionForBlueprints(FString& ClassName)
{
	if (LoadObject<UClass>(nullptr, *ClassName, nullptr, LOAD_EditorOnly, nullptr))
	{
		return true;
	}

	UE_LOG(LogSpatialGDKInteropCodeGenerator, Verbose, TEXT("Could not find unreal class for interop code generation: '%s', trying to find %s_C..."), *ClassName, *ClassName);

	if (LoadObject<UClass>(nullptr, *(ClassName + TEXT("_C")), nullptr, LOAD_EditorOnly, nullptr))
	{
		// Correct for user mistake: add _C to ClassName so we return the valid blueprint name
		ClassName.Append(TEXT("_C"));
		return true;
	}

	UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Could not find unreal class for interop code generation: '%s'."), *ClassName);

	return false;
}

bool GenerateClassHeaderMap(const FConfigSection* UserInteropCodeGenSection, ClassHeaderMap& OutClasses)
{
	TArray<FName> AllCodeGenKeys;
	UserInteropCodeGenSection->GetKeys(AllCodeGenKeys);

	// Iterate over the keys (class names) and extract header includes.
	for (FName ClassKey : AllCodeGenKeys)
	{
		TArray<FString> HeaderValueArray;
		UserInteropCodeGenSection->MultiFind(ClassKey, HeaderValueArray);
		FString ClassName = ClassKey.ToString();

		// Check class exists, correcting user typos if necessary.
		if (!CheckClassExistsWithCorrectionForBlueprints(ClassName))
		{
			return false;
		}

		// Now, ClassName is a class that must exist.
		// Note this doesn't modify UserInteropCodeGenSection, which still contains old class names without _C.
		OutClasses.Add(ClassName, HeaderValueArray);

		// Just for some user facing logging.
		FString Headers = FString::Join(HeaderValueArray, TEXT(" "));
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Log, TEXT("Found class to generate interop code for: '%s', with includes %s"), *ClassName, *Headers);
	}
	return true;
}

FString GetOutputPath(const FString& ConfigFilePath)
{
	FString OutputPath = FString::Printf(TEXT("%s/Generated/"), FApp::GetProjectName());
	const FString SettingsSectionName = "InteropCodeGen.Settings";
	if (const FConfigSection* SettingsSection = GetConfigSection(ConfigFilePath, SettingsSectionName))
	{
		if (const FConfigValue* OutputModuleSetting = SettingsSection->Find("OutputPath"))
		{
			OutputPath = OutputModuleSetting->GetValue();
		}
	}

	// Ensure that the specified path ends with a path separator.
	OutputPath.AppendChar('/');

	return OutputPath;
}

TArray<FString> CreateSingletonListFromConfigFile()
{
	TArray<FString> SingletonList;

	const FString FileName = "DefaultEditorSpatialGDK.ini";
	const FString ConfigFilePath = FPaths::SourceConfigDir().Append(FileName);

	// Load the SpatialGDK config file
	const FConfigFile* ConfigFile = LoadConfigFile(ConfigFilePath);
	if (!ConfigFile)
	{
		return SingletonList;
	}

	const FString SectionName = "SnapshotGenerator.SingletonActorClasses";
	const FConfigSection* SingletonActorClassesSection = GetConfigSection(ConfigFilePath, SectionName);
	if (SingletonActorClassesSection == nullptr)
	{
		return SingletonList;
	}

	TArray<FName> SingletonActorClasses;
	SingletonActorClassesSection->GetKeys(SingletonActorClasses);

	for (FName ClassName : SingletonActorClasses)
	{
		SingletonList.Add(ClassName.ToString());
	}

	return SingletonList;
}

void GenerateInteropFromClasses(const ClassHeaderMap& Classes, const FString& CombinedSchemaPath, const FString& CombinedForwardingCodePath)
{
	TArray<FString> SingletonList = CreateSingletonListFromConfigFile();

	// Component IDs 100000 to 100009 reserved for other SpatialGDK components.
	int ComponentId = 100010;
	for (auto& ClassHeaderList : Classes)
	{
		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *ClassHeaderList.Key);

		const TArray<FString>& TypeBindingHeaders = ClassHeaderList.Value;
		bool bIsSingleton = SingletonList.Find(ClassHeaderList.Key) != INDEX_NONE;

		ComponentId += GenerateCompleteSchemaFromClass(CombinedSchemaPath, CombinedForwardingCodePath, ComponentId, Class, TypeBindingHeaders, bIsSingleton);
	}
}

bool RunProcess(const FString& Command, const FString& Arguments)
{
	int32 ReturnCode = 0;
	FString StandardOutput;

	void* ReadPipe = nullptr;
	void* WritePipe = nullptr;
	FPlatformProcess::CreatePipe(ReadPipe, WritePipe);
	FProcHandle ProcHandle = FPlatformProcess::CreateProc(*Command, *Arguments, false, true, true, nullptr, 0, nullptr, WritePipe, ReadPipe);

	if (ProcHandle.IsValid())
	{
		FPlatformProcess::WaitForProc(ProcHandle);
		StandardOutput = FPlatformProcess::ReadPipe(ReadPipe);
		FPlatformProcess::GetProcReturnCode(ProcHandle, &ReturnCode);
	}

	FPlatformProcess::ClosePipe(ReadPipe, WritePipe);
	FPlatformProcess::CloseProc(ProcHandle);

	if (ReturnCode != 0)
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("%s"), *StandardOutput);
		return false;
	}

	UE_LOG(LogSpatialGDKInteropCodeGenerator, Display, TEXT("%s"), *StandardOutput);
	return true;
}

bool SpatialGDKGenerateInteropCode()
{
	// SpatialGDK config file definitions.
	const FString FileName = "DefaultEditorSpatialGDK.ini";
	const FString ConfigFilePath = FPaths::SourceConfigDir().Append(FileName);
	// Load the SpatialGDK config file
	LoadConfigFile(ConfigFilePath);

	const FString UserClassesSectionName = "InteropCodeGen.ClassesToGenerate";
	const FConfigSection* UserInteropCodeGenSection = GetConfigSection(ConfigFilePath, UserClassesSectionName);

	if (UserInteropCodeGenSection == nullptr)
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Unable to find section 'InteropCodeGen.ClassesToGenerate'."));
		return false;
	}

	if (!GenerateClassHeaderMap(UserInteropCodeGenSection, InteropGeneratedClasses))  // Checks that all classes are found and generate the class mapping.
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Not all classes found; check your DefaultEditorSpatialGDK.ini file."));
		return false;
	}

	if (!CheckClassNameListValidity(InteropGeneratedClasses))
	{
		return false;
	}

	const FString CombinedSchemaIntermediatePath = FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Intermediate/Improbable/"), *FGuid::NewGuid().ToString(), TEXT("/"));
	FString AbsoluteCombinedSchemaIntermediatePath = FPaths::ConvertRelativePathToFull(CombinedSchemaIntermediatePath);
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*AbsoluteCombinedSchemaIntermediatePath);

	const FString CombinedSchemaPath = FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("../spatial/schema/improbable/unreal/generated/"));
	FString AbsoluteCombinedSchemaPath = FPaths::ConvertRelativePathToFull(CombinedSchemaPath);

	const FString CombinedIntermediatePath = FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Intermediate/Improbable/"), *FGuid::NewGuid().ToString(), TEXT("/"));
	FString AbsoluteCombinedIntermediatePath = FPaths::ConvertRelativePathToFull(CombinedIntermediatePath);
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*AbsoluteCombinedIntermediatePath);

	const FString CombinedForwardingCodePath = FPaths::Combine(*FPaths::GetPath(FPaths::GameSourceDir()), *GetOutputPath(ConfigFilePath).Append(TEXT("Typebindings/")));
	FString AbsoluteCombinedForwardingCodePath = FPaths::ConvertRelativePathToFull(CombinedForwardingCodePath);

	UE_LOG(LogSpatialGDKInteropCodeGenerator, Display, TEXT("Schema path %s - Forwarding code path %s"), *AbsoluteCombinedSchemaPath, *AbsoluteCombinedForwardingCodePath);

	// Check schema path is valid.
	if (!FPaths::CollapseRelativeDirectories(AbsoluteCombinedSchemaPath))
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Invalid path: '%s'. Schema not generated."), *AbsoluteCombinedSchemaPath);
		return false;
	}

	if (!FPaths::CollapseRelativeDirectories(AbsoluteCombinedForwardingCodePath))
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Invalid path: '%s'. schema not generated."), *AbsoluteCombinedForwardingCodePath);
		return false;
	}

	GenerateInteropFromClasses(InteropGeneratedClasses, AbsoluteCombinedSchemaIntermediatePath, AbsoluteCombinedIntermediatePath);

	const FString DiffCopyPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Scripts/DiffCopy.bat")));

	// Copy Interop files.
	FString DiffCopyArguments = FString::Printf(TEXT("\"%s\" \"%s\" --remove-input"), *AbsoluteCombinedIntermediatePath, *AbsoluteCombinedForwardingCodePath);
	if (!RunProcess(DiffCopyPath, DiffCopyArguments))
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Could not move generated interop files during the diff-copy stage. Path: '%s', arguments: '%s'."), *DiffCopyPath, *DiffCopyArguments);
		return false;
	}

	// Copy schema files
	DiffCopyArguments = FString::Printf(TEXT("\"%s\" \"%s\" --remove-input"), *AbsoluteCombinedSchemaIntermediatePath, *AbsoluteCombinedSchemaPath);
	if (!RunProcess(DiffCopyPath, DiffCopyArguments))
	{
		UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Could not move generated schema files during the diff-copy stage. Path: '%s', arguments: '%s'."), *DiffCopyPath, *DiffCopyArguments);
		return false;
	}

	// Run Codegen
	//const FString CodegenPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Scripts/Codegen.bat")));
	//if (!RunProcess(CodegenPath, TEXT("")))
	//{
	//	UE_LOG(LogSpatialGDKInteropCodeGenerator, Error, TEXT("Spatial C++ Worker Codegen failed. Path: '%s'."), *CodegenPath);
	//	return false;
	//}

	const FString SchemaCompilerPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Binaries/ThirdParty/Improbable/Programs/schema_compiler.exe")));

	const FString GeneratedSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("../spatial/schema/improbable/unreal/generated/")));
	const FString CoreSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("../spatial/schema/improbable/unreal/gdk/")));
	const FString StandardSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Binaries/ThirdParty/Improbable/Programs/schema/improbable")));

	const FString CppOutputPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GameSourceDir()), *GetOutputPath(ConfigFilePath).Append(TEXT("Cpp/"))));
	const FString JsonOutputPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Intermediate/Improbable/Json")));

	TArray<FString> GeneratedSchemaFiles;
	IFileManager::Get().FindFiles(GeneratedSchemaFiles, *GeneratedSchemaPath, nullptr);
	TArray<FString> CoreSchemaFiles;
	IFileManager::Get().FindFiles(CoreSchemaFiles, *CoreSchemaPath, nullptr);
	TArray<FString> StandardSchemaFiles;
	IFileManager::Get().FindFiles(StandardSchemaFiles, *StandardSchemaPath, nullptr);

	FString AllSchema = TEXT("");

	for(const FString& SchemaFile : GeneratedSchemaFiles)
	{
		FString FullSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*GeneratedSchemaPath, *SchemaFile));
		AllSchema.Append(*FullSchemaPath).Append(TEXT(" "));
	}

	for(const FString& SchemaFile : CoreSchemaFiles)
	{
		FString FullSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*CoreSchemaPath, *SchemaFile));
		AllSchema.Append(*FullSchemaPath).Append(TEXT(" "));
	}

	for(const FString& SchemaFile : StandardSchemaFiles)
	{
		FString FullSchemaPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*StandardSchemaPath, *SchemaFile));
		AllSchema.Append(*FullSchemaPath).Append(TEXT(" "));
	}

	const FString GeneratedSchemaCompilePath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("../spatial/schema/")));
	const FString StandardSchemaCompilePath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*FPaths::GetPath(FPaths::GetProjectFilePath()), TEXT("Binaries/ThirdParty/Improbable/Programs/schema/")));

	const FString CodegenArguments = FString::Printf(TEXT("--cpp_out=%s --ast_json_out=%s --schema_path=%s --schema_path=%s --load_all_schema_on_schema_path %s"), *CppOutputPath, *JsonOutputPath, *GeneratedSchemaCompilePath, *StandardSchemaCompilePath, *AllSchema);

	FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*CppOutputPath);
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*JsonOutputPath);

	RunProcess(SchemaCompilerPath, CodegenArguments);


	FString GeneratedSchemaJsonPath = JsonOutputPath;
	GeneratedSchemaJsonPath.Append(TEXT("/improbable/unreal/generated"));
	TArray<FString> GeneratedSchemaJsonFiles;
	IFileManager::Get().FindFiles(GeneratedSchemaJsonFiles, *GeneratedSchemaJsonPath, nullptr);

	FString CoreSchemaJsonPath = JsonOutputPath;
	CoreSchemaJsonPath.Append(TEXT("/improbable/unreal/gdk"));
	TArray<FString> CoreSchemaJsonFiles;
	IFileManager::Get().FindFiles(CoreSchemaJsonFiles, *CoreSchemaJsonPath, nullptr);

	FString StandardSchemaJsonPath = JsonOutputPath;
	StandardSchemaJsonPath.Append(TEXT("/improbable"));
	TArray<FString> StandardSchemaJsonFiles;
	IFileManager::Get().FindFiles(StandardSchemaJsonFiles, *StandardSchemaJsonPath, nullptr);

	TArray<FString> AllSchemaComponents;

	for(const FString& SchemaJson : GeneratedSchemaJsonFiles)
	{
		FString FullJsonPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*GeneratedSchemaJsonPath, *SchemaJson));
		FString SchemaJson;

		FFileHelper::LoadFileToString(SchemaJson, *FullJsonPath);

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(SchemaJson);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			TArray<TSharedPtr<FJsonValue>> ComponentArray = JsonParsed->GetArrayField("componentDefinitions");

			for(const TSharedPtr<FJsonValue>& Element : ComponentArray)
			{
				FString componentName = Element->AsObject()->GetStringField("qualifiedName");
				componentName = componentName.Replace(TEXT("."), TEXT("::"));

				const TCHAR* test = *componentName;
				auto a = 1;

				AllSchemaComponents.Add(componentName);
			}
		}
	}

	for(const FString& SchemaJson : StandardSchemaJsonFiles)
	{
		FString FullJsonPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*StandardSchemaJsonPath, *SchemaJson));
		FString SchemaJson;

		FFileHelper::LoadFileToString(SchemaJson, *FullJsonPath);

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(SchemaJson);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			TArray<TSharedPtr<FJsonValue>> ComponentArray = JsonParsed->GetArrayField("componentDefinitions");

			for(const TSharedPtr<FJsonValue>& Element : ComponentArray)
			{
				FString componentName = Element->AsObject()->GetStringField("qualifiedName");
				componentName = componentName.Replace(TEXT("."), TEXT("::"));

				const TCHAR* test = *componentName;
				auto a = 1;

				AllSchemaComponents.Add(componentName);
			}
		}
	}

	for (const FString& SchemaJson : CoreSchemaJsonFiles)
	{
		FString FullJsonPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(*CoreSchemaJsonPath, *SchemaJson));
		FString SchemaJson;

		FFileHelper::LoadFileToString(SchemaJson, *FullJsonPath);

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(SchemaJson);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			TArray<TSharedPtr<FJsonValue>> ComponentArray = JsonParsed->GetArrayField("componentDefinitions");

			for (const TSharedPtr<FJsonValue>& Element : ComponentArray)
			{
				FString componentName = Element->AsObject()->GetStringField("qualifiedName");
				componentName = componentName.Replace(TEXT("."), TEXT("::"));

				const TCHAR* test = *componentName;
				auto a = 1;

				AllSchemaComponents.Add(componentName);
			}
		}
	}

	FCodeWriter Writer;

	Writer.Printf(R"""(
		// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
		// Note that this file has been generated automatically
		#pragma once

		#include <improbable/worker.h>)""");
	Writer.PrintNewLine();

	TArray<FString> ComponentHeaders;

	for(const FString& Component : GeneratedSchemaFiles)
	{
		FString ComponentHeader = Component.Replace(TEXT(".schema"), TEXT(".h"));
		ComponentHeader.InsertAt(0, TEXT("improbable/unreal/generated"));

		ComponentHeaders.Add(ComponentHeader);
	}

	for(const FString& Component : CoreSchemaFiles)
	{
		FString ComponentHeader = Component.Replace(TEXT(".schema"), TEXT(".h"));
		ComponentHeader.InsertAt(0, TEXT("improbable/unreal/gdk"));

		ComponentHeaders.Add(ComponentHeader);
	}

	for(const FString& Component : StandardSchemaFiles)
	{
		FString ComponentHeader = Component.Replace(TEXT(".schema"), TEXT(".h"));
		ComponentHeader.InsertAt(0, TEXT("improbable/"));

		ComponentHeaders.Add(ComponentHeader);
	}

	for(const FString& ComponentHeader : ComponentHeaders)
	{
		Writer.Printf("#include \"%s\"", *ComponentHeader);
	}

	Writer.PrintNewLine();

	Writer.Print(R"""(
namespace improbable
{
namespace unreal
{
	using Components = worker::Components<)""");

	Writer.Indent();
	Writer.Indent();
	for(int i = 0; i < AllSchemaComponents.Num(); i++)
	{
		const FString& Component = AllSchemaComponents[i];

		if(i == AllSchemaComponents.Num() - 1)
		{
			Writer.Printf("%s>", *Component);
			break;
		}

		Writer.Printf("%s,", *Component);
	}

	Writer.PrintNewLine();
	Writer.Outdent();
	Writer.Outdent();
	Writer.Print("} // ::unreal");
	Writer.Print("} // ::improbable");

	Writer.WriteToFile(TEXT("woo.abc"));

	Writer.WriteToFile(FString::Printf(TEXT("%s%s.h"), *CombinedForwardingCodePath, TEXT("SpatialComponents")));

	return true;
}
