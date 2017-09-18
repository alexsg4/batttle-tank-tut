// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//forward declaration
class UTankAimingComponent;
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPosessedTankDeath();

protected:
	//How close can the AI tank get to the player in cm
	UPROPERTY(EditDefaultsOnly, Category = "Setup") //TODO consider EditDefaultsOnly
	float AcceptanceRadius = 9000;	

};
