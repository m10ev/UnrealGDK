using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Improbable.CodeGeneration.FileHandling;
using Improbable.CodeGeneration.Model;
using Improbable.CodeGeneration.Test;
using Improbable.Unreal.CodeGeneration.Jobs;
using Improbable.Unreal.CodeGeneration.SchemaProcessing;
using NUnit.Framework;

namespace Improbable.Unreal.CodeGeneration.Test.Jobs.Unreal
{
    public class UnrealComponentJobTest
    {
        [Test]
        public static void run_writes_the_expected_output_files_to_disk()
        {
            var fileSystem = GenerateMockFileSystem();
            fileSystem.GetFileInfoMock = (path) =>
            {
                var fileWrapper = new MockFileWrapper(path, Path.GetDirectoryName(path), new DateTime(1, 1, 1));
                fileWrapper.ExistsMock = () => { return true; };
                fileWrapper.DeleteMock = () => { };
                return fileWrapper;
            };

            var schemaFileRaw = TestUtils.GetRawJsonDataFromResource<SchemaFileRaw>("Improbable.CodeGeneration.Resources.json.test.command.json");

            var schemaFileProcessor = new UnrealSchemaProcessor(new List<SchemaFileRaw>() { schemaFileRaw });
            var job = new UnrealComponentJob(schemaFileProcessor.unrealComponentDetails.First(), outputDir, fileSystem);

            job.Run();

            Assert.That(fileSystem.WrittenFiles.Count == 5, "UnrealComponentJob did not write the expected number of files");

            var fullOutputDir = Path.Combine("Codegen", "Test");
            Assert.That(fileSystem.WrittenFiles.Contains(Path.Combine(fullOutputDir, "ExampleComponentComponent.h")), "UnrealComponentJob did not write the expected files");
            Assert.That(fileSystem.WrittenFiles.Contains(Path.Combine(fullOutputDir, "ExampleComponentComponent.cpp")), "UnrealComponentJob did not write the expected files");
            Assert.That(fileSystem.WrittenFiles.Contains(Path.Combine(fullOutputDir, "ExampleComponentComponentUpdate.h")), "UnrealComponentJob did not write the expected files");
            Assert.That(fileSystem.WrittenFiles.Contains(Path.Combine(fullOutputDir, "ExampleComponentComponentUpdate.cpp")), "UnrealComponentJob did not write the expected files");
            Assert.That(fileSystem.WrittenFiles.Contains(Path.Combine(fullOutputDir, "ExampleComponentAddComponentOp.h")), "UnrealComponentJob did not write the expected files");
        }

        [Test]
        public static void clean_removes_the_expected_files()
        {
            var fileSystem = GenerateMockFileSystem();
            var fileWrapperList = new List<MockFileWrapper>();

            fileSystem.GetFileInfoMock = (path) =>
            {
                var fileWrapper = new MockFileWrapper(path, Path.GetDirectoryName(path), new DateTime(1, 1, 1));
                fileWrapper.ExistsMock = () => { return true; };
                fileWrapper.DeleteMock = () => { };
                fileWrapperList.Add(fileWrapper);
                return fileWrapper;
            };

            fileSystem.GetFilesInDirectoryMock = (path, searchpattern, recursive) => { return new List<IFile>() { new MockFileWrapper(path, Path.GetDirectoryName(path), new DateTime(1, 1, 1)) }; };

            var schemaFileRaw = TestUtils.GetRawJsonDataFromResource<SchemaFileRaw>("Improbable.CodeGeneration.Resources.json.test.enum.json");

            var schemaFileProcessor = new UnrealSchemaProcessor(new List<SchemaFileRaw>() { schemaFileRaw });
            var job = new UnrealComponentJob(schemaFileProcessor.unrealComponentDetails.First(), outputDir, fileSystem);

            job.Clean();

            Assert.That(fileWrapperList.Count == 5, "clean did not scan for the expected files to be deleted");

            foreach (var fileWrapper in fileWrapperList)
            {
                Assert.That(fileWrapper.DeleteCallCount == 1, "Did not call Delete the expected number of times for a filewrapper");
                Assert.That(fileWrapper.ExistsCallCount == 1, "Did not call Exists the expected number of times for a filewrapper");
            }

            var fullOutputDir = Path.Combine("Codegen", "Test");

            Assert.That(fileWrapperList.Exists((fileWrapper) => fileWrapper.CompletePath == Path.Combine(fullOutputDir, "ExampleEnumComponentComponent.h")));
            Assert.That(fileWrapperList.Exists((fileWrapper) => fileWrapper.CompletePath == Path.Combine(fullOutputDir, "ExampleEnumComponentComponent.cpp")));
            Assert.That(fileWrapperList.Exists((fileWrapper) => fileWrapper.CompletePath == Path.Combine(fullOutputDir, "ExampleEnumComponentComponentUpdate.h")));
            Assert.That(fileWrapperList.Exists((fileWrapper) => fileWrapper.CompletePath == Path.Combine(fullOutputDir, "ExampleEnumComponentComponentUpdate.cpp")));
            Assert.That(fileWrapperList.Exists((fileWrapper) => fileWrapper.CompletePath == Path.Combine(fullOutputDir, "ExampleEnumComponentAddComponentOp.h")));
        }

        private static MockFileSystem GenerateMockFileSystem()
        {
            var mockFileSystem = new MockFileSystem();
            mockFileSystem.DirectoryExistsMock = (directory) => { return true; };
            mockFileSystem.WriteToFileMock = (path, content) => { };

            return mockFileSystem;
        }

        private static readonly string outputDir = Path.Combine("Codegen", "Test");
    }
}
