// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIMovementController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReachedDesination);

UCLASS()
class COMPLEXGAMINGSYSTEM_API AAIMovementController : public AAIController
{
	GENERATED_BODY()

public:

	/// set radius  
	float m_radius = 600.0f;
	/// set offset
	float m_offset = 1.0f;
	/// set jitter
	float m_jitter = 1.0f;
	/// set previous target to be 0
	FVector m_prevTarget = { 0.0f, 0.0f, 0.0f };
	/// The owner of this controller
	AActor* Owner;
	/// The random posistion generated
	FVector targetPos = { 0.0f, 0.0f, 0.0f };

	/// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/// Calculte new random location
	FVector CalculateRandomVector( float z );

	/// Moves to a random location
	UFUNCTION(BlueprintCallable)
		void Wander();

	/// Checks to see if target position in within a given range
	bool CheckTargetInRange(float range);

	/// An event that is broadcast when Character has reached the targetPos. On this event Wander is called
	UPROPERTY(BlueprintAssignable, Category = "AIMovement")
		FReachedDesination OnReachedDesination;
};
