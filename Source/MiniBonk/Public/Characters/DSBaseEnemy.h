// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSBaseEnemy.generated.h"

UCLASS()
class MINIBONK_API ADSBaseEnemy : public ACharacter {
	GENERATED_BODY()

	// ===================================================================
	// ACTOR COMPONENTS
	// ===================================================================
	UPROPERTY(EditAnywhere, Category="Actor Components")
	TObjectPtr<UStaticMeshComponent> EnemyBody;

	
	// ===================================================================
	// UNREAL LIFECYCLE METHODS
	// ===================================================================
public:
	ADSBaseEnemy();

protected:
	virtual void BeginPlay() override;
};
