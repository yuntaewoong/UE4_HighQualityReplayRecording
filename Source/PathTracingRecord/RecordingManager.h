// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecordingManager.generated.h"
/*

Recording Manager: ������ ����� �����ϴ� actor

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
	bool m_IsRecording = false;//���� recording�������� ��Ÿ��

};
