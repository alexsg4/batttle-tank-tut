// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel;
class UTankTurret;

//hold Barrel and Turret properties and their movement methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel*);

	void SetTurretReference(UTankTurret*);

	void AimAt(FVector, float);

	void MoveBarrelTowards(FVector);


private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

};
