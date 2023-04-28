// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfiniteRunnerGameMode.h"
#include "UObject/ConstructorHelpers.h"

AInfiniteRunnerGameMode::AInfiniteRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Defaultoot"));
	RootComponent = DefaultRoot;
}

float AInfiniteRunnerGameMode::GetLaneOffset(int laneIndex)
{
	return (laneIndex - NumberOfLanes / 2) * LaneWidth;
}
