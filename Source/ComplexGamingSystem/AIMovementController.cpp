// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementController.h"
#include "NavigationSystem.h"
#include "Engine.h"

void AAIMovementController::TestFunction()
{
	MoveToLocation(FVector(0,0,0));
}

void AAIMovementController::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetPawn();

	OnReachedDesination.AddDynamic(this, &AAIMovementController::Wander);
	
	targetPos = Owner->GetActorLocation();
}

FVector AAIMovementController::CalculateRandomVector()
{
	/*float randX = (float)rand() - ((float)RAND_MAX) / 2;
	float randY = (float)rand() - ((float)RAND_MAX) / 2;
	return FVector{ randX, randY, z };*/
	FVector RandomLocation = FVector();
	UNavigationSystem::K2_GetRandomReachablePointInRadius(Owner, Owner->GetActorLocation(), RandomLocation, m_radius);
	return RandomLocation;
}

void AAIMovementController::Wander()
{
	//Start with a random target on the edge of a circle with a set radius around the agent
	targetPos = CalculateRandomVector().GetSafeNormal() * m_radius;
	//Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos *= m_jitter;
	//Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.GetSafeNormal() * m_radius;
	targetPos *= m_offset;
	//Add the previous target
	targetPos += m_prevTarget;

	GEngine->AddOnScreenDebugMessage(-1, 500.0f, FColor::Blue, targetPos.ToString());

	MoveToLocation(targetPos);
	return;
}

void AAIMovementController::LookForNeededRescource(AActor* owner)
{
}

bool AAIMovementController::CheckTargetInRange(float range)
{
	return (FVector::Distance(Owner->GetActorLocation(), targetPos) <= range);
}
