// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecordingManager.generated.h"
/*

Recording Manager: 게임의 기록을 관장하는 actor

*/

UCLASS()
class PATHTRACINGRECORD_API ARecordingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ARecordingManager();
	
	UFUNCTION(BlueprintCallable)
		bool GetIsRecording();

	UFUNCTION(BlueprintCallable)
		void SetIsRecording(bool isRecording);
private:
	bool m_IsRecording = false;//현재 recording중인지를 나타냄

};
