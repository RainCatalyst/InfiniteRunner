#include "ObjectSpawner.h"

#include "Math/UnrealMathUtility.h"
#include "InfiniteRunnerGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObjectSpawner::AObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentDistance = 0;
}

// Called when the game starts or when spawned
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
		GetWorld()->SpawnActor<AActor>(SpawnableObject[FMath::RandRange(0, SpawnableObject.Num() - 1)], GetActorLocation(), GetActorRotation(), FActorSpawnParameters());
	}
}

