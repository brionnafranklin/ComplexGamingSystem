// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIMovementController.generated.h"

/**
 * 
 */
UCLASS()
class COMPLEXGAMINGSYSTEM_API AAIMovementController : public AAIController
{
	GENERATED_BODY()

public:

	//set radius, offset, and jitter
	float m_radius = 500.0f;
	float m_offset = 0.0f;
	float m_jitter = 100.0f;
	//set previous target to be 0
	FVector m_prevTarget = { 0.0f, 0.0f, 0.0f };

	UFUNCTION(BlueprintCallable)
		void TestFunction();

	//Calculte new direction
	FVector CalculateRandomVector(float z);
	FVector Wander(FVector CurrentLocation);
	void LookForNeededRescource(AActor* owner);
	void Pathfind(AActor* owner, AActor* target);
};
