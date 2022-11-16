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

	UFUNCTION(BlueprintCallable)
		TArray<FString> GetReplayFileNameStrings();// 프로젝트경로/Saved/Demos에 저장된 .replay파일들의 이름배열을 리턴
private:
    struct DirectoryVisitor : public IPlatformFile::FDirectoryVisitor
    {
		DirectoryVisitor(TArray<FString>* pReplayFileNames)
		{
			m_pReplayFileNames = pReplayFileNames;
		}
		TArray<FString>* m_pReplayFileNames;//replay파일들의 이름배열 포인터
        bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override//디렉토리를 순회할때마다 실행되는 함수
        {
			if (bIsDirectory)
				return true;//디렉토리인 경우 아무것도 안함
			FString replayName = FPaths::GetPathLeaf(FilenameOrDirectory);//경로의 최하위 이름=파일이름
			replayName = replayName.Replace(TEXT(".replay"), TEXT(""));//.replay포맷명 삭제
			m_pReplayFileNames->Add(replayName);//배열에 추가
            return true;
        }
    };
	bool m_IsRecording = false;//현재 recording중인지를 나타냄

};

