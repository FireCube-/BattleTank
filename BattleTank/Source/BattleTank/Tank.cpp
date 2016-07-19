// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	if (!InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Null InputComponent referenced in method SetupPlayerInputComponent!"));
		return;
	}
	InputComponent->BindAxis("RotateTurret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("ElevateBarrel", this, &ATank::ElevateBarrel);
}

void ATank::SetTurretChildActor(UStaticMeshComponent* TurretFromBP)
{
	if (!TurretFromBP)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method SetTurretChildActor"));
		return;
	}
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP)
{
	if (!BarrelFromBP)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method SetBarrelChildActor"));
		return;
	}
	Barrel = BarrelFromBP;
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method RotateTurret"));
		return;
	}
	Turret->AddRelativeRotation(FRotator(0.f, Speed, 0.f));
}

void ATank::ElevateBarrel(float Speed)
{
	if (!Turret)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ElevateBarrel"));
		return;
	}
	Barrel->AddRelativeRotation(FRotator(Speed, 0.f, 0.f));
}
