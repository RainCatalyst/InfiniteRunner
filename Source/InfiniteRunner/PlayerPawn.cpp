#include "PlayerPawn.h"

#include "InfiniteRunnerGameMode.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
    
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);
    Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
    Capsule->SetupAttachment(RootComponent);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 800.f;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AInfiniteRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Theres a mode!")));
	}
	
	CurrentLane = GameMode->NumberOfLanes / 2;
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::MoveRight()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("RIGHT!")));
	SwitchLane(1);
}

void APlayerPawn::MoveLeft()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("LEFT!")));
	SwitchLane(-1);
}

void APlayerPawn::SwitchLane(int direction)
{
    // Tries to move the character lane in a direction
    int newLane = CurrentLane + direction;
    // Check if we are moving within legal limits
    if (newLane < 0 || newLane > GameMode->NumberOfLanes - 1) return;
	
    // Update current lane
    CurrentLane = newLane;
    float targetPosition = GameMode->GetLaneOffset(CurrentLane);

    // Move actor
    FVector currentPosition = GetActorLocation();
    currentPosition.Y = targetPosition;
    SetActorLocation(currentPosition);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerPawn::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerPawn::MoveRight);
}