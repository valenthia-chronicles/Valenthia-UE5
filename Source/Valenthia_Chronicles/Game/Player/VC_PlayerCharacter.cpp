// MIT License - Copyright (c) 2024 Valenthia Chronicles

#include "VC_PlayerCharacter.h"


// Sets default values
AVC_PlayerCharacter::AVC_PlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AVC_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVC_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
