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
	
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Triggers")
	UBoxComponent* LevelBounds;

	UPROPERTY(EditAnywhere)
	int NumberOfLanes = 3;
	UPROPERTY(EditAnywhere)
	float LaneWidth = 250.f;
	UPROPERTY(EditAnywhere)
	float LevelSpeed = -500.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector OutOfBoundBoxScale = FVector(0.f,0.f,0.f);
	UPROPERTY(BlueprintReadWrite, EditAnywhere,  Meta = (MakeEditWidget = true))
	FVector OutOfBoundBoxLocation = FVector(0.f,0.f,0.f);
};



