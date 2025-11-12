// Made by Dallai Studios - 2025

#include "MiniBonk/Public/Characters/DSPlayerCharacter.h"
#include "Macros/DSMacros.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// =====================================================================================
// UNREAL LIFECYCLE
// =====================================================================================
ADSPlayerCharacter::ADSPlayerCharacter() {
	this->PrimaryActorTick.bCanEverTick = true;

	this->GetCapsuleComponent()->SetCapsuleRadius(20.f);
	
	this->PlayerBody = this->CreateDefaultSubobject<UStaticMeshComponent>("Player Body");
	this->PlayerBody->SetupAttachment(this->GetRootComponent());
	this->PlayerBody->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

	this->PlayerCameraSpring = this->CreateDefaultSubobject<USpringArmComponent>("Player Camera Spring Arm");
	this->PlayerCameraSpring->SetupAttachment(this->GetRootComponent());
	this->PlayerCameraSpring->bUsePawnControlRotation = true;
	
	this->PlayerCamera = this->CreateDefaultSubobject<UCameraComponent>("Player Camera");
	this->PlayerCamera->SetupAttachment(this->PlayerCameraSpring);
	this->PlayerCamera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	if (const auto characterMovementComponent = this->GetCharacterMovement()) {
		characterMovementComponent->GravityScale = 1.2f;
		characterMovementComponent->MaxWalkSpeed = 700.f;
		characterMovementComponent->AirControl = 0.1f;
		characterMovementComponent->JumpZVelocity = 700.f;
		characterMovementComponent->SetWalkableFloorAngle(46.f);
	}
}

void ADSPlayerCharacter::BeginPlay() {
	Super::BeginPlay();
}

void ADSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* controller =  this->GetController<APlayerController>();

	if (!controller) {
		DS_LOG_ERROR("Player Character Error: the player controller is invalid");
		return;
	}

	const ULocalPlayer* localPlayer = controller->GetLocalPlayer();

	if (!localPlayer) {
		DS_LOG_ERROR("Player Character Error: The local player reference is invalid");
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* enhancedSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	if (!enhancedSubsystem) {
		DS_LOG_ERROR("Player Character Error: Enhanced input subsystem is invalid");
		return;
	}

	enhancedSubsystem->AddMappingContext(this->PlayerInputMappingContext, 0);

	UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!inputComponent) {
		DS_LOG_ERROR("Player Character Error: Enhanced input component is invalid");
		return;
	}

	// Movement Input Action Binding
	inputComponent->BindAction(this->MoveInputAction, ETriggerEvent::Triggered, this, &ADSPlayerCharacter::Move);

	// Look Input Action Binding
	inputComponent->BindAction(this->LookInputAction, ETriggerEvent::Triggered, this, &ADSPlayerCharacter::Look);

	// Jump Input Action Binding
	inputComponent->BindAction(this->JumpInputAction, ETriggerEvent::Started, this, &ADSPlayerCharacter::StartJump);
}


// =====================================================================================
// PLAYER MOVEMENT
// =====================================================================================
void ADSPlayerCharacter::Move(const FInputActionValue& Value) {
	const FVector2D movementValue = Value.Get<FVector2D>();
	this->AddMovementInput(this->GetActorForwardVector(), movementValue.X);
	this->AddMovementInput(this->GetActorRightVector(), movementValue.Y);
}

void ADSPlayerCharacter::Look(const FInputActionValue& Value) {
	const FVector2D lookValue = Value.Get<FVector2D>();
	this->AddControllerPitchInput(lookValue.Y);
	this->AddControllerYawInput(lookValue.X);
}

void ADSPlayerCharacter::StartJump(const FInputActionValue& Value) {
	this->Jump();
}
