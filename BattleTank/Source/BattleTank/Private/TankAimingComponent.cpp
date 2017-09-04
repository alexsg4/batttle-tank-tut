// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

/* TODO
void UTankAimingComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Reload state must be checked every Tick in order to update FiringState
	isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeSeconds;
	if (!isReloaded) { FiringState = EFiringState::Reloading; }
	else { FiringState = EFiringState::Aiming; }
} */

void UTankAimingComponent::InitialiseAim(UTankTurret * TurretToSet, UTankBarrel * BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		FiringState = EFiringState::Locked;
	}

	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No aim solution."));
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);	
	Turret->Rotate(DeltaRotator.Yaw);

}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && ProjectileBlueprint)) { return; }
	
	//TODO remove after adding back TICK
	isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeSeconds;
	
	if (isReloaded)
	{
		//spawn projectile at the socket location of the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->Launch(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
