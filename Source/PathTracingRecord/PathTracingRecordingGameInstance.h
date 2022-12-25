// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PathTracingRecordingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PATHTRACINGRECORD_API UPathTracingRecordingGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPathTracingRecordingGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartRecording(FString replayName);//replayName.replay�̸��� ���÷��� ���� ����

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StopRecording();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartReplay(FString replayName);//replayName.replay�̸��� ���÷��� �������

	UFUNCTION(BlueprintCallable)
		void SetCustomizingInfo(FString customizingInfo);

	UFUNCTION(BlueprintCallable)
		FString GetCustomizingInfo();
private:
	FString mCustomizingInfo;
};
