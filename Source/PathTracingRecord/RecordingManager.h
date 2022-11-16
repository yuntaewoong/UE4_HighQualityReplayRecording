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

	UFUNCTION(BlueprintCallable)
		TArray<FString> GetReplayFileNameStrings();// ������Ʈ���/Saved/Demos�� ����� .replay���ϵ��� �̸��迭�� ����
private:
    struct DirectoryVisitor : public IPlatformFile::FDirectoryVisitor
    {
		DirectoryVisitor(TArray<FString>* pReplayFileNames)
		{
			m_pReplayFileNames = pReplayFileNames;
		}
		TArray<FString>* m_pReplayFileNames;//replay���ϵ��� �̸��迭 ������
        bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override//���丮�� ��ȸ�Ҷ����� ����Ǵ� �Լ�
        {
			if (bIsDirectory)
				return true;//���丮�� ��� �ƹ��͵� ����
			FString replayName = FPaths::GetPathLeaf(FilenameOrDirectory);//����� ������ �̸�=�����̸�
			replayName = replayName.Replace(TEXT(".replay"), TEXT(""));//.replay���˸� ����
			m_pReplayFileNames->Add(replayName);//�迭�� �߰�
            return true;
        }
    };
	bool m_IsRecording = false;//���� recording�������� ��Ÿ��

};

