// Fill out your copyright notice in the Description page of Project Settings.


#include "HerbivoreCharacter.h"

// Sets default values
AHerbivoreCharacter::AHerbivoreCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHerbivoreCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHerbivoreCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AAIMovementController* Controller = CastChecked<AAIMovementController>(GetController());

	if (!Controller)
	{
		return;
	}

	if (Controller->CheckTargetInRange(300))
	{
		Controller->OnReachedDesination.Broadcast();
	}

	if (CheckIfHungry())
	{

	}
	// Slowly decrease current hunger
	currentHunger--;
}

// Called to bind functionality to input
void AHerbivoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AHerbivoreCharacter::CheckIfHungry()
{
	return currentHunger <= hungry;
}

