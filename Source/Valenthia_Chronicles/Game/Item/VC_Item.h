// MIT License - Copyright (c) 2024 Valenthia Chronicles

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VC_Item.generated.h"

UCLASS()
class VALENTHIA_CHRONICLES_API AVC_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVC_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
