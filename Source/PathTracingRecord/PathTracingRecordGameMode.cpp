// Copyright Epic Games, Inc. All Rights Reserved.

#include "PathTracingRecordGameMode.h"
#include "PathTracingRecordCharacter.h"
#include "UObject/ConstructorHelpers.h"

APathTracingRecordGameMode::APathTracingRecordGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
