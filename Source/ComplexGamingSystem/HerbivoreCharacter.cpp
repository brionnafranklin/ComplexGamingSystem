// Fill out your copyright notice in the Description page of Project Settings.

#include "HerbivoreCharacter.h"
#include "Engine.h"

void AHerbivoreCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->IsA(APlant::StaticClass()) && CheckIfHungry())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		Controller->MoveToLocation(OtherActor->GetActorLocation());
		GetWorld()->DestroyActor(OtherActor);
		Controller->Wander();
	}
}

void AHerbivoreCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->IsA(APlant::StaticClass()) && CheckIfHungry())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
	}
}

/// Sets default values
AHerbivoreCharacter::AHerbivoreCharacter()
{
 	/// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/// declare trigger capsule
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(300.0f, 100.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	/// declare overlap events
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AHerbivoreCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AHerbivoreCharacter::OnOverlapEnd);

	AIControllerClass = AAIMovementController::StaticClass();
}

/// Called when the game starts or when spawned
void AHerbivoreCharacter::BeginPlay()
{
	Super::BeginPlay();
}

/// Called every frame
void AHerbivoreCharacter::Tick(float DeltaTime)
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

/// Called to bind functionality to input
void AHerbivoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/// Checks to see if current hunger is below the the threshold of hungry
bool AHerbivoreCharacter::CheckIfHungry()
{
	return currentHunger <= hungry;
}

/// returns true if food is in range
bool AHerbivoreCharacter::CheckIfObjectfIsInRange(float range, FVector foodPos)
{
	return (FVector::Distance(GetActorLocation(), foodPos) <= range);
}

