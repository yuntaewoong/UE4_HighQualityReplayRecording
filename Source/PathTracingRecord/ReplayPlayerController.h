// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReplayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PATHTRACINGRECORD_API AReplayPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AReplayPlayerController();
	UFUNCTION(BlueprintCallable)
		void RestartReplay();
};
