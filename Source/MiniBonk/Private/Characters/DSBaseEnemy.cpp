// Made by Dallai Studios - 2025

#include "Characters/DSBaseEnemy.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"

// ===================================================================
// UNREAL LIFECYCLE METHODS
// ===================================================================
ADSBaseEnemy::ADSBaseEnemy() {
	PrimaryActorTick.bCanEverTick = false;

	this->EnemyBody = this->CreateDefaultSubobject<UStaticMeshComponent>("Enemy Body");
	this->EnemyBody->SetupAttachment(this->GetCapsuleComponent());
	this->EnemyBody->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void ADSBaseEnemy::BeginPlay() {
	Super::BeginPlay();

	this->GetArrowComponent()->SetHiddenInGame(false);
	this->GetArrowComponent()->SetVisibility(true);
}