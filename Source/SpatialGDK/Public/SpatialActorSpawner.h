// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <improbable/standard_library.h>
#include <improbable/view.h>
#include "SpatialNetDriver.h"

#include "SpatialActorSpawner.generated.h"

using namespace worker;
using ComponentStorageBase = detail::ComponentStorageBase;

UCLASS()
class SPATIALGDK_API USpatialActorSpawner : public UObject
{
	GENERATED_BODY()
	
public:
	void Init(USpatialNetDriver* NetDriver, UEntityRegistry* EntityRegistry);

	template <typename T>
	void Accept();

	void RegisterCallbacks();
	
	void AddEntity(const AddEntityOp& op);
	void RemoveEntity(const RemoveEntityOp& op);
	void HitCriticalSection(const CriticalSectionOp& op);
	
	void CreateActor(const worker::EntityId& EntityId);
	AActor* SpawnActor(improbable::PositionData* PositionComponent, UClass* ActorClass, bool bDeferred);
	void DeleteActor(const worker::EntityId& EntityId);

	UClass* GetNativeEntityClass(improbable::MetadataData* MetadataComponent);

	bool inCriticalSection;

private:
	TArray<AddEntityOp> PendingAddEntityOps;
	TArray<RemoveEntityOp> PendingRemoveEntityOps;
	TMap<EntityId, TArray<TSharedPtr<ComponentStorageBase>>> PendingAddComponentOps;

	UEntityRegistry* EntityRegistry;

	USpatialNetDriver* NetDriver;
	TSharedPtr<Connection> Connection;
	TSharedPtr<View> View;

	template <typename Metaclass>
	typename Metaclass::Data* GetComponentDataFromView(const worker::EntityId& EntityId)
	{
		auto EntityIterator = View->Entities.find(EntityId);
		if (EntityIterator == View->Entities.end())
		{
			return nullptr;
		}
		return EntityIterator->second.Get<Metaclass>().data();
	}
};
