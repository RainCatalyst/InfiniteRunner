// Responsible for spawn
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
	AObjectSpawner();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawn();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<AActor>> SpawnableObjects;
	UPROPERTY(EditAnywhere)
	float SpawnDistance;
	UPROPERTY(EditAnywhere)
	float SpawnChance;
	
	UPROPERTY()
	AInfiniteRunnerGameMode* GameMode;
private:
	float CurrentDistance;
};
