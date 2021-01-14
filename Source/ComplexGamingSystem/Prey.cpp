// Fill out your copyright notice in the Description page of Project Settings.


#include "Prey.h"

// Sets default values
APrey::APrey()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//attach a mesh component
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	AIMovement = CreateDefaultSubobject<UAIMovementComponent>("AIMovement");
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

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	FVector NewVelocity = GetVelocity();
	FVector NewSpeed = NewVelocity / DeltaTime;

	//Get force in a random direction
	//call wander
	Mesh->AddForce(AIMovement->Wander(NewLocation, NewVelocity, NewSpeed, DeltaTime));

}

// Called to bind functionality to input
void APrey::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

