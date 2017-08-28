// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 25.f;

public:
	void Rotate(float);
	
};
