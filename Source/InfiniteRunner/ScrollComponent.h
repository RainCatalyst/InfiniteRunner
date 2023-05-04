#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScrollComponent.generated.h"

class AInfiniteRunnerGameMode;

/** Moves the owner with the level **/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INFINITERUNNER_API UScrollComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScrollComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	AInfiniteRunnerGameMode* GameMode;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
