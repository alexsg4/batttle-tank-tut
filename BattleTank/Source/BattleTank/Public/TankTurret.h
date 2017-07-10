// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

private:

	//TODO Figure out setup parameters
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 25.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotation = 180.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinRotation = 0.f;

public:
	void Rotate(float);
	
};
