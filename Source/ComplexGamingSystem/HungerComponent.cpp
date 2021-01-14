// Fill out your copyright notice in the Description page of Project Settings.


#include "HungerComponent.h"

// Sets default values for this component's properties
UHungerComponent::UHungerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHungerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHungerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Slowly decrease current hunger
	currentHunger--;

	CheckIfEaten();
	CheckIfHungry();
	// ...
}

void UHungerComponent::CheckIfHungry()
{
	if (currentHunger <= hungry)
	{
		isHungry = true;
	}
}

void UHungerComponent::CheckIfEaten()
{
	if (eaten = true)
	{
		currentHunger = maxHunger;
	}
}
