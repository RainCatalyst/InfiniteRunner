#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class AObstacle;
class AInfiniteRunnerGameMode;
class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;

/** Base class for the player pawn **/
UCLASS()
class INFINITERUNNER_API APlayerPawn : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void MoveRight();
	void MoveLeft();
	void AssignIndex(int Index);
	int GetIndex();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SwitchLane(int Direction);
	void UpdatePosition();

	UFUNCTION(BlueprintImplementableEvent)
	void OnObstacleHit(AObstacle* Obstacle);
	UFUNCTION(BlueprintImplementableEvent)
	void OnObstacleDodged(AObstacle* Obstacle);

	UPROPERTY(BlueprintReadOnly)
	AInfiniteRunnerGameMode* GameMode;

	UPROPERTY(BlueprintReadOnly)
	int CurrentLane;
	UPROPERTY(BlueprintReadOnly)
	int PlayerIndex;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	bool Initialised;
};