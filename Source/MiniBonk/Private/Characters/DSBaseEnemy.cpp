// Made by Dallai Studios - 2025

#include "Characters/DSBaseEnemy.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Macros/DSMacros.h"

// ===================================================================
// UNREAL LIFECYCLE METHODS
// ===================================================================
ADSBaseEnemy::ADSBaseEnemy() {
	PrimaryActorTick.bCanEverTick = true;

	this->EnemyBody = this->CreateDefaultSubobject<UStaticMeshComponent>("Enemy Body");
	this->EnemyBody->SetupAttachment(this->GetCapsuleComponent());
	this->EnemyBody->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void ADSBaseEnemy::BeginPlay() {
	Super::BeginPlay();

	this->GetArrowComponent()->SetHiddenInGame(false);
	this->GetArrowComponent()->SetVisibility(true);
	
	this->EnemyBody->SetRelativeLocation(this->EnemyBodyStartLocation);

	if (!this->AnimationCurve) {
		DS_LOG_ERROR("Base Enemy Error: the animation curve is invalid");
		return;
	}
	
	FOnTimelineFloat timelineUpdateEvent;
	timelineUpdateEvent.BindUFunction(this, FName("AnimateEnemyUpdate"));

	FOnTimelineEvent timelineFinishEvent;
	timelineFinishEvent.BindUFunction(this, FName("AnimateEnemyFinish"));
	
	this->SpawnTimeline.AddInterpFloat(this->AnimationCurve, timelineUpdateEvent);
	this->SpawnTimeline.SetTimelineFinishedFunc(timelineFinishEvent);
	this->SpawnTimeline.PlayFromStart();
}

void ADSBaseEnemy::Tick(const float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	this->SpawnTimeline.TickTimeline(DeltaSeconds);
}


// ===================================================================
// SPAWN ANIMATION
// ===================================================================
void ADSBaseEnemy::AnimateEnemyUpdate(const float Value) {
	const auto newLocation = FMath::Lerp(this->EnemyBodyStartLocation, this->EnemyBodyDefaultLocation, Value);
	this->EnemyBody->SetRelativeLocation(newLocation);
}

void ADSBaseEnemy::AnimateEnemyFinish() {
	this->EnemyBody->SetRelativeLocation(this->EnemyBodyDefaultLocation);
}
