// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIMovementController.h"
#include "Plant.h"
#include "HerbivoreCharacter.generated.h"

UCLASS()
class COMPLEXGAMINGSYSTEM_API AHerbivoreCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHerbivoreCharacter();

	// Decreases over time and refils after eating
	float currentHunger = 100.0f;
	// The max hunger can be at any given time
	float maxHunger = 100.0f;
	// How low the hunger must be until food can be consumed
	float hungry = 75.0f;
	// The type of actor that is going to be eaten
	APlant* Food;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Checks to t see if current hunger is belong the the threshold of hungry
	bool CheckIfHungry();
};
