// Made by Dallai Studios - 2025

#include "MiniBonk/Public/Characters/DSPlayerCharacter.h"

// =====================================================================================
// UNREAL LIFECYCLE
// =====================================================================================
ADSPlayerCharacter::ADSPlayerCharacter() {
	this->PrimaryActorTick.bCanEverTick = true;
	this->PlayerBody = this->CreateDefaultSubobject<UStaticMeshComponent>("Player Body");
}