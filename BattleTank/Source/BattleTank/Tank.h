// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	virtual void BeginPlay() override;	
	virtual void Tick( float DeltaSeconds ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetTurretChildActor(UStaticMeshComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP);

private:
	UStaticMeshComponent* Turret = nullptr;
	UStaticMeshComponent* Barrel = nullptr;

	void RotateTurret(float Speed);
	void ElevateBarrel(float Speed);
};
