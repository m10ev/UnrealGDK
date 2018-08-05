// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "improbable/worker.h"
#include "improbable/view.h"

#include "SpatialActorSpawner.generated.h"

using namespace worker;

UCLASS()
class SPATIALGDK_API USpatialActorSpawner : public UObject
{
	GENERATED_BODY()
	
public:

	void RegisterCallbacks(View view);
	
	void AddEntity(const AddEntityOp& op);
	void RemoveEntity(const RemoveEntityOp& op);
	void HitCriticalSection(const CriticalSectionOp& op);
	
	void CreateActor();
	void SpawnActor();

	void GetNativeEntityClass();
	void SetupComponentInterest();

private:
	bool inCriticalSection;

	TArray<AddEntityOp> PendingAddEntityOps;
	TArray<RemoveEntityOp> PendingRemoveEntityOps;

	UEntityRegistry* EntityRegistry;

	USpatialNetDriver* NetDriver;
};
