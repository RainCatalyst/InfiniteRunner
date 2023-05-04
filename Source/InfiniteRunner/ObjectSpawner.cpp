#include "ObjectSpawner.h"

#include "Math/UnrealMathUtility.h"
#include "InfiniteRunnerGameMode.h"
#include "Kismet/GameplayStatics.h"

AObjectSpawner::AObjectSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentDistance = 0;
}

void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AInfiniteRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentDistance += GameMode->LevelSpeed * DeltaTime;

	// Spawn Logic
	if (CurrentDistance > SpawnDistance)
	{
		CurrentDistance -= SpawnDistance;
		if (FMath::FRandRange(0, 1) < SpawnChance)
		{
			// Call a BP event
			OnSpawn();
			// GetWorld()->SpawnActor<AActor>(SpawnableObjects[FMath::RandRange(0, SpawnableObjects.Num() - 1)], GetActorLocation(), GetActorRotation(), FActorSpawnParameters());
		}
	}
}

