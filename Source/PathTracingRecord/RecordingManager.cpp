// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordingManager.h"

ARecordingManager::ARecordingManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool ARecordingManager::GetIsRecording()
{
	return m_IsRecording;
}

void ARecordingManager::SetIsRecording(bool isRecording)
{
	m_IsRecording = isRecording;
}



