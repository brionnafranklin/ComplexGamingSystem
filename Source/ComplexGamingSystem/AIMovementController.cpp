// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementController.h"
#include "NavigationSystem.h"
#include "Engine.h"

/// Called when the game starts or when spawned
void AAIMovementController::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetPawn();

	OnReachedDesination.AddDynamic(this, &AAIMovementController::Wander);
	
	targetPos = Owner->GetActorLocation();
}

/// Calculte new random location
FVector AAIMovementController::CalculateRandomVector( float z )
{
	float randX = (float)rand() - ((float)RAND_MAX) / 2;
	float randY = (float)rand() - ((float)RAND_MAX) / 2;
	return FVector{ randX, randY, z };
}

/// Moves to a random location
void AAIMovementController::Wander()
{
	/// Start with a random target on the edge of a circle with a set radius around the agent
	targetPos = CalculateRandomVector(Owner->GetActorLocation().Z).GetSafeNormal() * m_radius;
	/// Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos *= m_jitter;
	/// Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.GetSafeNormal() * m_radius;
	targetPos *= m_offset;
	/// Add the previous target
	targetPos += m_prevTarget;

	GEngine->AddOnScreenDebugMessage(-1, 500.0f, FColor::Blue, targetPos.ToString());

	MoveToLocation(targetPos);
	return;
}

/// Checks to see if target position in within a given range
bool AAIMovementController::CheckTargetInRange(float range)
{
	return (FVector::Distance(Owner->GetActorLocation(), targetPos) <= range);
}
