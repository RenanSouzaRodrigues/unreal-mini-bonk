// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSPlayerCharacter.generated.h"

UCLASS()
class MINIBONK_API ADSPlayerCharacter : public ACharacter {
	GENERATED_BODY()

	// =====================================================================================
	// ACTOR COMPONENTS
	// =====================================================================================
protected:
	UPROPERTY(EditAnywhere, Category="Actor Components")
	TObjectPtr<UStaticMeshComponent> PlayerBody;


	// =====================================================================================
	// UNREAL LIFECYCLE
	// =====================================================================================
public:
	ADSPlayerCharacter();
};
