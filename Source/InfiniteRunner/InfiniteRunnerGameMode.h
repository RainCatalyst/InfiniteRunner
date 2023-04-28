// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InfiniteRunnerGameMode.generated.h"

class UBoxComponent;
class USceneComponent;

UCLASS(minimalapi)
class AInfiniteRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInfiniteRunnerGameMode();

	float GetLaneOffset(int laneIndex);
	
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere)
	int NumberOfLanes = 3;
	UPROPERTY(EditAnywhere)
	float LaneWidth = 250.f;
	UPROPERTY(EditAnywhere)
	float LevelSpeed = 500.f;
	UPROPERTY(EditAnywhere)
	float OutOfBoundsLocation = -100.f;
};



