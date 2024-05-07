// MIT License - Copyright (c) 2024 Valenthia Chronicles

#include "VC_UnitCharacter.h"


// Sets default values
AVC_UnitCharacter::AVC_UnitCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AVC_UnitCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVC_UnitCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}