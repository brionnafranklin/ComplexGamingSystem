// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HungerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPLEXGAMINGSYSTEM_API UHungerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHungerComponent();

	// Decreases over time and refils after eating
	float currentHunger = 100.0f;
	// The max hunger can be at any given time
	float maxHunger = 100.0f;
	// How low the hunger must be until food can be consumed
	float hungry = 75.0f;
	// wether or not this actor can eat
	bool isHungry = false;
	// wether or not this actor has consumed food
	bool eaten = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CheckIfHungry();
	void CheckIfEaten();
};