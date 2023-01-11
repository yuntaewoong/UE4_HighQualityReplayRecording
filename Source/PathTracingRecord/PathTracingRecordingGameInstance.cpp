// Fill out your copyright notice in the Description page of Project Settings.


#include "PathTracingRecordingGameInstance.h"

UPathTracingRecordingGameInstance::UPathTracingRecordingGameInstance()
{
}

void UPathTracingRecordingGameInstance::SetFixedFramerate(int Framerate)
{
	GEngine->FixedFrameRate = Framerate;
}

void UPathTracingRecordingGameInstance::SetBUseFixedFramerate(bool bUseFixed)
{
	GEngine->bUseFixedFrameRate = bUseFixed;
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




