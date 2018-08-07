// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpatialNetDriver.h"
#include <improbable/worker.h>
#include "SpatialGDK/Generated/improbable/unreal/gdk/spawner.h"
#include "SpatialPlayerSpawner.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialGDKPlayerSpawner, Log, All);

UCLASS()
class SPATIALGDK_API USpatialPlayerSpawner : public UObject
{
	GENERATED_BODY()
	
public:

	void Init(USpatialNetDriver* NetDriver, FTimerManager* TimerManager);

	// Server
	void ReceivePlayerSpawnRequest(const worker::CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op);

	// Client
	void SendPlayerSpawnRequest();
	void ReceivePlayerSpawnResponse(const worker::CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op);

private:
	USpatialNetDriver* NetDriver;
	
	FTimerManager* TimerManager;
	int NumberOfAttempts;
};
