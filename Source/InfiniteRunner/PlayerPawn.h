#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class AInfiniteRunnerGameMode;
class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;

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
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveRight();
	void MoveLeft();
	void SwitchLane(int direction);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
	AInfiniteRunnerGameMode* GameMode;
	
	int CurrentLane;
};