// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementController.h"

void AAIMovementController::TestFunction()
{
	MoveToLocation(FVector(0,0,0));
}

FVector AAIMovementController::CalculateRandomVector(float z)
{
	float randX = (float)rand() - ((float)RAND_MAX) / 2;
	float randY = (float)rand() - ((float)RAND_MAX) / 2;
	return FVector{ randX, randY, z };
}

FVector AAIMovementController::Wander(FVector CurrentLocation)
{
	//Start with a random target on the edge of a circle with a set radius around the agent
	FVector targetPos = CalculateRandomVector(CurrentLocation.Z).GetSafeNormal() * m_radius;
	//Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += CalculateRandomVector(CurrentLocation.Z).GetSafeNormal() * m_jitter;
	//Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.GetSafeNormal() * m_radius;
	targetPos *= m_offset;
	//Add the previous target
	targetPos += m_prevTarget;

	return targetPos;
}

void AAIMovementController::LookForNeededRescource(AActor* owner)
{
}

void AAIMovementController::Pathfind(AActor* owner, AActor* target)
{
}
