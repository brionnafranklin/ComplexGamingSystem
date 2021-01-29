// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIMovementController.h"
#include "HerbivoreCharacter.h"
#include "Components/CapsuleComponent.h"
#include "CarnivoreCharacter.generated.h"

UCLASS()
class COMPLEXGAMINGSYSTEM_API ACarnivoreCharacter : public ACharacter
{
	GENERATED_BODY()

	/// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	class UCapsuleComponent* TriggerCapsule;

public:
	/// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Sets default values for this character's properties
	ACarnivoreCharacter();

	/// Decreases over time and refils after eating
	float currentHunger = 100.0f;
	/// The max hunger can be at any given time
	float maxHunger = 100.0f;
	/// How low the hunger must be until food can be consumed
	float hungry = 75.0f;
	/// The AI Controller using this
	AAIMovementController* Controller;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// Checks to t see if current hunger is belong the the threshold of hungry
	bool CheckIfHungry();

	/// returns true if food is in range
	bool CheckIfObjectfIsInRange(float range, FVector foodPos);
};
