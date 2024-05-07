// MIT License - Copyright (c) 2024 Valenthia Chronicles

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "VC_PlayerCharacter.h"


// Sets default values
AVC_PlayerCharacter::AVC_PlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetupPlayerCamera();
	
	/// Don't rotate the player to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	/// Configure the player movement
	GetCharacterMovement()->bConstrainToPlane = true;								// Constrain movement to plane
	GetCharacterMovement()->bSnapToPlaneAtStart = true;								// Snap the player to plane at start
	GetCharacterMovement()->bOrientRotationToMovement = true;						// Character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);			// Rotation rate for the character
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


void AVC_PlayerCharacter::SetupPlayerCamera()
{
	// Create the spring arm component
	_playerSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_playerSpringArm->SetupAttachment(RootComponent);
	
	// Create the camera component
	_playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_playerCamera->SetupAttachment(_playerSpringArm, USpringArmComponent::SocketName);

	// Configure the spring arm
	_playerSpringArm->TargetArmLength = 900.f;									// Set the arm's length
	_playerSpringArm->bDoCollisionTest = false;									// Don't want to pull camera in when it collides with level
	_playerSpringArm->SetUsingAbsoluteRotation(true);							// Don't want arm to rotate when character does
	_playerSpringArm->SetRelativeRotation(FRotator(-50.f, 0.f, 0.f));			// Set the arm's default rotation

	_playerSpringArm->bUsePawnControlRotation = false;
}


