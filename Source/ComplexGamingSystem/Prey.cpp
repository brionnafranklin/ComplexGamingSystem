// Fill out your copyright notice in the Description page of Project Settings.


#include "Prey.h"

// Sets default values
APrey::APrey()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APrey::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APrey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FRotator CurrentRotation = GetActorRotation();
	FVector CurrentVelocity = GetVelocity();
	FVector CurrentSpeed = CurrentVelocity / DeltaTime;

	AAIMovementController* Controller = CastChecked<AAIMovementController>(GetController());
	if (!Controller)
	{
		return;
	}

	//FVector TestForce(100.00f, 0.00f, 0.00f);

	//FVector ChangedLocation(600, NewLocation.Y, NewLocation.Z);

	//Get force in a random direction
	//call wander
	//Mesh->AddForce(AIMovement->Wander(NewLocation, NewVelocity, NewSpeed, DeltaTime));
	//AddMovementInput(AIMovement->Wander(NewLocation, NewVelocity, NewSpeed, DeltaTime));
	//ConsumeMovementInputVector();
	//SetActorLocation(ChangedLocation);
	//AddForce(TestForce);
	SetActorLocation(Controller->Wander(CurrentLocation));
}

// Called to bind functionality to input
void APrey::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

