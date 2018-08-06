// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpatialNetDriver.h"
#include "SpatialPlayerSpawner.generated.h"

/**
 * 
 */
UCLASS()
class SPATIALGDK_API USpatialPlayerSpawner : public UObject
{
	GENERATED_BODY()
	
public:

	void Init();

	// Server
	void ReceivePlayerSpawnRequest(const CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op);

	// Client
	void SendPlayerSpawnRequest();
	void ReceivePlayerSpawnResponse(const CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op);

private:
	USpatialNetDriver* NetDriver;
	
	FTimerManager* TimerManager;
	int NumberOfAttempts;
};
