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

	//set radius, offset, and jitter
	float m_radius = 600.0f;
	float m_offset = 1.0f;
	float m_jitter = 1.0f;
	//set previous target to be 0
	FVector m_prevTarget = { 0.0f, 0.0f, 0.0f };
	AActor* Owner;

	FVector targetPos = { 0.0f, 0.0f, 0.0f };

	UFUNCTION(BlueprintCallable)
		void TestFunction();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Calculte new direction
	FVector CalculateRandomVector( float z );

	UFUNCTION(BlueprintCallable)
		void Wander();

	void LookForNeededRescource(AActor* owner);

	bool CheckTargetInRange(float range);

	UPROPERTY(BlueprintAssignable, Category = "AIMovement")
		FReachedDesination OnReachedDesination;
};
