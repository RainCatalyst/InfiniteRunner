// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InfiniteRunnerPlayerController.generated.h"

class AInfiniteRunnerGameMode;
class APlayerPawn;

/** Spawns two players and handles separate inputs **/
UCLASS()
class INFINITERUNNER_API AInfiniteRunnerPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AInfiniteRunnerPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	UPROPERTY()
	APlayerPawn* Player1;
	UPROPERTY()
	APlayerPawn* Player2;

private:
	UPROPERTY()
	AInfiniteRunnerGameMode* GameMode;
	
	void MoveLeft1();
	void MoveRight1();
	void MoveLeft2();
	void MoveRight2();
};
