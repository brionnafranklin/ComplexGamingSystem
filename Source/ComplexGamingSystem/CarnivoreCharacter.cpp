// Fill out your copyright notice in the Description page of Project Settings.

#include "CarnivoreCharacter.h"
#include "Engine.h"

/// Determinds how the character behaves when overlapping with another hitbox
void ACarnivoreCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->IsA(AHerbivoreCharacter::StaticClass()) && CheckIfHungry())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Overlap Begin"));
		Controller->MoveToLocation(OtherActor->GetActorLocation());
		GetWorld()->DestroyActor(OtherActor);
		Controller->Wander();
	}
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->IsA(ACarnivoreCharacter::StaticClass()))
	{
		FVector SpawnLocation = (GetActorLocation() + OtherActor->GetActorLocation()) / 2;
		FRotator SpawnRotation = (GetActorRotation());
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ACarnivoreCharacter>(SpawnLocation, SpawnRotation, SpawnParams);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Overlap Begin"));
	}
}

/// Determinds how the character behaves when no longer overlapping with another hitbox
void ACarnivoreCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->IsA(AHerbivoreCharacter::StaticClass()) && CheckIfHungry())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Overlap End"));
	}
}

// Sets default values
ACarnivoreCharacter::ACarnivoreCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/// declare trigger capsule
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(300.0f, 100.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	/// declare overlap events
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACarnivoreCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ACarnivoreCharacter::OnOverlapEnd);

	AIControllerClass = AAIMovementController::StaticClass();
}

// Called when the game starts or when spawned
void ACarnivoreCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarnivoreCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Controller = CastChecked<AAIMovementController>(GetController());

	if (!Controller)
	{
		return;
	}

	if (Controller->CheckTargetInRange(300))
	{
		Controller->OnReachedDesination.Broadcast();
	}
	/// Slowly decrease current hunger
	currentHunger--;
}

// Called to bind functionality to input
void ACarnivoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/// Checks to t see if current hunger is belong the the threshold of hungry
bool ACarnivoreCharacter::CheckIfHungry()
{
	return currentHunger <= hungry;
}

/// returns true if food is in range
bool ACarnivoreCharacter::CheckIfObjectfIsInRange(float range, FVector foodPos)
{
	return (FVector::Distance(GetActorLocation(), foodPos) <= range);
}

