// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSPlayerCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;

UCLASS()
class MINIBONK_API ADSPlayerCharacter : public ACharacter {
	GENERATED_BODY()

	// =====================================================================================
	// ACTOR COMPONENTS
	// =====================================================================================
protected:
	UPROPERTY(EditAnywhere, Category="Actor Components")
	TObjectPtr<UStaticMeshComponent> PlayerBody;

	UPROPERTY(EditAnywhere, Category="Actor Componets")
	TObjectPtr<USpringArmComponent> PlayerCameraSpring;
	
	UPROPERTY(EditAnywhere, Category="Actor Components")
	TObjectPtr<UCameraComponent> PlayerCamera;


	// =====================================================================================
	// UNREAL LIFECYCLE
	// =====================================================================================
public:
	ADSPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	
	// =====================================================================================
	// PLAYER MOVEMENT
	// =====================================================================================
protected:
	UPROPERTY(EditAnywhere, Category="Player Inputs")
	TObjectPtr<UInputMappingContext> PlayerInputMappingContext;

	UPROPERTY(EditAnywhere, Category="Player Inputs")
	TObjectPtr<UInputAction> MoveInputAction;
	
	UPROPERTY(EditAnywhere, Category="Player Inputs")
	TObjectPtr<UInputAction> LookInputAction;
	
	UPROPERTY(EditAnywhere, Category="Player Inputs")
	TObjectPtr<UInputAction> JumpInputAction;
	
protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartJump(const FInputActionValue& Value);
};
