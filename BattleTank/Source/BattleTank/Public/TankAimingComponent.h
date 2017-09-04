// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//enums
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

//hold Barrel and Turret properties and their movement methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	//virtual void Tick(float DeltaTime) override; TODO

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitialiseAim(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void AimAt(FVector);

	void MoveBarrelTowards(FVector);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	bool isReloaded = true;
	float ReloadTimeSeconds = 3;
	double LastFireTime = 0;

};
