// MIT License - Copyright (c) 2024 Valenthia Chronicles

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VC_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS(Abstract, Blueprintable)
class VALENTHIA_CHRONICLES_API AVC_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AVC_PlayerController();
	
	// Default Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	// List of every input action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> LeftClickAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> RightClickAction;

	// List of every handling events
	UFUNCTION(BlueprintCallable)
	void HandleLeftClickEvent();
	UFUNCTION(BlueprintCallable)
	void HandleRightClickEvent();
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
private:
	// Input Events
	void Move(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
};
