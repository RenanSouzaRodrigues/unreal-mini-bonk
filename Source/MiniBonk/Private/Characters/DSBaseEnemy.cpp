// Made by Dallai Studios - 2025


#include "Characters/DSBaseEnemy.h"


// Sets default values
ADSBaseEnemy::ADSBaseEnemy() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSBaseEnemy::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ADSBaseEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADSBaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

