// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Plant.generated.h"

UCLASS()
class COMPLEXGAMINGSYSTEM_API APlant : public AActor
{
	GENERATED_BODY()
	
	/// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	class UCapsuleComponent* TriggerCapsule;

	/// create mesh
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class UStaticMesh* Mesh;

public:	
	/// Sets default values for this actor's properties
	APlant();

protected:
	/// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/// Called every frame
	virtual void Tick(float DeltaTime) override;

};
