// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_TestsGameMode.h"
#include "UE5_TestsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_TestsGameMode::AUE5_TestsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
