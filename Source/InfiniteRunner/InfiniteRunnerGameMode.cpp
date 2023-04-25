// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfiniteRunnerGameMode.h"
#include "Components/BoxComponent.h"
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

	LevelBounds = CreateDefaultSubobject<UBoxComponent>(FName("CPPLevelBounds"));
	LevelBounds->SetupAttachment(DefaultRoot);
}
