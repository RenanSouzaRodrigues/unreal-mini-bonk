// Made by Dallai Studios - 2025

#include "MiniBonk/Public/Characters/DSPlayerCharacter.h"
#include "Macros/DSMacros.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// =====================================================================================
// UNREAL LIFECYCLE
// =====================================================================================
ADSPlayerCharacter::ADSPlayerCharacter() {
	this->PrimaryActorTick.bCanEverTick = true;
	this->PlayerBody = this->CreateDefaultSubobject<UStaticMeshComponent>("Player Body");
	this->PlayerBody->SetupAttachment(this->GetRootComponent());
	this->PlayerBody->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

	this->PlayerCameraSpring = this->CreateDefaultSubobject<USpringArmComponent>("Player Camera Spring Arm");
	this->PlayerCameraSpring->SetupAttachment(this->GetRootComponent());
	
	this->PlayerCamera = this->CreateDefaultSubobject<UCameraComponent>("Player Camera");
	this->PlayerCamera->SetupAttachment(this->PlayerCameraSpring);
	this->PlayerCamera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
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
}


// =====================================================================================
// PLAYER MOVEMENT
// =====================================================================================
void ADSPlayerCharacter::Move(const FInputActionValue& Value) {
	const FVector2D movementValue = Value.Get<FVector2D>();
	this->AddMovementInput(this->GetActorForwardVector(), movementValue.X);
	this->AddMovementInput(this->GetActorRightVector(), movementValue.Y);
}