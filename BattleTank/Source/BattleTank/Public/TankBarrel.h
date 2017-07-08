// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories=("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 35.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.f;

public:
	//-1 is max downward movement and +1 is max upward movement
	void Elevate(float);
	
	
};
