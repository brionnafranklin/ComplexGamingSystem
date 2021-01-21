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

	//Controller->Wander();
	if (Controller->CheckTargetInRange(600))
	{
		Controller->OnReachedDesination.Broadcast();
	}
}

// Called to bind functionality to input
void AHerbivoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

