// MIT License - Copyright (c) 2024 Valenthia Chronicles

#include "VC_PlayerController.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"


AVC_PlayerController::AVC_PlayerController() { }

void AVC_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	bEnableClickEvents = true;
	
	// Recover Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AVC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind each input action to a function
	if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AVC_PlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AVC_PlayerController::Jump);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVC_PlayerController::Move);
	} 
}


void AVC_PlayerController::Move(const FInputActionValue& Value)
{
	if (GetCharacter() != nullptr)
	{
		const FVector2D MovementVector = Value.Get<FVector2D>();
		
		// Find out which way is forward
		const FRotator Rotation = GetCharacter()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Add movement direction
		GetCharacter()->AddMovementInput(ForwardDirection, MovementVector.Y);
		GetCharacter()->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AVC_PlayerController::Jump(const FInputActionValue& Value)
{
	if (GetCharacter() != nullptr)
	{
		GetCharacter()->Jump();
	}
}


