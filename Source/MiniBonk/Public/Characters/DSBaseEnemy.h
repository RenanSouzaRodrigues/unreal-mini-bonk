// Made by Dallai Studios - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSBaseEnemy.generated.h"

UCLASS()
class MINIBONK_API ADSBaseEnemy : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADSBaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
