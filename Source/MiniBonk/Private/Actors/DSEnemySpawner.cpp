// Made by Dallai Studios - 2025

#include "Actors/DSEnemySpawner.h"
#include "Characters/DSBaseEnemy.h"
#include "Macros/DSMacros.h"

// ===================================================================
// UNREAL LIFECYCLE METHODS
// ===================================================================
ADSEnemySpawner::ADSEnemySpawner() {
	PrimaryActorTick.bCanEverTick = false;
}

void ADSEnemySpawner::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle enemySpawnTimerHandle;

	FTimerDelegate enemySpawnTimerDelegate;
	enemySpawnTimerDelegate.BindUFunction(this, FName("SpawnNewEnemy"));
	
	this->GetWorld()->GetTimerManager().SetTimer(enemySpawnTimerHandle, enemySpawnTimerDelegate, this->TimeToWaitBeforeSpawn, true);
}


// ===================================================================
// SPAWN ENEMY
// ===================================================================
void ADSEnemySpawner::SpawnNewEnemy() {
	if (!this->EnemyToSpawn) {
		DS_LOG_ERROR("Enemy Spawner error: The enemy to spawn is not defined");
		return;
	}

	FActorSpawnParameters params;
	params.Owner = this;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	const auto spawnLocation = this->GetActorLocation();
	const auto spawnRotation = FRotator::ZeroRotator;
	
	this->GetWorld()->SpawnActor<ADSBaseEnemy>(this->EnemyToSpawn, spawnLocation, spawnRotation, params);
}