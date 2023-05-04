// Fill out your copyright notice in the Description page of Project Settings.


#include "InfiniteRunnerPlayerController.h"

#include "InfiniteRunnerGameMode.h"
#include "PlayerPawn.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

AInfiniteRunnerPlayerController::AInfiniteRunnerPlayerController()
{
	
}

// void AInfiniteRunnerPlayerController::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// }

void AInfiniteRunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// GameMode = Cast<AInfiniteRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	// Spawn players
	Player1 = Cast<APlayerPawn>(GetPawn());
	Player2 = GetWorld()->SpawnActor<APlayerPawn>(GetWorld()->GetAuthGameMode()->DefaultPawnClass, FVector(0, 200, 0), FRotator(0, 0, 0));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Spawning players!")));

	// Assign player indices
	Player1->AssignIndex(0);
	Player2->AssignIndex(1);

	// Bind input
	InputComponent->BindAction("MoveLeft1", IE_Pressed, this, &AInfiniteRunnerPlayerController::MoveLeft1);
	InputComponent->BindAction("MoveRight1", IE_Pressed, this, &AInfiniteRunnerPlayerController::MoveRight1);
	InputComponent->BindAction("MoveLeft2", IE_Pressed, this, &AInfiniteRunnerPlayerController::MoveLeft2);
	InputComponent->BindAction("MoveRight2", IE_Pressed, this, &AInfiniteRunnerPlayerController::MoveRight2);
}

void AInfiniteRunnerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void AInfiniteRunnerPlayerController::MoveLeft1()
{
	Player1->MoveLeft();
}

void AInfiniteRunnerPlayerController::MoveRight1()
{
	Player1->MoveRight();
}

void AInfiniteRunnerPlayerController::MoveLeft2()
{
	Player2->MoveLeft();
}

void AInfiniteRunnerPlayerController::MoveRight2()
{
	Player2->MoveRight();
}
