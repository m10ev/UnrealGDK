// Fill out your copyright notice in the Description page of Project Settings.

#include "SpatialActorSpawner.h"

void USpatialActorSpawner::RegisterCallbacks(View& view)
{
	view.OnAddEntity([this](const AddEntityOp& op) {
		AddEntity(op);
	});

	view.OnRemoveEntity([this](const RemoveEntityOp& op) {
		RemoveEntity(op);
	});

	view.OnCriticalSection([this](const CriticalSectionOp op) {
		HitCriticalSection(op);
	});
}

void USpatialActorSpawner::AddEntity(const AddEntityOp& op)
{
	if(inCriticalSection)
	{
		PendingAddEntityOps.Add(op);
		return;
	}

	CreateActor();
}

void USpatialActorSpawner::RemoveEntity(const RemoveEntityOp& op)
{
	if(inCriticalSection)
	{
		PendingRemoveEntityOps.Add(op);
		return;
	}


}

void USpatialActorSpawner::HitCriticalSection(const CriticalSectionOp& op)
{
	if(!inCriticalSection)
	{
		inCriticalSection = true;
	}
	else
	{
		inCriticalSection = false;

		for(const AddEntityOp& op : PendingAddEntityOps)
		{
			AddEntity(op);
		}
		PendingAddEntityOps.Empty();

		for(const RemoveEntityOp& op : PendingRemoveEntityOps)
		{
			RemoveEntity(op);
		}
	}
}

void USpatialActorSpawner::CreateActor()
{

}

void USpatialActorSpawner::SpawnActor()
{

}

void USpatialActorSpawner::GetNativeEntityClass()
{

}

void USpatialActorSpawner::SetupComponentInterest()
{

}

