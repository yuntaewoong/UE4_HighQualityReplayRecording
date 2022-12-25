// Fill out your copyright notice in the Description page of Project Settings.


#include "PathTracingRecordingGameInstance.h"

UPathTracingRecordingGameInstance::UPathTracingRecordingGameInstance()
{
}

void UPathTracingRecordingGameInstance::StartRecording(FString replayName)
{
	StartRecordingReplay(replayName, "?");
}

void UPathTracingRecordingGameInstance::StopRecording()
{
	StopRecordingReplay();
}

void UPathTracingRecordingGameInstance::StartReplay(FString replayName)
{
	PlayReplay(replayName, nullptr);
}

void UPathTracingRecordingGameInstance::SetCustomizingInfo(FString customizingInfo)
{
	mCustomizingInfo = customizingInfo;
}

FString UPathTracingRecordingGameInstance::GetCustomizingInfo()
{
	return mCustomizingInfo;
}
