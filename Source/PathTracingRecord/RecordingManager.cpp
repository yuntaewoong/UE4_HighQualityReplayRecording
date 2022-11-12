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
    TArray<FString> fileNames= TArray<FString>();//��� FString�迭
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();//�𸮾� file system���۷���
    FString replayDirectory = TEXT("");
    {//replay ���丮�� ������Ʈdirectory/Saved/Demos/
        replayDirectory = FPaths::ProjectSavedDir();
        replayDirectory.Append(TEXT("Demos/"));
        if (!FileManager.DirectoryExists(*replayDirectory))//���丮 ���� üũ
            UE_LOG(LogTemp, Error, TEXT("FilePaths: %s does not exist"), *replayDirectory);
    } 
    DirectoryVisitor visitor(&fileNames);//Ŀ���� visitor
    if (!FileManager.IterateDirectory(*replayDirectory, visitor))//���丮 ��ȸ
        UE_LOG(LogTemp, Warning, TEXT("FilePaths: Directory did not exist or visitor returned false"));
        
    return fileNames;

}



