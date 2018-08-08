// Fill out your copyright notice in the Description page of Project Settings.

#include "SpatialPlayerSpawner.h"
#include "SocketSubsystem.h"
#include "SpatialNetConnection.h"
#include "SpatialConstants.h"
#include <improbable/worker.h>
#include "TimerManager.h"

using namespace worker;

using PlayerSpawner = improbable::unreal::PlayerSpawner;

DEFINE_LOG_CATEGORY(LogSpatialGDKPlayerSpawner);

void USpatialPlayerSpawner::Init(USpatialNetDriver* NetDriver, FTimerManager* TimerManager)
{
	TSharedPtr<View> View = NetDriver->View;

	this->NetDriver = NetDriver;
	this->TimerManager = TimerManager;

	View->OnCommandRequest<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>([this](const CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op){
		ReceivePlayerSpawnRequest(op);
	});

	View->OnCommandResponse<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>([this](const CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op){
		ReceivePlayerSpawnResponse(op);
	});

	NumberOfAttempts = 0;
}

void USpatialPlayerSpawner::ReceivePlayerSpawnRequest(const CommandRequestOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op)
{
	FString URLString = UTF8_TO_TCHAR(op.Request.url().c_str());
	URLString.Append(TEXT("?workerId=")).Append(UTF8_TO_TCHAR(op.CallerWorkerId.c_str()));

	NetDriver->AcceptNewPlayer(FURL(nullptr, *URLString, TRAVEL_Absolute), false);

	PlayerSpawner::Commands::SpawnPlayer::Response Response;
	Response.set_success(true);
	NetDriver->Connection->SendCommandResponse<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>(op.RequestId, Response);
}

void USpatialPlayerSpawner::SendPlayerSpawnRequest()
{
	FURL DummyURL;
	PlayerSpawner::Commands::SpawnPlayer::Request Request;
	Request.set_url(TCHAR_TO_UTF8(*DummyURL.ToString(true)));

	NetDriver->Connection->SendCommandRequest<PlayerSpawner::Commands::SpawnPlayer>(SpatialConstants::SPAWNER_ENTITY_ID, Request, 0);
	++NumberOfAttempts;
}

void USpatialPlayerSpawner::ReceivePlayerSpawnResponse(const CommandResponseOp<improbable::unreal::PlayerSpawner::Commands::SpawnPlayer>& op)
{
	if(op.StatusCode == worker::StatusCode::kSuccess)
	{
		UE_LOG(LogSpatialGDKPlayerSpawner, Display, TEXT("Player spawned sucessfully"));
	}
	else if(NumberOfAttempts < SpatialConstants::MAX_NUMBER_COMMAND_ATTEMPTS)
	{
		UE_LOG(LogSpatialGDKPlayerSpawner, Warning, TEXT("Player spawn request failed: \"%s\""),
			*FString(op.Message.c_str()));

		FTimerHandle RetryTimer;
		FTimerDelegate TimerCallback;
		TimerCallback.BindLambda([this, RetryTimer]()
		{
			this->SendPlayerSpawnRequest();
		});

		TimerManager->SetTimer(RetryTimer, TimerCallback, SpatialConstants::GetCommandRetryWaitTimeSeconds(NumberOfAttempts), false);
	}
	else
	{
		UE_LOG(LogSpatialGDKPlayerSpawner, Fatal, TEXT("Player spawn request failed too many times. (%u attempts)"),
			SpatialConstants::MAX_NUMBER_COMMAND_ATTEMPTS)
	}
}
