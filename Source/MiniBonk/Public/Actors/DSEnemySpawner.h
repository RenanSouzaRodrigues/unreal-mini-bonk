// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DSEnemySpawner.generated.h"

class ADSBaseEnemy;

UCLASS()
class MINIBONK_API ADSEnemySpawner : public AActor {
	GENERATED_BODY()

	
	// ===================================================================
	// ACTOR PROPERTIES
	// ===================================================================
protected:
	UPROPERTY(EditAnywhere, Category="Actor Properties")
	TSubclassOf<ADSBaseEnemy> EnemyToSpawn;

	UPROPERTY(EditAnywhere, Category="Actor Properties")
	float TimeToWaitBeforeSpawn { 2.f };

	
	// ===================================================================
	// UNREAL LIFECYCLE METHODS
	// ===================================================================
public:
	ADSEnemySpawner();

protected:
	virtual void BeginPlay() override;

	
	// ===================================================================
	// SPAWN ENEMY
	// ===================================================================
private:
	UFUNCTION()
	void SpawnNewEnemy();
};
