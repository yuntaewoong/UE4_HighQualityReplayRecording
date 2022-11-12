// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplayPlayerController.h"
#include "Engine/World.h"
#include "Engine/DemoNetDriver.h"

void AReplayPlayerController::RestartReplay()
{
	if (UWorld* world = GetWorld())
	{
		if(UDemoNetDriver * demoDriver = world->GetDemoNetDriver())
		{
			demoDriver->GotoTimeInSeconds(0.f);
		}
	}
}
