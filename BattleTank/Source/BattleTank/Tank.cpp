// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	if (InputComponent)
	{
		InputComponent->BindAction("Turret_Clockwise", EInputEvent::IE_Pressed, this, &ATank::TurretCWRotate);
		InputComponent->BindAction("Turret_CClockwise", EInputEvent::IE_Pressed, this, &ATank::TurretCCWRotate);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Null InputComponent referenced in SetupPlayerInputComponent!"));
	}
}

void ATank::SetTurretChildActor(UStaticMeshComponent* TurretFromBP)
{
	if (TurretFromBP)
	{
		Turret = TurretFromBP;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Turret component not found!"));
	}
}

void ATank::TurretCWRotate()
{
	Turret->AddRelativeRotation(FRotator(0.f, 30.f, 0.f));
}

void ATank::TurretCCWRotate()
{
	Turret->AddRelativeRotation(FRotator(0.f, -30.f, 0.f));
}
