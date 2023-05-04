#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

class UBoxComponent;

/** Base class for all obstacles in the game **/
UCLASS()
class INFINITERUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UFUNCTION(BlueprintCallable)
	void Remove();
	UFUNCTION(BlueprintCallable)
	void RemoveNext();
	UFUNCTION(BlueprintCallable)
	void SetNext(AObstacle* Next);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	AObstacle* NextObstacle;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collision;
};
