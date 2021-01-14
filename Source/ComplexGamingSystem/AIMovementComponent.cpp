// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementComponent.h"

// Sets default values for this component's properties
UAIMovementComponent::UAIMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAIMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAIMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get the Actor to which this component is attached
	AActor* owner = GetOwner();

	//Identify need

	// ...
}

FVector UAIMovementComponent::CalculateRandomVector(float z)
{
	float randX = (float)rand() - ((float)RAND_MAX) / 2;
	float randY = (float)rand() - ((float)RAND_MAX) / 2;
	return FVector{ randX, randY, z };
}

// Move in random direction
FVector UAIMovementComponent::Wander(FVector NewLocation, FVector NewVelocity, FVector NewSpeed, float DeltaTime)
{
	//Start with a random target on the edge of a circle with a set radius around the agent
	FVector targetPos = CalculateRandomVector(NewLocation.Z).GetSafeNormal() * m_radius;
	//Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += CalculateRandomVector(NewLocation.Z).GetSafeNormal() * m_jitter;
	//Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.GetSafeNormal() * m_radius;
	//Add the agent�s heading, multiplied by the distance, to the target
	FVector heading = NewVelocity.GetSafeNormal();
	targetPos += heading * m_offset;
	//Add the previous target
	targetPos += m_prevTarget;

	//Store previous target
	m_prevTarget.X = targetPos.X;
	m_prevTarget.Y = targetPos.Y;
	m_prevTarget.Z = targetPos.Z;

	//Calculate the vector describing the direction to the target and normalize it
	FVector direction = targetPos - NewLocation;
	direction = direction.GetSafeNormal();
	//Multiply the direction by the speed we want the agent to move
	FVector force = direction * NewSpeed;
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - NewVelocity;

	//Return the force
	force = (force * DeltaTime);
	return force;
}

void UAIMovementComponent::LookForNeededRescource(AActor* owner)
{
	// if owner is prey make food plant
	//if (owner = prey)
	//{

	//}
	//// if owner is predator make food prey
	//if (owner.ishunger)
	//{
	//	Pathfind(owner, )
	//}
}

void UAIMovementComponent::Pathfind(AActor* owner, AActor* target)
{

}
