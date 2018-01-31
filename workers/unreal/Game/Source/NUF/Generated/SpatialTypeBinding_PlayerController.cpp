// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_PlayerController.h"
#include "SpatialOS.h"
#include "Engine.h"
#include "SpatialActorChannel.h"
#include "EntityBuilder.h"
#include "SpatialPackageMapClient.h"
#include "Utils/BunchReader.h"
#include "SpatialNetDriver.h"
#include "SpatialUpdateInterop.h"

const FRepHandlePropertyMap& USpatialTypeBinding_PlayerController::GetHandlePropertyMap()
{
	static FRepHandlePropertyMap HandleToPropertyMap;
	if (HandleToPropertyMap.Num() == 0)
	{
		UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("PlayerController"));
		HandleToPropertyMap.Add(18, FRepHandleData{nullptr, Class->FindPropertyByName("TargetViewRotation"), COND_OwnerOnly});
		HandleToPropertyMap.Add(19, FRepHandleData{nullptr, Class->FindPropertyByName("SpawnLocation"), COND_OwnerOnly});
		HandleToPropertyMap.Add(1, FRepHandleData{nullptr, Class->FindPropertyByName("bHidden"), COND_None});
		HandleToPropertyMap.Add(2, FRepHandleData{nullptr, Class->FindPropertyByName("bReplicateMovement"), COND_None});
		HandleToPropertyMap.Add(3, FRepHandleData{nullptr, Class->FindPropertyByName("bTearOff"), COND_None});
		HandleToPropertyMap.Add(4, FRepHandleData{nullptr, Class->FindPropertyByName("RemoteRole"), COND_None});
		HandleToPropertyMap.Add(5, FRepHandleData{nullptr, Class->FindPropertyByName("Owner"), COND_None});
		HandleToPropertyMap.Add(6, FRepHandleData{nullptr, Class->FindPropertyByName("ReplicatedMovement"), COND_SimulatedOrPhysics});
		HandleToPropertyMap.Add(7, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[7].Property = Cast<UStructProperty>(HandleToPropertyMap[7].Parent)->Struct->FindPropertyByName("AttachParent");
		HandleToPropertyMap.Add(8, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[8].Property = Cast<UStructProperty>(HandleToPropertyMap[8].Parent)->Struct->FindPropertyByName("LocationOffset");
		HandleToPropertyMap.Add(9, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[9].Property = Cast<UStructProperty>(HandleToPropertyMap[9].Parent)->Struct->FindPropertyByName("RelativeScale3D");
		HandleToPropertyMap.Add(10, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[10].Property = Cast<UStructProperty>(HandleToPropertyMap[10].Parent)->Struct->FindPropertyByName("RotationOffset");
		HandleToPropertyMap.Add(11, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[11].Property = Cast<UStructProperty>(HandleToPropertyMap[11].Parent)->Struct->FindPropertyByName("AttachSocket");
		HandleToPropertyMap.Add(12, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[12].Property = Cast<UStructProperty>(HandleToPropertyMap[12].Parent)->Struct->FindPropertyByName("AttachComponent");
		HandleToPropertyMap.Add(13, FRepHandleData{nullptr, Class->FindPropertyByName("Role"), COND_None});
		HandleToPropertyMap.Add(14, FRepHandleData{nullptr, Class->FindPropertyByName("bCanBeDamaged"), COND_None});
		HandleToPropertyMap.Add(15, FRepHandleData{nullptr, Class->FindPropertyByName("Instigator"), COND_None});
		HandleToPropertyMap.Add(16, FRepHandleData{nullptr, Class->FindPropertyByName("Pawn"), COND_None});
		HandleToPropertyMap.Add(17, FRepHandleData{nullptr, Class->FindPropertyByName("PlayerState"), COND_None});
	}
	return HandleToPropertyMap;
}

void USpatialTypeBinding_PlayerController::Init(USpatialUpdateInterop* InUpdateInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InUpdateInterop, InPackageMap);

	RPCToSenderMap.Emplace("OnServerStartedVisualLogger", &USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_Sender);
	RPCToSenderMap.Emplace("ClientWasKicked", &USpatialTypeBinding_PlayerController::ClientWasKicked_Sender);
	RPCToSenderMap.Emplace("ClientVoiceHandshakeComplete", &USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_Sender);
	RPCToSenderMap.Emplace("ClientUpdateLevelStreamingStatus", &USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_Sender);
	RPCToSenderMap.Emplace("ClientUnmutePlayer", &USpatialTypeBinding_PlayerController::ClientUnmutePlayer_Sender);
	RPCToSenderMap.Emplace("ClientTravelInternal", &USpatialTypeBinding_PlayerController::ClientTravelInternal_Sender);
	RPCToSenderMap.Emplace("ClientTeamMessage", &USpatialTypeBinding_PlayerController::ClientTeamMessage_Sender);
	RPCToSenderMap.Emplace("ClientStopForceFeedback", &USpatialTypeBinding_PlayerController::ClientStopForceFeedback_Sender);
	RPCToSenderMap.Emplace("ClientStopCameraShake", &USpatialTypeBinding_PlayerController::ClientStopCameraShake_Sender);
	RPCToSenderMap.Emplace("ClientStopCameraAnim", &USpatialTypeBinding_PlayerController::ClientStopCameraAnim_Sender);
	RPCToSenderMap.Emplace("ClientStartOnlineSession", &USpatialTypeBinding_PlayerController::ClientStartOnlineSession_Sender);
	RPCToSenderMap.Emplace("ClientSpawnCameraLensEffect", &USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_Sender);
	RPCToSenderMap.Emplace("ClientSetViewTarget", &USpatialTypeBinding_PlayerController::ClientSetViewTarget_Sender);
	RPCToSenderMap.Emplace("ClientSetSpectatorWaiting", &USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_Sender);
	RPCToSenderMap.Emplace("ClientSetHUD", &USpatialTypeBinding_PlayerController::ClientSetHUD_Sender);
	RPCToSenderMap.Emplace("ClientSetForceMipLevelsToBeResident", &USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_Sender);
	RPCToSenderMap.Emplace("ClientSetCinematicMode", &USpatialTypeBinding_PlayerController::ClientSetCinematicMode_Sender);
	RPCToSenderMap.Emplace("ClientSetCameraMode", &USpatialTypeBinding_PlayerController::ClientSetCameraMode_Sender);
	RPCToSenderMap.Emplace("ClientSetCameraFade", &USpatialTypeBinding_PlayerController::ClientSetCameraFade_Sender);
	RPCToSenderMap.Emplace("ClientSetBlockOnAsyncLoading", &USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_Sender);
	RPCToSenderMap.Emplace("ClientReturnToMainMenu", &USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_Sender);
	RPCToSenderMap.Emplace("ClientRetryClientRestart", &USpatialTypeBinding_PlayerController::ClientRetryClientRestart_Sender);
	RPCToSenderMap.Emplace("ClientRestart", &USpatialTypeBinding_PlayerController::ClientRestart_Sender);
	RPCToSenderMap.Emplace("ClientReset", &USpatialTypeBinding_PlayerController::ClientReset_Sender);
	RPCToSenderMap.Emplace("ClientRepObjRef", &USpatialTypeBinding_PlayerController::ClientRepObjRef_Sender);
	RPCToSenderMap.Emplace("ClientReceiveLocalizedMessage", &USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_Sender);
	RPCToSenderMap.Emplace("ClientPrestreamTextures", &USpatialTypeBinding_PlayerController::ClientPrestreamTextures_Sender);
	RPCToSenderMap.Emplace("ClientPrepareMapChange", &USpatialTypeBinding_PlayerController::ClientPrepareMapChange_Sender);
	RPCToSenderMap.Emplace("ClientPlaySoundAtLocation", &USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_Sender);
	RPCToSenderMap.Emplace("ClientPlaySound", &USpatialTypeBinding_PlayerController::ClientPlaySound_Sender);
	RPCToSenderMap.Emplace("ClientPlayForceFeedback", &USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_Sender);
	RPCToSenderMap.Emplace("ClientPlayCameraShake", &USpatialTypeBinding_PlayerController::ClientPlayCameraShake_Sender);
	RPCToSenderMap.Emplace("ClientPlayCameraAnim", &USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_Sender);
	RPCToSenderMap.Emplace("ClientMutePlayer", &USpatialTypeBinding_PlayerController::ClientMutePlayer_Sender);
	RPCToSenderMap.Emplace("ClientMessage", &USpatialTypeBinding_PlayerController::ClientMessage_Sender);
	RPCToSenderMap.Emplace("ClientIgnoreMoveInput", &USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_Sender);
	RPCToSenderMap.Emplace("ClientIgnoreLookInput", &USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_Sender);
	RPCToSenderMap.Emplace("ClientGotoState", &USpatialTypeBinding_PlayerController::ClientGotoState_Sender);
	RPCToSenderMap.Emplace("ClientGameEnded", &USpatialTypeBinding_PlayerController::ClientGameEnded_Sender);
	RPCToSenderMap.Emplace("ClientForceGarbageCollection", &USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_Sender);
	RPCToSenderMap.Emplace("ClientFlushLevelStreaming", &USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_Sender);
	RPCToSenderMap.Emplace("ClientEndOnlineSession", &USpatialTypeBinding_PlayerController::ClientEndOnlineSession_Sender);
	RPCToSenderMap.Emplace("ClientEnableNetworkVoice", &USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_Sender);
	RPCToSenderMap.Emplace("ClientCommitMapChange", &USpatialTypeBinding_PlayerController::ClientCommitMapChange_Sender);
	RPCToSenderMap.Emplace("ClientClearCameraLensEffects", &USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_Sender);
	RPCToSenderMap.Emplace("ClientCapBandwidth", &USpatialTypeBinding_PlayerController::ClientCapBandwidth_Sender);
	RPCToSenderMap.Emplace("ClientCancelPendingMapChange", &USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_Sender);
	RPCToSenderMap.Emplace("ClientAddTextureStreamingLoc", &USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_Sender);
	RPCToSenderMap.Emplace("ClientSetRotation", &USpatialTypeBinding_PlayerController::ClientSetRotation_Sender);
	RPCToSenderMap.Emplace("ClientSetLocation", &USpatialTypeBinding_PlayerController::ClientSetLocation_Sender);
	RPCToSenderMap.Emplace("ServerViewSelf", &USpatialTypeBinding_PlayerController::ServerViewSelf_Sender);
	RPCToSenderMap.Emplace("ServerViewPrevPlayer", &USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_Sender);
	RPCToSenderMap.Emplace("ServerViewNextPlayer", &USpatialTypeBinding_PlayerController::ServerViewNextPlayer_Sender);
	RPCToSenderMap.Emplace("ServerVerifyViewTarget", &USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_Sender);
	RPCToSenderMap.Emplace("ServerUpdateLevelVisibility", &USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_Sender);
	RPCToSenderMap.Emplace("ServerUpdateCamera", &USpatialTypeBinding_PlayerController::ServerUpdateCamera_Sender);
	RPCToSenderMap.Emplace("ServerUnmutePlayer", &USpatialTypeBinding_PlayerController::ServerUnmutePlayer_Sender);
	RPCToSenderMap.Emplace("ServerToggleAILogging", &USpatialTypeBinding_PlayerController::ServerToggleAILogging_Sender);
	RPCToSenderMap.Emplace("ServerShortTimeout", &USpatialTypeBinding_PlayerController::ServerShortTimeout_Sender);
	RPCToSenderMap.Emplace("ServerSetSpectatorWaiting", &USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_Sender);
	RPCToSenderMap.Emplace("ServerSetSpectatorLocation", &USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_Sender);
	RPCToSenderMap.Emplace("ServerRestartPlayer", &USpatialTypeBinding_PlayerController::ServerRestartPlayer_Sender);
	RPCToSenderMap.Emplace("ServerPause", &USpatialTypeBinding_PlayerController::ServerPause_Sender);
	RPCToSenderMap.Emplace("ServerNotifyLoadedWorld", &USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_Sender);
	RPCToSenderMap.Emplace("ServerMutePlayer", &USpatialTypeBinding_PlayerController::ServerMutePlayer_Sender);
	RPCToSenderMap.Emplace("ServerCheckClientPossessionReliable", &USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_Sender);
	RPCToSenderMap.Emplace("ServerCheckClientPossession", &USpatialTypeBinding_PlayerController::ServerCheckClientPossession_Sender);
	RPCToSenderMap.Emplace("ServerChangeName", &USpatialTypeBinding_PlayerController::ServerChangeName_Sender);
	RPCToSenderMap.Emplace("ServerCamera", &USpatialTypeBinding_PlayerController::ServerCamera_Sender);
	RPCToSenderMap.Emplace("ServerAcknowledgePossession", &USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_Sender);
}

void USpatialTypeBinding_PlayerController::BindToView()
{
	TSharedPtr<worker::View> View = UpdateInterop->GetSpatialOS()->GetView().Pin();
	SingleClientAddCallback = View->OnAddComponent<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>([this](
		const worker::AddComponentOp<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>& Op)
	{
		auto Update = improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update::FromInitialData(Op.Data);
		USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
		if (ActorChannel)
		{
			ReceiveUpdateFromSpatial_SingleClient(ActorChannel, Update);
		}
		else
		{
			PendingSingleClientData.Add(Op.EntityId, Op.Data);
		}
	});
	SingleClientUpdateCallback = View->OnComponentUpdate<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>([this](
		const worker::ComponentUpdateOp<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>& Op)
	{
		USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
		if (ActorChannel)
		{
			ReceiveUpdateFromSpatial_SingleClient(ActorChannel, Op.Update);
		}
		else
		{
			Op.Update.ApplyTo(PendingSingleClientData.FindOrAdd(Op.EntityId));
		}
	});
	MultiClientAddCallback = View->OnAddComponent<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>([this](
		const worker::AddComponentOp<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>& Op)
	{
		auto Update = improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update::FromInitialData(Op.Data);
		USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
		if (ActorChannel)
		{
			ReceiveUpdateFromSpatial_MultiClient(ActorChannel, Update);
		}
		else
		{
			PendingMultiClientData.Add(Op.EntityId, Op.Data);
		}
	});
	MultiClientUpdateCallback = View->OnComponentUpdate<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>([this](
		const worker::ComponentUpdateOp<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>& Op)
	{
		USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
		if (ActorChannel)
		{
			ReceiveUpdateFromSpatial_MultiClient(ActorChannel, Op.Update);
		}
		else
		{
			Op.Update.ApplyTo(PendingMultiClientData.FindOrAdd(Op.EntityId));
		}
	});
	using ClientRPCCommandTypes = improbable::unreal::UnrealPlayerControllerClientRPCs::Commands;
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Onserverstartedvisuallogger>(std::bind(&USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientwaskicked>(std::bind(&USpatialTypeBinding_PlayerController::ClientWasKicked_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientvoicehandshakecomplete>(std::bind(&USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientupdatelevelstreamingstatus>(std::bind(&USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientunmuteplayer>(std::bind(&USpatialTypeBinding_PlayerController::ClientUnmutePlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clienttravelinternal>(std::bind(&USpatialTypeBinding_PlayerController::ClientTravelInternal_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientteammessage>(std::bind(&USpatialTypeBinding_PlayerController::ClientTeamMessage_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientstopforcefeedback>(std::bind(&USpatialTypeBinding_PlayerController::ClientStopForceFeedback_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientstopcamerashake>(std::bind(&USpatialTypeBinding_PlayerController::ClientStopCameraShake_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientstopcameraanim>(std::bind(&USpatialTypeBinding_PlayerController::ClientStopCameraAnim_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientstartonlinesession>(std::bind(&USpatialTypeBinding_PlayerController::ClientStartOnlineSession_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientspawncameralenseffect>(std::bind(&USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetviewtarget>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetViewTarget_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetspectatorwaiting>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsethud>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetHUD_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetforcemiplevelstoberesident>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetcinematicmode>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetCinematicMode_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetcameramode>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetCameraMode_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetcamerafade>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetCameraFade_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetblockonasyncloading>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientreturntomainmenu>(std::bind(&USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientretryclientrestart>(std::bind(&USpatialTypeBinding_PlayerController::ClientRetryClientRestart_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientrestart>(std::bind(&USpatialTypeBinding_PlayerController::ClientRestart_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientreset>(std::bind(&USpatialTypeBinding_PlayerController::ClientReset_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientrepobjref>(std::bind(&USpatialTypeBinding_PlayerController::ClientRepObjRef_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientreceivelocalizedmessage>(std::bind(&USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientprestreamtextures>(std::bind(&USpatialTypeBinding_PlayerController::ClientPrestreamTextures_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientpreparemapchange>(std::bind(&USpatialTypeBinding_PlayerController::ClientPrepareMapChange_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientplaysoundatlocation>(std::bind(&USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientplaysound>(std::bind(&USpatialTypeBinding_PlayerController::ClientPlaySound_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientplayforcefeedback>(std::bind(&USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientplaycamerashake>(std::bind(&USpatialTypeBinding_PlayerController::ClientPlayCameraShake_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientplaycameraanim>(std::bind(&USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientmuteplayer>(std::bind(&USpatialTypeBinding_PlayerController::ClientMutePlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientmessage>(std::bind(&USpatialTypeBinding_PlayerController::ClientMessage_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientignoremoveinput>(std::bind(&USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientignorelookinput>(std::bind(&USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientgotostate>(std::bind(&USpatialTypeBinding_PlayerController::ClientGotoState_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientgameended>(std::bind(&USpatialTypeBinding_PlayerController::ClientGameEnded_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientforcegarbagecollection>(std::bind(&USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientflushlevelstreaming>(std::bind(&USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientendonlinesession>(std::bind(&USpatialTypeBinding_PlayerController::ClientEndOnlineSession_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientenablenetworkvoice>(std::bind(&USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcommitmapchange>(std::bind(&USpatialTypeBinding_PlayerController::ClientCommitMapChange_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientclearcameralenseffects>(std::bind(&USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcapbandwidth>(std::bind(&USpatialTypeBinding_PlayerController::ClientCapBandwidth_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcancelpendingmapchange>(std::bind(&USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientaddtexturestreamingloc>(std::bind(&USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetrotation>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetRotation_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientsetlocation>(std::bind(&USpatialTypeBinding_PlayerController::ClientSetLocation_Receiver, this, std::placeholders::_1)));
	using ServerRPCCommandTypes = improbable::unreal::UnrealPlayerControllerServerRPCs::Commands;
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverviewself>(std::bind(&USpatialTypeBinding_PlayerController::ServerViewSelf_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverviewprevplayer>(std::bind(&USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverviewnextplayer>(std::bind(&USpatialTypeBinding_PlayerController::ServerViewNextPlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serververifyviewtarget>(std::bind(&USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverupdatelevelvisibility>(std::bind(&USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverupdatecamera>(std::bind(&USpatialTypeBinding_PlayerController::ServerUpdateCamera_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverunmuteplayer>(std::bind(&USpatialTypeBinding_PlayerController::ServerUnmutePlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servertoggleailogging>(std::bind(&USpatialTypeBinding_PlayerController::ServerToggleAILogging_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servershorttimeout>(std::bind(&USpatialTypeBinding_PlayerController::ServerShortTimeout_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serversetspectatorwaiting>(std::bind(&USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serversetspectatorlocation>(std::bind(&USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverrestartplayer>(std::bind(&USpatialTypeBinding_PlayerController::ServerRestartPlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverpause>(std::bind(&USpatialTypeBinding_PlayerController::ServerPause_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servernotifyloadedworld>(std::bind(&USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servermuteplayer>(std::bind(&USpatialTypeBinding_PlayerController::ServerMutePlayer_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servercheckclientpossessionreliable>(std::bind(&USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servercheckclientpossession>(std::bind(&USpatialTypeBinding_PlayerController::ServerCheckClientPossession_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serverchangename>(std::bind(&USpatialTypeBinding_PlayerController::ServerChangeName_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Servercamera>(std::bind(&USpatialTypeBinding_PlayerController::ServerCamera_Receiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ServerRPCCommandTypes::Serveracknowledgepossession>(std::bind(&USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_Receiver, this, std::placeholders::_1)));
}

void USpatialTypeBinding_PlayerController::UnbindFromView()
{
	TSharedPtr<worker::View> View = UpdateInterop->GetSpatialOS()->GetView().Pin();
	View->Remove(SingleClientAddCallback);
	View->Remove(SingleClientUpdateCallback);
	View->Remove(MultiClientAddCallback);
	View->Remove(MultiClientUpdateCallback);
	for (auto& Callback : RPCReceiverCallbacks)
	{
		View->Remove(Callback);
	}
}

worker::ComponentId USpatialTypeBinding_PlayerController::GetReplicatedGroupComponentId(EReplicatedPropertyGroup Group) const
{
	switch (Group)
	{
	case GROUP_SingleClient:
		return improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::ComponentId;
	case GROUP_MultiClient:
		return improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::ComponentId;
	default:
		checkNoEntry();
		return 0;
	}
}

worker::Entity USpatialTypeBinding_PlayerController::CreateActorEntity(const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Setup initial data.
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Data SingleClientData;
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Data MultiClientData;
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged);
	SingleClientUpdate.ApplyTo(SingleClientData);
	MultiClientUpdate.ApplyTo(MultiClientData);

	// Create entity.
	const improbable::Coordinates SpatialPosition = USpatialOSConversionFunctionLibrary::UnrealCoordinatesToSpatialOsCoordinatesCast(Position);
	improbable::WorkerAttributeSet UnrealWorkerAttributeSet{worker::List<std::string>{"UnrealWorker"}};
	improbable::WorkerAttributeSet UnrealClientAttributeSet{worker::List<std::string>{"UnrealClient"}};
	improbable::WorkerRequirementSet UnrealWorkerWritePermission{{UnrealWorkerAttributeSet}};
	improbable::WorkerRequirementSet UnrealClientWritePermission{{UnrealClientAttributeSet}};
	improbable::WorkerRequirementSet AnyWorkerReadPermission{{UnrealClientAttributeSet, UnrealWorkerAttributeSet}};
	return improbable::unreal::FEntityBuilder::Begin()
		.AddPositionComponent(improbable::Position::Data{SpatialPosition}, UnrealWorkerWritePermission)
		.AddMetadataComponent(improbable::Metadata::Data{TCHAR_TO_UTF8(*Metadata)})
		.SetPersistence(true)
		.SetReadAcl(AnyWorkerReadPermission)
		.AddComponent<improbable::player::PlayerControlClient>(improbable::player::PlayerControlClient::Data{}, UnrealClientWritePermission)
		.AddComponent<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>(SingleClientData, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>(MultiClientData, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealPlayerControllerCompleteData>(improbable::unreal::UnrealPlayerControllerCompleteData::Data{}, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealPlayerControllerClientRPCs>(improbable::unreal::UnrealPlayerControllerClientRPCs::Data{}, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealPlayerControllerServerRPCs>(improbable::unreal::UnrealPlayerControllerServerRPCs::Data{}, UnrealClientWritePermission)
		.Build();
}

void USpatialTypeBinding_PlayerController::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const worker::EntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = UpdateInterop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData>(EntityId, SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData>(EntityId, MultiClientUpdate);
	}
}

void USpatialTypeBinding_PlayerController::SendRPCCommand(const UFunction* const Function, FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	TSharedPtr<worker::Connection> Connection = UpdateInterop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	checkf(*SenderFuncIterator, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), RPCFrame, Channel, Target);
}

void USpatialTypeBinding_PlayerController::ApplyQueuedStateToChannel(USpatialActorChannel* ActorChannel)
{
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Data* SingleClientData = PendingSingleClientData.Find(ActorChannel->GetEntityId());
	if (SingleClientData)
	{
		improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update Update;
		Update.FromInitialData(*SingleClientData);
		PendingSingleClientData.Remove(ActorChannel->GetEntityId());
		ReceiveUpdateFromSpatial_SingleClient(ActorChannel, Update);
	}
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Data* MultiClientData = PendingMultiClientData.Find(ActorChannel->GetEntityId());
	if (MultiClientData)
	{
		improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update Update;
		Update.FromInitialData(*MultiClientData);
		PendingMultiClientData.Remove(ActorChannel->GetEntityId());
		ReceiveUpdateFromSpatial_MultiClient(ActorChannel, Update);
	}
}

void USpatialTypeBinding_PlayerController::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged) const
{
	// Build up SpatialOS component updates.
	auto& PropertyMap = GetHandlePropertyMap();
	FChangelistIterator ChangelistIterator(Changes.Changed, 0);
	FRepHandleIterator HandleIterator(ChangelistIterator, Changes.Cmds, Changes.BaseHandleToCmdIndex, 0, 1, 0, Changes.Cmds.Num() - 1);
	while (HandleIterator.NextHandle())
	{
		const FRepLayoutCmd& Cmd = Changes.Cmds[HandleIterator.CmdIndex];
		const uint8* Data = Changes.SourceData + HandleIterator.ArrayOffset + Cmd.Offset;
		auto& PropertyMapData = PropertyMap[HandleIterator.Handle];
		UE_LOG(LogSpatialUpdateInterop, Log, TEXT("-> Handle: %d Property %s"), HandleIterator.Handle, *Cmd.Property->GetName());
		switch (GetGroupFromCondition(PropertyMapData.Condition))
		{
		case GROUP_SingleClient:
			ApplyUpdateToSpatial_SingleClient(Data, HandleIterator.Handle, Cmd.Property, Channel, SingleClientUpdate);
			bSingleClientUpdateChanged = true;
			break;
		case GROUP_MultiClient:
			ApplyUpdateToSpatial_MultiClient(Data, HandleIterator.Handle, Cmd.Property, Channel, MultiClientUpdate);
			bMultiClientUpdateChanged = true;
			break;
		}
	}
}

void USpatialTypeBinding_PlayerController::ApplyUpdateToSpatial_SingleClient(
	const uint8* RESTRICT Data,
	int32 Handle,
	UProperty* Property,
	USpatialActorChannel* Channel,
	improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 18: // field_targetviewrotation
		{
			FRotator Value;
			Value = *(reinterpret_cast<const FRotator*>(Data));

			OutUpdate.set_field_targetviewrotation(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 19: // field_spawnlocation
		{
			FVector Value;
			Value = *(reinterpret_cast<const FVector*>(Data));

			OutUpdate.set_field_spawnlocation(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_PlayerController::ApplyUpdateToSpatial_MultiClient(
	const uint8* RESTRICT Data,
	int32 Handle,
	UProperty* Property,
	USpatialActorChannel* Channel,
	improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			OutUpdate.set_field_bhidden(Value != 0);
			break;
		}
		case 2: // field_breplicatemovement
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			OutUpdate.set_field_breplicatemovement(Value != 0);
			break;
		}
		case 3: // field_btearoff
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			OutUpdate.set_field_btearoff(Value != 0);
			break;
		}
		case 4: // field_remoterole
		{
			TEnumAsByte<ENetRole> Value;
			Value = *(reinterpret_cast<const TEnumAsByte<ENetRole>*>(Data));

			OutUpdate.set_field_remoterole(uint32_t(Value));
			break;
		}
		case 5: // field_owner
		{
			AActor* Value;
			Value = *(reinterpret_cast<AActor* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 5);
				}
				else
				{
					OutUpdate.set_field_owner(UObjectRef);
				}
			}
			break;
		}
		case 6: // field_replicatedmovement
		{
			FRepMovement Value;
			Value = *(reinterpret_cast<const FRepMovement*>(Data));

			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				bool Success;
				Value.NetSerialize(ValueDataWriter, nullptr, Success);
				OutUpdate.set_field_replicatedmovement(std::string((char*)ValueData.GetData(), ValueData.Num()));
			}
			break;
		}
		case 7: // field_attachmentreplication_attachparent
		{
			AActor* Value;
			Value = *(reinterpret_cast<AActor* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachparent(UObjectRef);
				}
			}
			break;
		}
		case 8: // field_attachmentreplication_locationoffset
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			OutUpdate.set_field_attachmentreplication_locationoffset(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 9: // field_attachmentreplication_relativescale3d
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			OutUpdate.set_field_attachmentreplication_relativescale3d(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 10: // field_attachmentreplication_rotationoffset
		{
			FRotator Value;
			Value = *(reinterpret_cast<const FRotator*>(Data));

			OutUpdate.set_field_attachmentreplication_rotationoffset(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 11: // field_attachmentreplication_attachsocket
		{
			FName Value;
			Value = *(reinterpret_cast<const FName*>(Data));

			OutUpdate.set_field_attachmentreplication_attachsocket(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication_attachcomponent
		{
			USceneComponent* Value;
			Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachcomponent(UObjectRef);
				}
			}
			break;
		}
		case 13: // field_role
		{
			TEnumAsByte<ENetRole> Value;
			Value = *(reinterpret_cast<const TEnumAsByte<ENetRole>*>(Data));

			OutUpdate.set_field_role(uint32_t(Value));
			break;
		}
		case 14: // field_bcanbedamaged
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			OutUpdate.set_field_bcanbedamaged(Value != 0);
			break;
		}
		case 15: // field_instigator
		{
			APawn* Value;
			Value = *(reinterpret_cast<APawn* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator(UObjectRef);
				}
			}
			break;
		}
		case 16: // field_pawn
		{
			APawn* Value;
			Value = *(reinterpret_cast<APawn* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 16);
				}
				else
				{
					OutUpdate.set_field_pawn(UObjectRef);
				}
			}
			break;
		}
		case 17: // field_playerstate
		{
			APlayerState* Value;
			Value = *(reinterpret_cast<APlayerState* const*>(Data));

			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (UObjectRef.entity() == 0)
				{
					PackageMap->AddPendingObjRef(Value, Channel, 17);
				}
				else
				{
					OutUpdate.set_field_playerstate(UObjectRef);
				}
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_PlayerController::ReceiveUpdateFromSpatial_SingleClient(
	USpatialActorChannel* ActorChannel,
	const improbable::unreal::UnrealPlayerControllerSingleClientReplicatedData::Update& Update) const
{
	FNetBitWriter OutputWriter(nullptr, 0);
	auto& HandleToPropertyMap = GetHandlePropertyMap();
	ConditionMapFilter ConditionMap(ActorChannel);
	if (!Update.field_targetviewrotation().empty())
	{
		// field_targetviewrotation
		uint32 Handle = 18;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRotator Value;

			{
				auto& Rotator = *(Update.field_targetviewrotation().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_spawnlocation().empty())
	{
		// field_spawnlocation
		uint32 Handle = 19;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector Value;

			{
				auto& Vector = *(Update.field_spawnlocation().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	UpdateInterop->ReceiveSpatialUpdate(ActorChannel, OutputWriter);
}

void USpatialTypeBinding_PlayerController::ReceiveUpdateFromSpatial_MultiClient(
	USpatialActorChannel* ActorChannel,
	const improbable::unreal::UnrealPlayerControllerMultiClientReplicatedData::Update& Update) const
{
	FNetBitWriter OutputWriter(nullptr, 0);
	auto& HandleToPropertyMap = GetHandlePropertyMap();
	ConditionMapFilter ConditionMap(ActorChannel);
	if (!Update.field_bhidden().empty())
	{
		// field_bhidden
		uint32 Handle = 1;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Update.field_bhidden().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_breplicatemovement().empty())
	{
		// field_breplicatemovement
		uint32 Handle = 2;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Update.field_breplicatemovement().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_btearoff().empty())
	{
		// field_btearoff
		uint32 Handle = 3;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Update.field_btearoff().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_remoterole().empty())
	{
		// field_remoterole
		uint32 Handle = 4;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			TEnumAsByte<ENetRole> Value;

			Value = TEnumAsByte<ENetRole>(uint8(*(Update.field_remoterole().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_owner().empty())
	{
		// field_owner
		uint32 Handle = 5;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			AActor* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_owner().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<AActor*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_replicatedmovement().empty())
	{
		// field_replicatedmovement
		uint32 Handle = 6;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRepMovement Value;

			{
				auto& ValueDataStr = *(Update.field_replicatedmovement().data());
				TArray<uint8> ValueData;
				ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				bool bSuccess;
				Value.NetSerialize(ValueDataReader, nullptr, bSuccess);
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_attachparent().empty())
	{
		// field_attachmentreplication_attachparent
		uint32 Handle = 7;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			AActor* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_attachmentreplication_attachparent().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<AActor*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_locationoffset().empty())
	{
		// field_attachmentreplication_locationoffset
		uint32 Handle = 8;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Update.field_attachmentreplication_locationoffset().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_relativescale3d().empty())
	{
		// field_attachmentreplication_relativescale3d
		uint32 Handle = 9;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Update.field_attachmentreplication_relativescale3d().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_rotationoffset().empty())
	{
		// field_attachmentreplication_rotationoffset
		uint32 Handle = 10;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRotator Value;

			{
				auto& Rotator = *(Update.field_attachmentreplication_rotationoffset().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_attachsocket().empty())
	{
		// field_attachmentreplication_attachsocket
		uint32 Handle = 11;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FName Value;

			Value = FName((*(Update.field_attachmentreplication_attachsocket().data())).data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_attachmentreplication_attachcomponent().empty())
	{
		// field_attachmentreplication_attachcomponent
		uint32 Handle = 12;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			USceneComponent* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_attachmentreplication_attachcomponent().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<USceneComponent*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_role().empty())
	{
		// field_role
		uint32 Handle = 13;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			TEnumAsByte<ENetRole> Value;

			Value = TEnumAsByte<ENetRole>(uint8(*(Update.field_role().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_bcanbedamaged().empty())
	{
		// field_bcanbedamaged
		uint32 Handle = 14;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Update.field_bcanbedamaged().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_instigator().empty())
	{
		// field_instigator
		uint32 Handle = 15;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			APawn* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_instigator().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<APawn*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_pawn().empty())
	{
		// field_pawn
		uint32 Handle = 16;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			APawn* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_pawn().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<APawn*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Update.field_playerstate().empty())
	{
		// field_playerstate
		uint32 Handle = 17;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			APlayerState* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Update.field_playerstate().data());
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
				if (NetGUID.IsValid())
				{
					Value = static_cast<APlayerState*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
				}
				else
				{
					Value = nullptr;
				}
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogSpatialUpdateInterop, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	UpdateInterop->ReceiveSpatialUpdate(ActorChannel, OutputWriter);
}

void USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bIsLogging);

	improbable::unreal::UnrealOnServerStartedVisualLoggerRequest Request;
	Request.set_field_bislogging(bIsLogging != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientWasKicked_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UTextProperty, KickReason);

	improbable::unreal::UnrealClientWasKickedRequest Request;
	// UNSUPPORTED

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientwaskicked>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientVoiceHandshakeCompleteRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, PackageName);
	P_GET_UBOOL(bNewShouldBeLoaded);
	P_GET_UBOOL(bNewShouldBeVisible);
	P_GET_UBOOL(bNewShouldBlockOnLoad);
	P_GET_PROPERTY(UIntProperty, LODIndex);

	improbable::unreal::UnrealClientUpdateLevelStreamingStatusRequest Request;
	Request.set_field_packagename(TCHAR_TO_UTF8(*PackageName.ToString()));
	Request.set_field_bnewshouldbeloaded(bNewShouldBeLoaded != 0);
	Request.set_field_bnewshouldbevisible(bNewShouldBeVisible != 0);
	Request.set_field_bnewshouldblockonload(bNewShouldBlockOnLoad != 0);
	Request.set_field_lodindex(LODIndex);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientUnmutePlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FUniqueNetIdRepl, PlayerId)

	improbable::unreal::UnrealClientUnmutePlayerRequest Request;
	{
		TArray<uint8> ValueData;
		FMemoryWriter ValueDataWriter(ValueData);
		bool Success;
		PlayerId.NetSerialize(ValueDataWriter, nullptr, Success);
		Request.set_field_playerid(std::string((char*)ValueData.GetData(), ValueData.Num()));
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientunmuteplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientTravelInternal_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UStrProperty, URL);
	P_GET_PROPERTY(UByteProperty, TravelType);
	P_GET_UBOOL(bSeamless);
	P_GET_STRUCT(FGuid, MapPackageGuid)

	improbable::unreal::UnrealClientTravelInternalRequest Request;
	Request.set_field_url(TCHAR_TO_UTF8(*URL));
	Request.set_field_traveltype(uint32_t(TravelType));
	Request.set_field_bseamless(bSeamless != 0);
	Request.set_field_mappackageguid_a(MapPackageGuid.A);
	Request.set_field_mappackageguid_b(MapPackageGuid.B);
	Request.set_field_mappackageguid_c(MapPackageGuid.C);
	Request.set_field_mappackageguid_d(MapPackageGuid.D);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clienttravelinternal>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientTeamMessage_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(APlayerState, SenderPlayerState);
	P_GET_PROPERTY(UStrProperty, S);
	P_GET_PROPERTY(UNameProperty, Type);
	P_GET_PROPERTY(UFloatProperty, MsgLifeTime);

	improbable::unreal::UnrealClientTeamMessageRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(SenderPlayerState);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(SenderPlayerState, Channel, -1);
		}
		else
		{
			Request.set_field_senderplayerstate(UObjectRef);
		}
	}
	Request.set_field_s(TCHAR_TO_UTF8(*S));
	Request.set_field_type(TCHAR_TO_UTF8(*Type.ToString()));
	Request.set_field_msglifetime(MsgLifeTime);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientteammessage>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientStopForceFeedback_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UForceFeedbackEffect, ForceFeedbackEffect);
	P_GET_PROPERTY(UNameProperty, Tag);

	improbable::unreal::UnrealClientStopForceFeedbackRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(ForceFeedbackEffect);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(ForceFeedbackEffect, Channel, -1);
		}
		else
		{
			Request.set_field_forcefeedbackeffect(UObjectRef);
		}
	}
	Request.set_field_tag(TCHAR_TO_UTF8(*Tag.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopforcefeedback>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraShake_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UClass, Shake);
	P_GET_UBOOL(bImmediately);

	improbable::unreal::UnrealClientStopCameraShakeRequest Request;
	// UNSUPPORTED UClass
	Request.set_field_bimmediately(bImmediately != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcamerashake>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraAnim_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UCameraAnim, AnimToStop);

	improbable::unreal::UnrealClientStopCameraAnimRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(AnimToStop);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(AnimToStop, Channel, -1);
		}
		else
		{
			Request.set_field_animtostop(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcameraanim>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientStartOnlineSession_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientStartOnlineSessionRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstartonlinesession>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UClass, LensEffectEmitterClass);

	improbable::unreal::UnrealClientSpawnCameraLensEffectRequest Request;
	// UNSUPPORTED UClass

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetViewTarget_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(AActor, A);
	P_GET_STRUCT(FViewTargetTransitionParams, TransitionParams)

	improbable::unreal::UnrealClientSetViewTargetRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(A);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(A, Channel, -1);
		}
		else
		{
			Request.set_field_a(UObjectRef);
		}
	}
	Request.set_field_transitionparams_blendtime(TransitionParams.BlendTime);
	Request.set_field_transitionparams_blendfunction(uint32_t(TransitionParams.BlendFunction));
	Request.set_field_transitionparams_blendexp(TransitionParams.BlendExp);
	Request.set_field_transitionparams_blockoutgoing(TransitionParams.bLockOutgoing != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetviewtarget>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bWaiting);

	improbable::unreal::UnrealClientSetSpectatorWaitingRequest Request;
	Request.set_field_bwaiting(bWaiting != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetHUD_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UClass, NewHUDClass);

	improbable::unreal::UnrealClientSetHUDRequest Request;
	// UNSUPPORTED UClass

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsethud>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UMaterialInterface, Material);
	P_GET_PROPERTY(UFloatProperty, ForceDuration);
	P_GET_PROPERTY(UIntProperty, CinematicTextureGroups);

	improbable::unreal::UnrealClientSetForceMipLevelsToBeResidentRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Material);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(Material, Channel, -1);
		}
		else
		{
			Request.set_field_material(UObjectRef);
		}
	}
	Request.set_field_forceduration(ForceDuration);
	Request.set_field_cinematictexturegroups(CinematicTextureGroups);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetCinematicMode_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bInCinematicMode);
	P_GET_UBOOL(bAffectsMovement);
	P_GET_UBOOL(bAffectsTurning);
	P_GET_UBOOL(bAffectsHUD);

	improbable::unreal::UnrealClientSetCinematicModeRequest Request;
	Request.set_field_bincinematicmode(bInCinematicMode != 0);
	Request.set_field_baffectsmovement(bAffectsMovement != 0);
	Request.set_field_baffectsturning(bAffectsTurning != 0);
	Request.set_field_baffectshud(bAffectsHUD != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcinematicmode>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraMode_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, NewCamMode);

	improbable::unreal::UnrealClientSetCameraModeRequest Request;
	Request.set_field_newcammode(TCHAR_TO_UTF8(*NewCamMode.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcameramode>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraFade_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bEnableFading);
	P_GET_STRUCT(FColor, FadeColor)
	P_GET_STRUCT(FVector2D, FadeAlpha)
	P_GET_PROPERTY(UFloatProperty, FadeTime);
	P_GET_UBOOL(bFadeAudio);

	improbable::unreal::UnrealClientSetCameraFadeRequest Request;
	Request.set_field_benablefading(bEnableFading != 0);
	Request.set_field_fadecolor_b(uint32_t(FadeColor.B));
	Request.set_field_fadecolor_g(uint32_t(FadeColor.G));
	Request.set_field_fadecolor_r(uint32_t(FadeColor.R));
	Request.set_field_fadecolor_a(uint32_t(FadeColor.A));
	Request.set_field_fadealpha_x(FadeAlpha.X);
	Request.set_field_fadealpha_y(FadeAlpha.Y);
	Request.set_field_fadetime(FadeTime);
	Request.set_field_bfadeaudio(bFadeAudio != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcamerafade>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientSetBlockOnAsyncLoadingRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UStrProperty, ReturnReason);

	improbable::unreal::UnrealClientReturnToMainMenuRequest Request;
	Request.set_field_returnreason(TCHAR_TO_UTF8(*ReturnReason));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenu>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientRetryClientRestart_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(APawn, NewPawn);

	improbable::unreal::UnrealClientRetryClientRestartRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(NewPawn);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(NewPawn, Channel, -1);
		}
		else
		{
			Request.set_field_newpawn(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientretryclientrestart>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientRestart_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(APawn, NewPawn);

	improbable::unreal::UnrealClientRestartRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(NewPawn);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(NewPawn, Channel, -1);
		}
		else
		{
			Request.set_field_newpawn(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrestart>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientReset_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientResetRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreset>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientRepObjRef_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UObject, Object);

	improbable::unreal::UnrealClientRepObjRefRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Object);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(Object, Channel, -1);
		}
		else
		{
			Request.set_field_object(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrepobjref>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UClass, Message);
	P_GET_PROPERTY(UIntProperty, Switch);
	P_GET_OBJECT(APlayerState, RelatedPlayerState_1);
	P_GET_OBJECT(APlayerState, RelatedPlayerState_2);
	P_GET_OBJECT(UObject, OptionalObject);

	improbable::unreal::UnrealClientReceiveLocalizedMessageRequest Request;
	// UNSUPPORTED UClass
	Request.set_field_switch(Switch);
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(RelatedPlayerState_1);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(RelatedPlayerState_1, Channel, -1);
		}
		else
		{
			Request.set_field_relatedplayerstate_1(UObjectRef);
		}
	}
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(RelatedPlayerState_2);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(RelatedPlayerState_2, Channel, -1);
		}
		else
		{
			Request.set_field_relatedplayerstate_2(UObjectRef);
		}
	}
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(OptionalObject);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(OptionalObject, Channel, -1);
		}
		else
		{
			Request.set_field_optionalobject(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPrestreamTextures_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(AActor, ForcedActor);
	P_GET_PROPERTY(UFloatProperty, ForceDuration);
	P_GET_UBOOL(bEnableStreaming);
	P_GET_PROPERTY(UIntProperty, CinematicTextureGroups);

	improbable::unreal::UnrealClientPrestreamTexturesRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(ForcedActor);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(ForcedActor, Channel, -1);
		}
		else
		{
			Request.set_field_forcedactor(UObjectRef);
		}
	}
	Request.set_field_forceduration(ForceDuration);
	Request.set_field_benablestreaming(bEnableStreaming != 0);
	Request.set_field_cinematictexturegroups(CinematicTextureGroups);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientprestreamtextures>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPrepareMapChange_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, LevelName);
	P_GET_UBOOL(bFirst);
	P_GET_UBOOL(bLast);

	improbable::unreal::UnrealClientPrepareMapChangeRequest Request;
	Request.set_field_levelname(TCHAR_TO_UTF8(*LevelName.ToString()));
	Request.set_field_bfirst(bFirst != 0);
	Request.set_field_blast(bLast != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientpreparemapchange>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(USoundBase, Sound);
	P_GET_STRUCT(FVector, Location)
	P_GET_PROPERTY(UFloatProperty, VolumeMultiplier);
	P_GET_PROPERTY(UFloatProperty, PitchMultiplier);

	improbable::unreal::UnrealClientPlaySoundAtLocationRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Sound);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(Sound, Channel, -1);
		}
		else
		{
			Request.set_field_sound(UObjectRef);
		}
	}
	Request.set_field_location(improbable::Vector3f(Location.X, Location.Y, Location.Z));
	Request.set_field_volumemultiplier(VolumeMultiplier);
	Request.set_field_pitchmultiplier(PitchMultiplier);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPlaySound_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(USoundBase, Sound);
	P_GET_PROPERTY(UFloatProperty, VolumeMultiplier);
	P_GET_PROPERTY(UFloatProperty, PitchMultiplier);

	improbable::unreal::UnrealClientPlaySoundRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Sound);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(Sound, Channel, -1);
		}
		else
		{
			Request.set_field_sound(UObjectRef);
		}
	}
	Request.set_field_volumemultiplier(VolumeMultiplier);
	Request.set_field_pitchmultiplier(PitchMultiplier);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysound>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UForceFeedbackEffect, ForceFeedbackEffect);
	P_GET_UBOOL(bLooping);
	P_GET_PROPERTY(UNameProperty, Tag);

	improbable::unreal::UnrealClientPlayForceFeedbackRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(ForceFeedbackEffect);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(ForceFeedbackEffect, Channel, -1);
		}
		else
		{
			Request.set_field_forcefeedbackeffect(UObjectRef);
		}
	}
	Request.set_field_blooping(bLooping != 0);
	Request.set_field_tag(TCHAR_TO_UTF8(*Tag.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplayforcefeedback>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraShake_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UClass, Shake);
	P_GET_PROPERTY(UFloatProperty, Scale);
	P_GET_PROPERTY(UByteProperty, PlaySpace);
	P_GET_STRUCT(FRotator, UserPlaySpaceRot)

	improbable::unreal::UnrealClientPlayCameraShakeRequest Request;
	// UNSUPPORTED UClass
	Request.set_field_scale(Scale);
	Request.set_field_playspace(uint32_t(PlaySpace));
	Request.set_field_userplayspacerot(improbable::unreal::UnrealFRotator(UserPlaySpaceRot.Yaw, UserPlaySpaceRot.Pitch, UserPlaySpaceRot.Roll));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycamerashake>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(UCameraAnim, AnimToPlay);
	P_GET_PROPERTY(UFloatProperty, Scale);
	P_GET_PROPERTY(UFloatProperty, Rate);
	P_GET_PROPERTY(UFloatProperty, BlendInTime);
	P_GET_PROPERTY(UFloatProperty, BlendOutTime);
	P_GET_UBOOL(bLoop);
	P_GET_UBOOL(bRandomStartTime);
	P_GET_PROPERTY(UByteProperty, Space);
	P_GET_STRUCT(FRotator, CustomPlaySpace)

	improbable::unreal::UnrealClientPlayCameraAnimRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(AnimToPlay);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(AnimToPlay, Channel, -1);
		}
		else
		{
			Request.set_field_animtoplay(UObjectRef);
		}
	}
	Request.set_field_scale(Scale);
	Request.set_field_rate(Rate);
	Request.set_field_blendintime(BlendInTime);
	Request.set_field_blendouttime(BlendOutTime);
	Request.set_field_bloop(bLoop != 0);
	Request.set_field_brandomstarttime(bRandomStartTime != 0);
	Request.set_field_space(uint32_t(Space));
	Request.set_field_customplayspace(improbable::unreal::UnrealFRotator(CustomPlaySpace.Yaw, CustomPlaySpace.Pitch, CustomPlaySpace.Roll));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycameraanim>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientMutePlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FUniqueNetIdRepl, PlayerId)

	improbable::unreal::UnrealClientMutePlayerRequest Request;
	{
		TArray<uint8> ValueData;
		FMemoryWriter ValueDataWriter(ValueData);
		bool Success;
		PlayerId.NetSerialize(ValueDataWriter, nullptr, Success);
		Request.set_field_playerid(std::string((char*)ValueData.GetData(), ValueData.Num()));
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmuteplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientMessage_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UStrProperty, S);
	P_GET_PROPERTY(UNameProperty, Type);
	P_GET_PROPERTY(UFloatProperty, MsgLifeTime);

	improbable::unreal::UnrealClientMessageRequest Request;
	Request.set_field_s(TCHAR_TO_UTF8(*S));
	Request.set_field_type(TCHAR_TO_UTF8(*Type.ToString()));
	Request.set_field_msglifetime(MsgLifeTime);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmessage>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bIgnore);

	improbable::unreal::UnrealClientIgnoreMoveInputRequest Request;
	Request.set_field_bignore(bIgnore != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignoremoveinput>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bIgnore);

	improbable::unreal::UnrealClientIgnoreLookInputRequest Request;
	Request.set_field_bignore(bIgnore != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignorelookinput>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientGotoState_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, NewState);

	improbable::unreal::UnrealClientGotoStateRequest Request;
	Request.set_field_newstate(TCHAR_TO_UTF8(*NewState.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgotostate>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientGameEnded_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(AActor, EndGameFocus);
	P_GET_UBOOL(bIsWinner);

	improbable::unreal::UnrealClientGameEndedRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(EndGameFocus);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(EndGameFocus, Channel, -1);
		}
		else
		{
			Request.set_field_endgamefocus(UObjectRef);
		}
	}
	Request.set_field_biswinner(bIsWinner != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgameended>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientForceGarbageCollectionRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientFlushLevelStreamingRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientEndOnlineSession_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientEndOnlineSessionRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientendonlinesession>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bEnable);

	improbable::unreal::UnrealClientEnableNetworkVoiceRequest Request;
	Request.set_field_benable(bEnable != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientCommitMapChange_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientCommitMapChangeRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcommitmapchange>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientClearCameraLensEffectsRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientCapBandwidth_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UIntProperty, Cap);

	improbable::unreal::UnrealClientCapBandwidthRequest Request;
	Request.set_field_cap(Cap);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcapbandwidth>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealClientCancelPendingMapChangeRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FVector, InLoc)
	P_GET_PROPERTY(UFloatProperty, Duration);
	P_GET_UBOOL(bOverrideLocation);

	improbable::unreal::UnrealClientAddTextureStreamingLocRequest Request;
	Request.set_field_inloc(improbable::Vector3f(InLoc.X, InLoc.Y, InLoc.Z));
	Request.set_field_duration(Duration);
	Request.set_field_boverridelocation(bOverrideLocation != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetRotation_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FRotator, NewRotation)
	P_GET_UBOOL(bResetCamera);

	improbable::unreal::UnrealClientSetRotationRequest Request;
	Request.set_field_newrotation(improbable::unreal::UnrealFRotator(NewRotation.Yaw, NewRotation.Pitch, NewRotation.Roll));
	Request.set_field_bresetcamera(bResetCamera != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetrotation>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ClientSetLocation_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FVector, NewLocation)
	P_GET_STRUCT(FRotator, NewRotation)

	improbable::unreal::UnrealClientSetLocationRequest Request;
	Request.set_field_newlocation(improbable::Vector3f(NewLocation.X, NewLocation.Y, NewLocation.Z));
	Request.set_field_newrotation(improbable::unreal::UnrealFRotator(NewRotation.Yaw, NewRotation.Pitch, NewRotation.Roll));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetlocation>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerViewSelf_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FViewTargetTransitionParams, TransitionParams)

	improbable::unreal::UnrealServerViewSelfRequest Request;
	Request.set_field_transitionparams_blendtime(TransitionParams.BlendTime);
	Request.set_field_transitionparams_blendfunction(uint32_t(TransitionParams.BlendFunction));
	Request.set_field_transitionparams_blendexp(TransitionParams.BlendExp);
	Request.set_field_transitionparams_blockoutgoing(TransitionParams.bLockOutgoing != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewself>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerViewPrevPlayerRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewprevplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerViewNextPlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerViewNextPlayerRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewnextplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerVerifyViewTargetRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serververifyviewtarget>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, PackageName);
	P_GET_UBOOL(bIsVisible);

	improbable::unreal::UnrealServerUpdateLevelVisibilityRequest Request;
	Request.set_field_packagename(TCHAR_TO_UTF8(*PackageName.ToString()));
	Request.set_field_bisvisible(bIsVisible != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerUpdateCamera_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FVector_NetQuantize, CamLoc)
	P_GET_PROPERTY(UIntProperty, CamPitchAndYaw);

	improbable::unreal::UnrealServerUpdateCameraRequest Request;
	Request.set_field_camloc(improbable::Vector3f(CamLoc.X, CamLoc.Y, CamLoc.Z));
	Request.set_field_campitchandyaw(CamPitchAndYaw);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatecamera>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerUnmutePlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FUniqueNetIdRepl, PlayerId)

	improbable::unreal::UnrealServerUnmutePlayerRequest Request;
	{
		TArray<uint8> ValueData;
		FMemoryWriter ValueDataWriter(ValueData);
		bool Success;
		PlayerId.NetSerialize(ValueDataWriter, nullptr, Success);
		Request.set_field_playerid(std::string((char*)ValueData.GetData(), ValueData.Num()));
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverunmuteplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerToggleAILogging_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerToggleAILoggingRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servertoggleailogging>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerShortTimeout_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerShortTimeoutRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servershorttimeout>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_UBOOL(bWaiting);

	improbable::unreal::UnrealServerSetSpectatorWaitingRequest Request;
	Request.set_field_bwaiting(bWaiting != 0);

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FVector, NewLoc)
	P_GET_STRUCT(FRotator, NewRot)

	improbable::unreal::UnrealServerSetSpectatorLocationRequest Request;
	Request.set_field_newloc(improbable::Vector3f(NewLoc.X, NewLoc.Y, NewLoc.Z));
	Request.set_field_newrot(improbable::unreal::UnrealFRotator(NewRot.Yaw, NewRot.Pitch, NewRot.Roll));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorlocation>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerRestartPlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerRestartPlayerRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverrestartplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerPause_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerPauseRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverpause>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, WorldPackageName);

	improbable::unreal::UnrealServerNotifyLoadedWorldRequest Request;
	Request.set_field_worldpackagename(TCHAR_TO_UTF8(*WorldPackageName.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servernotifyloadedworld>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerMutePlayer_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_STRUCT(FUniqueNetIdRepl, PlayerId)

	improbable::unreal::UnrealServerMutePlayerRequest Request;
	{
		TArray<uint8> ValueData;
		FMemoryWriter ValueDataWriter(ValueData);
		bool Success;
		PlayerId.NetSerialize(ValueDataWriter, nullptr, Success);
		Request.set_field_playerid(std::string((char*)ValueData.GetData(), ValueData.Num()));
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servermuteplayer>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerCheckClientPossessionReliableRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossession_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	improbable::unreal::UnrealServerCheckClientPossessionRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossession>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerChangeName_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UStrProperty, S);

	improbable::unreal::UnrealServerChangeNameRequest Request;
	Request.set_field_s(TCHAR_TO_UTF8(*S));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverchangename>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerCamera_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_PROPERTY(UNameProperty, NewMode);

	improbable::unreal::UnrealServerCameraRequest Request;
	Request.set_field_newmode(TCHAR_TO_UTF8(*NewMode.ToString()));

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercamera>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_Sender(worker::Connection* const Connection, struct FFrame* const RPCFrame, USpatialActorChannel* Channel, const worker::EntityId& Target)
{
	FFrame& Stack = *RPCFrame;
	P_GET_OBJECT(APawn, P);

	improbable::unreal::UnrealServerAcknowledgePossessionRequest Request;
	{
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(P);
		improbable::unreal::UnrealObjectRef UObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
		if (UObjectRef.entity() == 0)
		{
			PackageMap->AddPendingObjRef(P, Channel, -1);
		}
		else
		{
			Request.set_field_p(UObjectRef);
		}
	}

	Connection->SendCommandRequest<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serveracknowledgepossession>(Target, Request, 0);
}

void USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("OnServerStartedVisualLogger_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("OnServerStartedVisualLogger_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bIsLogging
	bool bIsLogging;
	bIsLogging = Op.Request.field_bislogging();

	// Call implementation and send command response.
	TargetObject->OnServerStartedVisualLogger_Implementation(bIsLogging);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>(Op);
}

void USpatialTypeBinding_PlayerController::ClientWasKicked_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientwaskicked>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientWasKicked_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientWasKicked_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract KickReason
	FText KickReason;
	// UNSUPPORTED

	// Call implementation and send command response.
	TargetObject->ClientWasKicked_Implementation(KickReason);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientwaskicked>(Op);
}

void USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientVoiceHandshakeComplete_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientVoiceHandshakeComplete_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientVoiceHandshakeComplete_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>(Op);
}

void USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientUpdateLevelStreamingStatus_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientUpdateLevelStreamingStatus_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PackageName
	FName PackageName;
	PackageName = FName((Op.Request.field_packagename()).data());

	// Extract bNewShouldBeLoaded
	bool bNewShouldBeLoaded;
	bNewShouldBeLoaded = Op.Request.field_bnewshouldbeloaded();

	// Extract bNewShouldBeVisible
	bool bNewShouldBeVisible;
	bNewShouldBeVisible = Op.Request.field_bnewshouldbevisible();

	// Extract bNewShouldBlockOnLoad
	bool bNewShouldBlockOnLoad;
	bNewShouldBlockOnLoad = Op.Request.field_bnewshouldblockonload();

	// Extract LODIndex
	int32 LODIndex;
	LODIndex = Op.Request.field_lodindex();

	// Call implementation and send command response.
	TargetObject->ClientUpdateLevelStreamingStatus_Implementation(PackageName, bNewShouldBeLoaded, bNewShouldBeVisible, bNewShouldBlockOnLoad, LODIndex);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>(Op);
}

void USpatialTypeBinding_PlayerController::ClientUnmutePlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientunmuteplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientUnmutePlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientUnmutePlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PlayerId
	FUniqueNetIdRepl PlayerId;
	{
		auto& ValueDataStr = Op.Request.field_playerid();
		TArray<uint8> ValueData;
		ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
		FMemoryReader ValueDataReader(ValueData);
		bool bSuccess;
		PlayerId.NetSerialize(ValueDataReader, nullptr, bSuccess);
	}

	// Call implementation and send command response.
	TargetObject->ClientUnmutePlayer_Implementation(PlayerId);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientunmuteplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ClientTravelInternal_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clienttravelinternal>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientTravelInternal_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientTravelInternal_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract URL
	FString URL;
	URL = FString(UTF8_TO_TCHAR(Op.Request.field_url().c_str()));

	// Extract TravelType
	TEnumAsByte<ETravelType> TravelType;
	TravelType = TEnumAsByte<ETravelType>(uint8(Op.Request.field_traveltype()));

	// Extract bSeamless
	bool bSeamless;
	bSeamless = Op.Request.field_bseamless();

	// Extract MapPackageGuid
	FGuid MapPackageGuid;
	MapPackageGuid.A = Op.Request.field_mappackageguid_a();
	MapPackageGuid.B = Op.Request.field_mappackageguid_b();
	MapPackageGuid.C = Op.Request.field_mappackageguid_c();
	MapPackageGuid.D = Op.Request.field_mappackageguid_d();

	// Call implementation and send command response.
	TargetObject->ClientTravelInternal_Implementation(URL, TravelType, bSeamless, MapPackageGuid);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clienttravelinternal>(Op);
}

void USpatialTypeBinding_PlayerController::ClientTeamMessage_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientteammessage>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientTeamMessage_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientTeamMessage_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract SenderPlayerState
	APlayerState* SenderPlayerState;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_senderplayerstate();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			SenderPlayerState = static_cast<APlayerState*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			SenderPlayerState = nullptr;
		}
	}

	// Extract S
	FString S;
	S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));

	// Extract Type
	FName Type;
	Type = FName((Op.Request.field_type()).data());

	// Extract MsgLifeTime
	float MsgLifeTime;
	MsgLifeTime = Op.Request.field_msglifetime();

	// Call implementation and send command response.
	TargetObject->ClientTeamMessage_Implementation(SenderPlayerState, S, Type, MsgLifeTime);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientteammessage>(Op);
}

void USpatialTypeBinding_PlayerController::ClientStopForceFeedback_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopforcefeedback>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientStopForceFeedback_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientStopForceFeedback_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract ForceFeedbackEffect
	UForceFeedbackEffect* ForceFeedbackEffect;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_forcefeedbackeffect();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			ForceFeedbackEffect = static_cast<UForceFeedbackEffect*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			ForceFeedbackEffect = nullptr;
		}
	}

	// Extract Tag
	FName Tag;
	Tag = FName((Op.Request.field_tag()).data());

	// Call implementation and send command response.
	TargetObject->ClientStopForceFeedback_Implementation(ForceFeedbackEffect, Tag);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopforcefeedback>(Op);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraShake_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcamerashake>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientStopCameraShake_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientStopCameraShake_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Shake
	TSubclassOf<UCameraShake>  Shake;
	// UNSUPPORTED UClass

	// Extract bImmediately
	bool bImmediately;
	bImmediately = Op.Request.field_bimmediately();

	// Call implementation and send command response.
	TargetObject->ClientStopCameraShake_Implementation(Shake, bImmediately);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcamerashake>(Op);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraAnim_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcameraanim>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientStopCameraAnim_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientStopCameraAnim_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract AnimToStop
	UCameraAnim* AnimToStop;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_animtostop();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			AnimToStop = static_cast<UCameraAnim*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			AnimToStop = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ClientStopCameraAnim_Implementation(AnimToStop);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstopcameraanim>(Op);
}

void USpatialTypeBinding_PlayerController::ClientStartOnlineSession_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstartonlinesession>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientStartOnlineSession_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientStartOnlineSession_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientStartOnlineSession_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientstartonlinesession>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSpawnCameraLensEffect_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSpawnCameraLensEffect_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract LensEffectEmitterClass
	TSubclassOf<AEmitterCameraLensEffectBase>  LensEffectEmitterClass;
	// UNSUPPORTED UClass

	// Call implementation and send command response.
	TargetObject->ClientSpawnCameraLensEffect_Implementation(LensEffectEmitterClass);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetViewTarget_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetviewtarget>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetViewTarget_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetViewTarget_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract A
	AActor* A;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_a();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			A = static_cast<AActor*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			A = nullptr;
		}
	}

	// Extract TransitionParams
	FViewTargetTransitionParams TransitionParams;
	TransitionParams.BlendTime = Op.Request.field_transitionparams_blendtime();
	TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(Op.Request.field_transitionparams_blendfunction()));
	TransitionParams.BlendExp = Op.Request.field_transitionparams_blendexp();
	TransitionParams.bLockOutgoing = Op.Request.field_transitionparams_blockoutgoing();

	// Call implementation and send command response.
	TargetObject->ClientSetViewTarget_Implementation(A, TransitionParams);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetviewtarget>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetSpectatorWaiting_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetSpectatorWaiting_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bWaiting
	bool bWaiting;
	bWaiting = Op.Request.field_bwaiting();

	// Call implementation and send command response.
	TargetObject->ClientSetSpectatorWaiting_Implementation(bWaiting);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetHUD_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsethud>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetHUD_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetHUD_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewHUDClass
	TSubclassOf<AHUD>  NewHUDClass;
	// UNSUPPORTED UClass

	// Call implementation and send command response.
	TargetObject->ClientSetHUD_Implementation(NewHUDClass);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsethud>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetForceMipLevelsToBeResident_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetForceMipLevelsToBeResident_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Material
	UMaterialInterface* Material;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_material();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			Material = static_cast<UMaterialInterface*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			Material = nullptr;
		}
	}

	// Extract ForceDuration
	float ForceDuration;
	ForceDuration = Op.Request.field_forceduration();

	// Extract CinematicTextureGroups
	int32 CinematicTextureGroups;
	CinematicTextureGroups = Op.Request.field_cinematictexturegroups();

	// Call implementation and send command response.
	TargetObject->ClientSetForceMipLevelsToBeResident_Implementation(Material, ForceDuration, CinematicTextureGroups);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetCinematicMode_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcinematicmode>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetCinematicMode_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetCinematicMode_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bInCinematicMode
	bool bInCinematicMode;
	bInCinematicMode = Op.Request.field_bincinematicmode();

	// Extract bAffectsMovement
	bool bAffectsMovement;
	bAffectsMovement = Op.Request.field_baffectsmovement();

	// Extract bAffectsTurning
	bool bAffectsTurning;
	bAffectsTurning = Op.Request.field_baffectsturning();

	// Extract bAffectsHUD
	bool bAffectsHUD;
	bAffectsHUD = Op.Request.field_baffectshud();

	// Call implementation and send command response.
	TargetObject->ClientSetCinematicMode_Implementation(bInCinematicMode, bAffectsMovement, bAffectsTurning, bAffectsHUD);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcinematicmode>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraMode_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcameramode>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetCameraMode_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetCameraMode_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewCamMode
	FName NewCamMode;
	NewCamMode = FName((Op.Request.field_newcammode()).data());

	// Call implementation and send command response.
	TargetObject->ClientSetCameraMode_Implementation(NewCamMode);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcameramode>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraFade_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcamerafade>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetCameraFade_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetCameraFade_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bEnableFading
	bool bEnableFading;
	bEnableFading = Op.Request.field_benablefading();

	// Extract FadeColor
	FColor FadeColor;
	FadeColor.B = uint8(uint8(Op.Request.field_fadecolor_b()));
	FadeColor.G = uint8(uint8(Op.Request.field_fadecolor_g()));
	FadeColor.R = uint8(uint8(Op.Request.field_fadecolor_r()));
	FadeColor.A = uint8(uint8(Op.Request.field_fadecolor_a()));

	// Extract FadeAlpha
	FVector2D FadeAlpha;
	FadeAlpha.X = Op.Request.field_fadealpha_x();
	FadeAlpha.Y = Op.Request.field_fadealpha_y();

	// Extract FadeTime
	float FadeTime;
	FadeTime = Op.Request.field_fadetime();

	// Extract bFadeAudio
	bool bFadeAudio;
	bFadeAudio = Op.Request.field_bfadeaudio();

	// Call implementation and send command response.
	TargetObject->ClientSetCameraFade_Implementation(bEnableFading, FadeColor, FadeAlpha, FadeTime, bFadeAudio);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetcamerafade>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetBlockOnAsyncLoading_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetBlockOnAsyncLoading_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientSetBlockOnAsyncLoading_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>(Op);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenu>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientReturnToMainMenu_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientReturnToMainMenu_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract ReturnReason
	FString ReturnReason;
	ReturnReason = FString(UTF8_TO_TCHAR(Op.Request.field_returnreason().c_str()));

	// Call implementation and send command response.
	TargetObject->ClientReturnToMainMenu_Implementation(ReturnReason);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenu>(Op);
}

void USpatialTypeBinding_PlayerController::ClientRetryClientRestart_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientretryclientrestart>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientRetryClientRestart_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientRetryClientRestart_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewPawn
	APawn* NewPawn;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_newpawn();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			NewPawn = static_cast<APawn*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			NewPawn = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ClientRetryClientRestart_Implementation(NewPawn);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientretryclientrestart>(Op);
}

void USpatialTypeBinding_PlayerController::ClientRestart_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrestart>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientRestart_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientRestart_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewPawn
	APawn* NewPawn;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_newpawn();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			NewPawn = static_cast<APawn*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			NewPawn = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ClientRestart_Implementation(NewPawn);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrestart>(Op);
}

void USpatialTypeBinding_PlayerController::ClientReset_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreset>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientReset_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientReset_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientReset_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreset>(Op);
}

void USpatialTypeBinding_PlayerController::ClientRepObjRef_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrepobjref>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientRepObjRef_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientRepObjRef_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Object
	UObject* Object;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_object();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			Object = static_cast<UObject*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			Object = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ClientRepObjRef_Implementation(Object);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientrepobjref>(Op);
}

void USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientReceiveLocalizedMessage_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientReceiveLocalizedMessage_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Message
	TSubclassOf<ULocalMessage>  Message;
	// UNSUPPORTED UClass

	// Extract Switch
	int32 Switch;
	Switch = Op.Request.field_switch();

	// Extract RelatedPlayerState_1
	APlayerState* RelatedPlayerState_1;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_relatedplayerstate_1();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			RelatedPlayerState_1 = static_cast<APlayerState*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			RelatedPlayerState_1 = nullptr;
		}
	}

	// Extract RelatedPlayerState_2
	APlayerState* RelatedPlayerState_2;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_relatedplayerstate_2();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			RelatedPlayerState_2 = static_cast<APlayerState*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			RelatedPlayerState_2 = nullptr;
		}
	}

	// Extract OptionalObject
	UObject* OptionalObject;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_optionalobject();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			OptionalObject = static_cast<UObject*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			OptionalObject = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ClientReceiveLocalizedMessage_Implementation(Message, Switch, RelatedPlayerState_1, RelatedPlayerState_2, OptionalObject);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPrestreamTextures_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientprestreamtextures>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPrestreamTextures_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPrestreamTextures_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract ForcedActor
	AActor* ForcedActor;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_forcedactor();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			ForcedActor = static_cast<AActor*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			ForcedActor = nullptr;
		}
	}

	// Extract ForceDuration
	float ForceDuration;
	ForceDuration = Op.Request.field_forceduration();

	// Extract bEnableStreaming
	bool bEnableStreaming;
	bEnableStreaming = Op.Request.field_benablestreaming();

	// Extract CinematicTextureGroups
	int32 CinematicTextureGroups;
	CinematicTextureGroups = Op.Request.field_cinematictexturegroups();

	// Call implementation and send command response.
	TargetObject->ClientPrestreamTextures_Implementation(ForcedActor, ForceDuration, bEnableStreaming, CinematicTextureGroups);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientprestreamtextures>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPrepareMapChange_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientpreparemapchange>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPrepareMapChange_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPrepareMapChange_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract LevelName
	FName LevelName;
	LevelName = FName((Op.Request.field_levelname()).data());

	// Extract bFirst
	bool bFirst;
	bFirst = Op.Request.field_bfirst();

	// Extract bLast
	bool bLast;
	bLast = Op.Request.field_blast();

	// Call implementation and send command response.
	TargetObject->ClientPrepareMapChange_Implementation(LevelName, bFirst, bLast);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientpreparemapchange>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPlaySoundAtLocation_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPlaySoundAtLocation_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Sound
	USoundBase* Sound;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_sound();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			Sound = static_cast<USoundBase*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			Sound = nullptr;
		}
	}

	// Extract Location
	FVector Location;
	{
		auto& Vector = Op.Request.field_location();
		Location.X = Vector.x();
		Location.Y = Vector.y();
		Location.Z = Vector.z();
	}

	// Extract VolumeMultiplier
	float VolumeMultiplier;
	VolumeMultiplier = Op.Request.field_volumemultiplier();

	// Extract PitchMultiplier
	float PitchMultiplier;
	PitchMultiplier = Op.Request.field_pitchmultiplier();

	// Call implementation and send command response.
	TargetObject->ClientPlaySoundAtLocation_Implementation(Sound, Location, VolumeMultiplier, PitchMultiplier);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPlaySound_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysound>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPlaySound_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPlaySound_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Sound
	USoundBase* Sound;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_sound();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			Sound = static_cast<USoundBase*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			Sound = nullptr;
		}
	}

	// Extract VolumeMultiplier
	float VolumeMultiplier;
	VolumeMultiplier = Op.Request.field_volumemultiplier();

	// Extract PitchMultiplier
	float PitchMultiplier;
	PitchMultiplier = Op.Request.field_pitchmultiplier();

	// Call implementation and send command response.
	TargetObject->ClientPlaySound_Implementation(Sound, VolumeMultiplier, PitchMultiplier);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaysound>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplayforcefeedback>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPlayForceFeedback_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPlayForceFeedback_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract ForceFeedbackEffect
	UForceFeedbackEffect* ForceFeedbackEffect;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_forcefeedbackeffect();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			ForceFeedbackEffect = static_cast<UForceFeedbackEffect*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			ForceFeedbackEffect = nullptr;
		}
	}

	// Extract bLooping
	bool bLooping;
	bLooping = Op.Request.field_blooping();

	// Extract Tag
	FName Tag;
	Tag = FName((Op.Request.field_tag()).data());

	// Call implementation and send command response.
	TargetObject->ClientPlayForceFeedback_Implementation(ForceFeedbackEffect, bLooping, Tag);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplayforcefeedback>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraShake_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycamerashake>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPlayCameraShake_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPlayCameraShake_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Shake
	TSubclassOf<UCameraShake>  Shake;
	// UNSUPPORTED UClass

	// Extract Scale
	float Scale;
	Scale = Op.Request.field_scale();

	// Extract PlaySpace
	TEnumAsByte<ECameraAnimPlaySpace::Type> PlaySpace;
	PlaySpace = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(Op.Request.field_playspace()));

	// Extract UserPlaySpaceRot
	FRotator UserPlaySpaceRot;
	{
		auto& Rotator = Op.Request.field_userplayspacerot();
		UserPlaySpaceRot.Yaw = Rotator.yaw();
		UserPlaySpaceRot.Pitch = Rotator.pitch();
		UserPlaySpaceRot.Roll = Rotator.roll();
	}

	// Call implementation and send command response.
	TargetObject->ClientPlayCameraShake_Implementation(Shake, Scale, PlaySpace, UserPlaySpaceRot);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycamerashake>(Op);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycameraanim>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientPlayCameraAnim_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientPlayCameraAnim_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract AnimToPlay
	UCameraAnim* AnimToPlay;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_animtoplay();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			AnimToPlay = static_cast<UCameraAnim*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			AnimToPlay = nullptr;
		}
	}

	// Extract Scale
	float Scale;
	Scale = Op.Request.field_scale();

	// Extract Rate
	float Rate;
	Rate = Op.Request.field_rate();

	// Extract BlendInTime
	float BlendInTime;
	BlendInTime = Op.Request.field_blendintime();

	// Extract BlendOutTime
	float BlendOutTime;
	BlendOutTime = Op.Request.field_blendouttime();

	// Extract bLoop
	bool bLoop;
	bLoop = Op.Request.field_bloop();

	// Extract bRandomStartTime
	bool bRandomStartTime;
	bRandomStartTime = Op.Request.field_brandomstarttime();

	// Extract Space
	TEnumAsByte<ECameraAnimPlaySpace::Type> Space;
	Space = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(Op.Request.field_space()));

	// Extract CustomPlaySpace
	FRotator CustomPlaySpace;
	{
		auto& Rotator = Op.Request.field_customplayspace();
		CustomPlaySpace.Yaw = Rotator.yaw();
		CustomPlaySpace.Pitch = Rotator.pitch();
		CustomPlaySpace.Roll = Rotator.roll();
	}

	// Call implementation and send command response.
	TargetObject->ClientPlayCameraAnim_Implementation(AnimToPlay, Scale, Rate, BlendInTime, BlendOutTime, bLoop, bRandomStartTime, Space, CustomPlaySpace);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientplaycameraanim>(Op);
}

void USpatialTypeBinding_PlayerController::ClientMutePlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmuteplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientMutePlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientMutePlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PlayerId
	FUniqueNetIdRepl PlayerId;
	{
		auto& ValueDataStr = Op.Request.field_playerid();
		TArray<uint8> ValueData;
		ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
		FMemoryReader ValueDataReader(ValueData);
		bool bSuccess;
		PlayerId.NetSerialize(ValueDataReader, nullptr, bSuccess);
	}

	// Call implementation and send command response.
	TargetObject->ClientMutePlayer_Implementation(PlayerId);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmuteplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ClientMessage_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmessage>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientMessage_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientMessage_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract S
	FString S;
	S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));

	// Extract Type
	FName Type;
	Type = FName((Op.Request.field_type()).data());

	// Extract MsgLifeTime
	float MsgLifeTime;
	MsgLifeTime = Op.Request.field_msglifetime();

	// Call implementation and send command response.
	TargetObject->ClientMessage_Implementation(S, Type, MsgLifeTime);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientmessage>(Op);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignoremoveinput>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientIgnoreMoveInput_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientIgnoreMoveInput_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bIgnore
	bool bIgnore;
	bIgnore = Op.Request.field_bignore();

	// Call implementation and send command response.
	TargetObject->ClientIgnoreMoveInput_Implementation(bIgnore);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignoremoveinput>(Op);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignorelookinput>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientIgnoreLookInput_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientIgnoreLookInput_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bIgnore
	bool bIgnore;
	bIgnore = Op.Request.field_bignore();

	// Call implementation and send command response.
	TargetObject->ClientIgnoreLookInput_Implementation(bIgnore);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientignorelookinput>(Op);
}

void USpatialTypeBinding_PlayerController::ClientGotoState_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgotostate>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientGotoState_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientGotoState_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewState
	FName NewState;
	NewState = FName((Op.Request.field_newstate()).data());

	// Call implementation and send command response.
	TargetObject->ClientGotoState_Implementation(NewState);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgotostate>(Op);
}

void USpatialTypeBinding_PlayerController::ClientGameEnded_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgameended>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientGameEnded_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientGameEnded_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract EndGameFocus
	AActor* EndGameFocus;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_endgamefocus();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			EndGameFocus = static_cast<AActor*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			EndGameFocus = nullptr;
		}
	}

	// Extract bIsWinner
	bool bIsWinner;
	bIsWinner = Op.Request.field_biswinner();

	// Call implementation and send command response.
	TargetObject->ClientGameEnded_Implementation(EndGameFocus, bIsWinner);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientgameended>(Op);
}

void USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientForceGarbageCollection_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientForceGarbageCollection_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientForceGarbageCollection_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>(Op);
}

void USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientFlushLevelStreaming_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientFlushLevelStreaming_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientFlushLevelStreaming_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>(Op);
}

void USpatialTypeBinding_PlayerController::ClientEndOnlineSession_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientendonlinesession>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientEndOnlineSession_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientEndOnlineSession_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientEndOnlineSession_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientendonlinesession>(Op);
}

void USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientEnableNetworkVoice_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientEnableNetworkVoice_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bEnable
	bool bEnable;
	bEnable = Op.Request.field_benable();

	// Call implementation and send command response.
	TargetObject->ClientEnableNetworkVoice_Implementation(bEnable);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>(Op);
}

void USpatialTypeBinding_PlayerController::ClientCommitMapChange_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcommitmapchange>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCommitMapChange_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCommitMapChange_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientCommitMapChange_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcommitmapchange>(Op);
}

void USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientClearCameraLensEffects_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientClearCameraLensEffects_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientClearCameraLensEffects_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>(Op);
}

void USpatialTypeBinding_PlayerController::ClientCapBandwidth_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcapbandwidth>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCapBandwidth_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCapBandwidth_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract Cap
	int32 Cap;
	Cap = Op.Request.field_cap();

	// Call implementation and send command response.
	TargetObject->ClientCapBandwidth_Implementation(Cap);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcapbandwidth>(Op);
}

void USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCancelPendingMapChange_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCancelPendingMapChange_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientCancelPendingMapChange_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>(Op);
}

void USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientAddTextureStreamingLoc_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientAddTextureStreamingLoc_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract InLoc
	FVector InLoc;
	{
		auto& Vector = Op.Request.field_inloc();
		InLoc.X = Vector.x();
		InLoc.Y = Vector.y();
		InLoc.Z = Vector.z();
	}

	// Extract Duration
	float Duration;
	Duration = Op.Request.field_duration();

	// Extract bOverrideLocation
	bool bOverrideLocation;
	bOverrideLocation = Op.Request.field_boverridelocation();

	// Call implementation and send command response.
	TargetObject->ClientAddTextureStreamingLoc_Implementation(InLoc, Duration, bOverrideLocation);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetRotation_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetrotation>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetRotation_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetRotation_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewRotation
	FRotator NewRotation;
	{
		auto& Rotator = Op.Request.field_newrotation();
		NewRotation.Yaw = Rotator.yaw();
		NewRotation.Pitch = Rotator.pitch();
		NewRotation.Roll = Rotator.roll();
	}

	// Extract bResetCamera
	bool bResetCamera;
	bResetCamera = Op.Request.field_bresetcamera();

	// Call implementation and send command response.
	TargetObject->ClientSetRotation_Implementation(NewRotation, bResetCamera);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetrotation>(Op);
}

void USpatialTypeBinding_PlayerController::ClientSetLocation_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetlocation>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientSetLocation_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientSetLocation_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewLocation
	FVector NewLocation;
	{
		auto& Vector = Op.Request.field_newlocation();
		NewLocation.X = Vector.x();
		NewLocation.Y = Vector.y();
		NewLocation.Z = Vector.z();
	}

	// Extract NewRotation
	FRotator NewRotation;
	{
		auto& Rotator = Op.Request.field_newrotation();
		NewRotation.Yaw = Rotator.yaw();
		NewRotation.Pitch = Rotator.pitch();
		NewRotation.Roll = Rotator.roll();
	}

	// Call implementation and send command response.
	TargetObject->ClientSetLocation_Implementation(NewLocation, NewRotation);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerClientRPCs::Commands::Clientsetlocation>(Op);
}

void USpatialTypeBinding_PlayerController::ServerViewSelf_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewself>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerViewSelf_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerViewSelf_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract TransitionParams
	FViewTargetTransitionParams TransitionParams;
	TransitionParams.BlendTime = Op.Request.field_transitionparams_blendtime();
	TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(Op.Request.field_transitionparams_blendfunction()));
	TransitionParams.BlendExp = Op.Request.field_transitionparams_blendexp();
	TransitionParams.bLockOutgoing = Op.Request.field_transitionparams_blockoutgoing();

	// Call implementation and send command response.
	TargetObject->ServerViewSelf_Implementation(TransitionParams);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewself>(Op);
}

void USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewprevplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerViewPrevPlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerViewPrevPlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerViewPrevPlayer_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewprevplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ServerViewNextPlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewnextplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerViewNextPlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerViewNextPlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerViewNextPlayer_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverviewnextplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serververifyviewtarget>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerVerifyViewTarget_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerVerifyViewTarget_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerVerifyViewTarget_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serververifyviewtarget>(Op);
}

void USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerUpdateLevelVisibility_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerUpdateLevelVisibility_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PackageName
	FName PackageName;
	PackageName = FName((Op.Request.field_packagename()).data());

	// Extract bIsVisible
	bool bIsVisible;
	bIsVisible = Op.Request.field_bisvisible();

	// Call implementation and send command response.
	TargetObject->ServerUpdateLevelVisibility_Implementation(PackageName, bIsVisible);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>(Op);
}

void USpatialTypeBinding_PlayerController::ServerUpdateCamera_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatecamera>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerUpdateCamera_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerUpdateCamera_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract CamLoc
	FVector_NetQuantize CamLoc;
	{
		auto& Vector = Op.Request.field_camloc();
		CamLoc.X = Vector.x();
		CamLoc.Y = Vector.y();
		CamLoc.Z = Vector.z();
	}

	// Extract CamPitchAndYaw
	int32 CamPitchAndYaw;
	CamPitchAndYaw = Op.Request.field_campitchandyaw();

	// Call implementation and send command response.
	TargetObject->ServerUpdateCamera_Implementation(CamLoc, CamPitchAndYaw);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverupdatecamera>(Op);
}

void USpatialTypeBinding_PlayerController::ServerUnmutePlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverunmuteplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerUnmutePlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerUnmutePlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PlayerId
	FUniqueNetIdRepl PlayerId;
	{
		auto& ValueDataStr = Op.Request.field_playerid();
		TArray<uint8> ValueData;
		ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
		FMemoryReader ValueDataReader(ValueData);
		bool bSuccess;
		PlayerId.NetSerialize(ValueDataReader, nullptr, bSuccess);
	}

	// Call implementation and send command response.
	TargetObject->ServerUnmutePlayer_Implementation(PlayerId);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverunmuteplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ServerToggleAILogging_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servertoggleailogging>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerToggleAILogging_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerToggleAILogging_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerToggleAILogging_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servertoggleailogging>(Op);
}

void USpatialTypeBinding_PlayerController::ServerShortTimeout_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servershorttimeout>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerShortTimeout_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerShortTimeout_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerShortTimeout_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servershorttimeout>(Op);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerSetSpectatorWaiting_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerSetSpectatorWaiting_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract bWaiting
	bool bWaiting;
	bWaiting = Op.Request.field_bwaiting();

	// Call implementation and send command response.
	TargetObject->ServerSetSpectatorWaiting_Implementation(bWaiting);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>(Op);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorlocation>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerSetSpectatorLocation_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerSetSpectatorLocation_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewLoc
	FVector NewLoc;
	{
		auto& Vector = Op.Request.field_newloc();
		NewLoc.X = Vector.x();
		NewLoc.Y = Vector.y();
		NewLoc.Z = Vector.z();
	}

	// Extract NewRot
	FRotator NewRot;
	{
		auto& Rotator = Op.Request.field_newrot();
		NewRot.Yaw = Rotator.yaw();
		NewRot.Pitch = Rotator.pitch();
		NewRot.Roll = Rotator.roll();
	}

	// Call implementation and send command response.
	TargetObject->ServerSetSpectatorLocation_Implementation(NewLoc, NewRot);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorlocation>(Op);
}

void USpatialTypeBinding_PlayerController::ServerRestartPlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverrestartplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerRestartPlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerRestartPlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerRestartPlayer_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverrestartplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ServerPause_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverpause>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerPause_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerPause_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerPause_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverpause>(Op);
}

void USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servernotifyloadedworld>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerNotifyLoadedWorld_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerNotifyLoadedWorld_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract WorldPackageName
	FName WorldPackageName;
	WorldPackageName = FName((Op.Request.field_worldpackagename()).data());

	// Call implementation and send command response.
	TargetObject->ServerNotifyLoadedWorld_Implementation(WorldPackageName);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servernotifyloadedworld>(Op);
}

void USpatialTypeBinding_PlayerController::ServerMutePlayer_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servermuteplayer>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerMutePlayer_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerMutePlayer_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract PlayerId
	FUniqueNetIdRepl PlayerId;
	{
		auto& ValueDataStr = Op.Request.field_playerid();
		TArray<uint8> ValueData;
		ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
		FMemoryReader ValueDataReader(ValueData);
		bool bSuccess;
		PlayerId.NetSerialize(ValueDataReader, nullptr, bSuccess);
	}

	// Call implementation and send command response.
	TargetObject->ServerMutePlayer_Implementation(PlayerId);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servermuteplayer>(Op);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerCheckClientPossessionReliable_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerCheckClientPossessionReliable_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerCheckClientPossessionReliable_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>(Op);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossession_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossession>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerCheckClientPossession_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerCheckClientPossession_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ServerCheckClientPossession_Implementation();
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossession>(Op);
}

void USpatialTypeBinding_PlayerController::ServerChangeName_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverchangename>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerChangeName_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerChangeName_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract S
	FString S;
	S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));

	// Call implementation and send command response.
	TargetObject->ServerChangeName_Implementation(S);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serverchangename>(Op);
}

void USpatialTypeBinding_PlayerController::ServerCamera_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercamera>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerCamera_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerCamera_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract NewMode
	FName NewMode;
	NewMode = FName((Op.Request.field_newmode()).data());

	// Call implementation and send command response.
	TargetObject->ServerCamera_Implementation(NewMode);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Servercamera>(Op);
}

void USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_Receiver(const worker::CommandRequestOp<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serveracknowledgepossession>& Op)
{
	FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ServerAcknowledgePossession_Receiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	APlayerController* TargetObject = Cast<APlayerController>(PackageMap->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ServerAcknowledgePossession_Receiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Extract P
	APawn* P;
	{
		improbable::unreal::UnrealObjectRef TargetObject = Op.Request.field_p();
		FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObject);
		if (NetGUID.IsValid())
		{
			P = static_cast<APawn*>(PackageMap->GetObjectFromNetGUID(NetGUID, true));
		}
		else
		{
			P = nullptr;
		}
	}

	// Call implementation and send command response.
	TargetObject->ServerAcknowledgePossession_Implementation(P);
	SendRPCResponse<improbable::unreal::UnrealPlayerControllerServerRPCs::Commands::Serveracknowledgepossession>(Op);
}