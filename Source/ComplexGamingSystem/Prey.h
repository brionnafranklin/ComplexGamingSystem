// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIMovementController.h"
#include "Prey.generated.h"

UCLASS()
class COMPLEXGAMINGSYSTEM_API APrey : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APrey();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
