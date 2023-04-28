#include "ScrollComponent.h"
#include "Kismet/GameplayStatics.h"
#include "InfiniteRunnerGameMode.h"

UScrollComponent::UScrollComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UScrollComponent::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AInfiniteRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void UScrollComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		FVector Movement = (Parent->GetActorForwardVector() * GameMode->LevelSpeed) * DeltaTime; 
		Parent->AddActorLocalOffset(-Movement);
		if (Parent->GetActorLocation().X < GameMode->OutOfBoundsLocation)
		{
			Parent->Destroy();
		}
	}
};
