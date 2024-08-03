// MIT License - Copyright (c) 2024 Valenthia Chronicles

#pragma once

#include "CoreMinimal.h"
#include "Valenthia_Chronicles/Game/Unit/VC_UnitCharacter.h"
#include "VC_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS(Abstract, Blueprintable)
class VALENTHIA_CHRONICLES_API AVC_PlayerCharacter : public AVC_UnitCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVC_PlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool IsJumping() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Configure the player camera
	void SetupPlayerCamera();
	
private:
	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> _playerCamera;

	// Spring arm component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> _playerSpringArm;
};
