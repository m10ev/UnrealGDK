// Fill out your copyright notice in the Description page of Project Settings.

#include "SpatialPlayerSpawner.h"
#include "SocketSubsystem.h"
#include "SpatialNetConnection.h"
#include <improbable/worker.h>
#include "SpatialGDK/Generated/improbable/unreal/gdk/spawner.h"

using namespace worker;

using PlayerSpawner = improbable::unreal::PlayerSpawner;

void USpatialPlayerSpawner::Init(USpatialNetDriver* NetDriver, FTimerManager* TimerManager)
{
	TSharedPtr<View> View = NetDriver->View;

	this->NetDriver = NetDriver;
	this->TimerManager = TimerManager;

	View->OnCommandRequest<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>([this](const CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op){
		ReceivePlayerSpawnRequest(op);
	});

	View->OnCommandResponse<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>([this](const CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op){
			
	});
}

void USpatialPlayerSpawner::ReceivePlayerSpawnRequest(const CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op)
{
	FString URLString = op.Request.url();
	URLString.Append(TEXT("?workerId=")).Append(UTF8_TO_TCHAR(op.CallerWorkerId.c_str()));

	NetDriver->AcceptNewPlayer(FURL(nullptr, *URLString, TRAVEL_Absolute), false);
}

void USpatialPlayerSpawner::SendPlayerSpawnRequest()
{
	FURL DummyURL;
	PlayerSpawner::Commands::SpawnPlayer::Request Request(DummyURL);
	NetDriver->Connection->SendCommandRequest<PlayerSpawner::Commands::SpawnPlayer>(SpatialConstants::SPAWNER_ENTITY_ID, Request, 0);
	++NumberOfAttempts;
}

void USpatialPlayerSpawner::ReceivePlayerSpawnResponse(const CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op)
{
	if(op.StatusCode == worker::StatusCode::kSuccess)
	{

	}
	else if(NumberOfAttempts < SpatialConstants::MAX_NUMBER_COMMAND_ATTEMPTS)
	{
	
	}
	else
	{

	}
}
