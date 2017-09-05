// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//forward declaration
class UTankAimingComponent;

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

protected:
	//How close can the AI tank get to the player in cm
	UPROPERTY(EditDefaultsOnly, Category = "Setup") //TODO consider EditDefaultsOnly
	float AcceptanceRadius = 9000;	

};
