// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
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
	// ACTOR PROPERTIES
	// ===================================================================
	UPROPERTY(EditAnywhere, Category="Actor Properties")
	FVector EnemyBodyStartLocation { FVector(0, 0, -200.f) };

	UPROPERTY(EditAnywhere, Category="Actor Properties")
	TObjectPtr<UCurveFloat> AnimationCurve;
	
private:
	FTimeline SpawnTimeline;
	FVector EnemyBodyDefaultLocation { FVector(0,0,0) } ;


	
	// ===================================================================
	// UNREAL LIFECYCLE METHODS
	// ===================================================================
public:
	ADSBaseEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(const float DeltaSeconds) override;

	
	// ===================================================================
	// SPAWN ANIMATION
	// ===================================================================
private:
	UFUNCTION()
	void AnimateEnemyUpdate(const float Value);

	UFUNCTION()
	void AnimateEnemyFinish();
};
