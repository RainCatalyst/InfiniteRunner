#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectSpawner.generated.h"

class AInfiniteRunnerGameMode;

UCLASS()
class INFINITERUNNER_API AObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectSpawner();
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> SpawnableObject;
	UPROPERTY(EditAnywhere)
	float SpawnDistance;
	
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	AInfiniteRunnerGameMode* GameMode;

	float CurrentDistance;
};
