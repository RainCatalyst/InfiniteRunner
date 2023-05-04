#include "PlayerPawn.h"

#include "InfiniteRunnerGameMode.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
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

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AInfiniteRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::OnOverlapBegin);
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Initialised)
	{
		Initialised = true;
		CurrentLane = PlayerIndex == 0 ? 0 : GameMode->NumberOfLanes - 1;
		UpdatePosition();
		UE_LOG(LogTemp, Warning, TEXT("Initialised Player Index: %d, Player Lane: %d"), PlayerIndex, CurrentLane);
	}
}

void APlayerPawn::MoveRight()
{
	SwitchLane(1);
}

void APlayerPawn::MoveLeft()
{
	SwitchLane(-1);
}

void APlayerPawn::AssignIndex(int Index)
{
	PlayerIndex = Index;
	Initialised = false;
}

int APlayerPawn::GetIndex()
{
	return PlayerIndex;
}

void APlayerPawn::SwitchLane(int Direction)
{
    // Tries to move the character lane in a direction
    const int NewLane = CurrentLane + Direction;
    // Check if we are moving within legal limits
    if (NewLane < 0 || NewLane > GameMode->NumberOfLanes - 1) return;
	
    // Update current lane
    CurrentLane = NewLane;
	UpdatePosition();
}

void APlayerPawn::UpdatePosition()
{
	const float TargetPosition = GameMode->GetLaneOffset(CurrentLane);

	// Move actor to match the lane position
	FVector CurrentPosition = GetActorLocation();
	CurrentPosition.Y = TargetPosition;
	SetActorLocation(CurrentPosition);
}

void APlayerPawn::OnOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// If we've hit an obstacle
	if (OtherActor->IsA(AObstacle::StaticClass()))
	{
		if (OtherComp->ComponentTags.Num() > 0)
		{
			if (OtherComp->ComponentTags[0] == TEXT("Hit"))
			{
				// Hit the actual obstacle
				OnObstacleHit(Cast<AObstacle>(OtherActor));
			}
			else if (OtherComp->ComponentTags[0] == TEXT("Dodge"))
			{
				// Hit the "dodge" hitbox
				OnObstacleDodged(Cast<AObstacle>(OtherActor));
			}
		}
	}
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}