// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward declaration
class UTankAimingComponent;

/**
 * Responsible for helping the player aim. (and more)
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAim(UTankAimingComponent* AimingCompRef);

private:
	void BeginPlay() override;

	void Tick(float DeltaTime) override;
	
	bool GetLookDirection(FVector2D, FVector&) const;

	bool GetLookVectorHitLocation(FVector, FVector&) const;

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	//Start moving the barrel 
	//so that a shot would hit 
	//where the crosshair intersects the world 
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
	

};
