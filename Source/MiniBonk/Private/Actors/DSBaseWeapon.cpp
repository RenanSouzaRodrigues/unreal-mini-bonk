// Made by Dallai Studios - 2025


#include "Actors/DSBaseWeapon.h"


// Sets default values
ADSBaseWeapon::ADSBaseWeapon() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSBaseWeapon::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ADSBaseWeapon::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

