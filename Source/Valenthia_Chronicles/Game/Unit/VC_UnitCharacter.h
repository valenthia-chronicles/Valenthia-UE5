// MIT License - Copyright (c) 2024 Valenthia Chronicles

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VC_UnitCharacter.generated.h"


UCLASS(Abstract, Blueprintable)
class VALENTHIA_CHRONICLES_API AVC_UnitCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVC_UnitCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
