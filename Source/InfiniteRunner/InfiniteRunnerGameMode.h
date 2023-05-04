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

	virtual void Tick(float DeltaTime) override;

	float GetLaneOffset(int laneIndex);
	
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MaxHealth = 3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ObstacleDespawnChance = 0.1f;
	UPROPERTY(EditAnywhere)
	int NumberOfLanes = 5;
	UPROPERTY(EditAnywhere)
	float LaneWidth = 250.f;
	UPROPERTY(EditAnywhere)
	float LevelSpeed = 500.f;
	UPROPERTY(EditAnywhere)
	float LevelAcceleration = 10.f;
	UPROPERTY(EditAnywhere)
	float OutOfBoundsLocation = -1000.f;

protected:
	UPROPERTY(BlueprintReadWrite)
	int CurrentHealth;
};



