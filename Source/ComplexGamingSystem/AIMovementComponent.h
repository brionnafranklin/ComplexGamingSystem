// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPLEXGAMINGSYSTEM_API UAIMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAIMovementComponent();

	//set radius, offset, and jitter
	float m_radius = 1000.0f;
	float m_offset = 0.0f;
	float m_jitter = 500.0f;
	//set previous target to be 0
	FVector m_prevTarget = { 0.0f, 0.0f, 0.0f };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Wander(AActor* owner, FVector NewLocation, FVector NewVelocity, float NewSpeed, float DeltaTime);
	void LookForNeededRescource(AActor* owner);
	void Pathfind(AActor* owner, AActor* target);
};
