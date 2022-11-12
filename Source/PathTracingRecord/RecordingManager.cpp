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

TArray<FString> ARecordingManager::GetReplayFileNames()
{
    TArray<FString> fileNames= TArray<FString>();//결과 FString배열
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();//언리얼 file system레퍼런스
    FString replayDirectory = TEXT("");
    {//replay 디렉토리는 프로젝트directory/Saved/Demos/
        replayDirectory = FPaths::ProjectSavedDir();
        replayDirectory.Append(TEXT("Demos/"));
        if (!FileManager.DirectoryExists(*replayDirectory))//디렉토리 존재 체크
            UE_LOG(LogTemp, Error, TEXT("FilePaths: %s does not exist"), *replayDirectory);
    } 
    DirectoryVisitor visitor(&fileNames);//커스텀 visitor
    if (!FileManager.IterateDirectory(*replayDirectory, visitor))//디렉토리 순회
        UE_LOG(LogTemp, Warning, TEXT("FilePaths: Directory did not exist or visitor returned false"));
        
    return fileNames;

}



