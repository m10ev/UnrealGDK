// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

// Fill out your copyright notice in the Description page of Project Settings.

//#include "SpatialSpawner.h"
//#include "Commander.h"
//#include "CoreMinimal.h"
//#include "Engine/NetDriver.h"
//#include "PlayerSpawnerComponent.h"
//#include "SpatialConstants.h"
//#include "SpatialNetConnection.h"
//#include "SpatialNetDriver.h"
//#include "SpawnPlayerResponse.h"
//#include "SpawnPlayerRequest.h"

//ASpatialSpawner::ASpatialSpawner()
//{
// 	PrimaryActorTick.bCanEverTick = false;
//
//	PlayerSpawnerComponent = CreateDefaultSubobject<UPlayerSpawnerComponent>(TEXT("PlayerSpawnerComponent"));
//}
//
//void ASpatialSpawner::PostInitializeComponents()
//{
//	Super::PostInitializeComponents();
//	UE_LOG(LogTemp, Warning, TEXT("Initializing Spatial Spawner with netmode %d"), (int)GetNetMode());
//
//	PlayerSpawnerComponent->OnSpawnPlayerCommandRequest.AddDynamic(this, &ASpatialSpawner::HandleSpawnRequest);
//}
//
//void ASpatialSpawner::BeginPlay()
//{
//	Super::BeginPlay();	
//}
//
//void ASpatialSpawner::BeginDestroy()
//{
//	if (PlayerSpawnerComponent)
//	{
//		PlayerSpawnerComponent->OnSpawnPlayerCommandRequest.RemoveDynamic(this, &ASpatialSpawner::HandleSpawnRequest);
//	}	
//	
//	Super::BeginDestroy();	
//}
//
//void ASpatialSpawner::HandleSpawnRequest(USpawnPlayerCommandResponder* Responder)
//{
//	check(GetWorld());	
//
//	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
//
//	if (NetDriver)
//	{
//		FString URLString = Responder->GetRequest()->GetUrl();
//		URLString += TEXT("?workerId=") + Responder->GetCallerWorkerId();
//		NetDriver->AcceptNewPlayer(FURL(nullptr, *URLString, TRAVEL_Absolute), false);
//	}
//	else
//	{
//		UE_LOG(LogTemp, Error, TEXT("Login failed. Spatial net driver is not setup correctly."));
//	}
//	auto Response = NewObject<USpawnPlayerResponse>()->Init({});
//	Responder->SendResponse(Response);
//}
