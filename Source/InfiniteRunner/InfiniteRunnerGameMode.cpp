// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfiniteRunnerGameMode.h"

#include "InfiniteRunnerPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AInfiniteRunnerGameMode::AInfiniteRunnerGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Defaultoot"));
	RootComponent = DefaultRoot;
	PlayerControllerClass = AInfiniteRunnerPlayerController::StaticClass();
	CurrentHealth = MaxHealth;
}

void AInfiniteRunnerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LevelSpeed += LevelAcceleration * DeltaTime;
}

float AInfiniteRunnerGameMode::GetLaneOffset(int LaneIndex)
{
	// Return the expected player (or obstacle) position based on the lane index
	return (LaneIndex - NumberOfLanes / 2) * LaneWidth;
}
