// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//forward declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	void BeginPlay() override;
	
	void Tick(float DeltaTime) override;

	ATank* GetAIControlledTank() const;

	ATank* GetPlayerTank() const;
	
};
