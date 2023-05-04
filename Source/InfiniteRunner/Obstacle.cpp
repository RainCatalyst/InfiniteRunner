#include "Obstacle.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = true;
	NextObstacle = nullptr;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
}

void AObstacle::Remove()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroying self"));
	Destroy();
}

void AObstacle::RemoveNext()
{
	if (NextObstacle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Removing next"));
		NextObstacle->Remove();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Removing next"));
	}
}

void AObstacle::SetNext(AObstacle* Next)
{
	NextObstacle = Next;
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();
}

