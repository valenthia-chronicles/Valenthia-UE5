// MIT License - Copyright (c) 2024 Valenthia Chronicles

#include "VC_StatComponent.h"


// Sets default values for this component's properties
UVC_StatComponent::UVC_StatComponent() : MaxHealth(100), MaxPower(100), Level(1)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	// You can turn these feature off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UVC_StatComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Power = MaxPower;
}

void UVC_StatComponent::SetLevel(const uint8 NewLevel)
{
	Level = NewLevel;
}

void UVC_StatComponent::UpdateCurrentHealth(const int32 Amount)
{
	// Use FMath::Clamp to ensure the new health value is between 0 and MaxHealth
	Health = FMath::Clamp((Health + Amount), 0, MaxHealth);
}

void UVC_StatComponent::UpdateCurrentPower(const int32 Amount)
{
	// Use FMath::Clamp to ensure the new power value is between 0 and MaxPower
	Power = FMath::Clamp((Power + Amount), 0, MaxPower);
}


