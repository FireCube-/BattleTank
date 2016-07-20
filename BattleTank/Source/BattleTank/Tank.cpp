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
	InputComponent->BindAxis("MoveTank", this, &ATank::MoveTank);
	InputComponent->BindAxis("RotateTank", this, &ATank::RotateTank);
}

void ATank::SetTurretChildActor(UStaticMeshComponent* TurretFromBP)
{
	if (!TurretFromBP)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::SetTurretChildActor"));
		return;
	}
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP)
{
	if (!BarrelFromBP)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::SetBarrelChildActor"));
		return;
	}
	Barrel = BarrelFromBP;
}

void ATank::SetTankChildActor(UStaticMeshComponent* TankFromBP)
{
	if (!TankFromBP)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::SetTankChildActor"));
		return;
	}
	Tank = TankFromBP;
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::RotateTurret"));
		return;
	}
	float Rotation = GetWorld()->DeltaTimeSeconds * TurretRotationSpeed *  Speed;
	Turret->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}

void ATank::ElevateBarrel(float Speed)
{
	if (!Turret)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::ElevateBarrel"));
		return;
	}
	float Rotation = GetWorld()->DeltaTimeSeconds * TankRotationSpeed *  Speed;
	float PitchRotated = Barrel->GetComponentRotation().Pitch + Rotation;
	if (PitchRotated <= MaximumElevationDegree && PitchRotated >= MinimumElevationDegree)
		Barrel->AddRelativeRotation(FRotator(Rotation, 0.f, 0.f));
}

void ATank::MoveTank(float Speed)
{
	if (!Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::MoveTank"));
		return;
	}
	float Location = GetWorld()->DeltaTimeSeconds * TankMovementSpeed * Speed * -1.f;
	Tank->AddRelativeLocation(Tank->GetForwardVector() * Location);
}

void ATank::RotateTank(float Speed)
{
	if (!Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("Null UStaticMeshComponent referenced in method ATank::RotateTank"));
		return;
	}
	float Rotation = GetWorld()->DeltaTimeSeconds * TankRotationSpeed *  Speed;
	Tank->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}