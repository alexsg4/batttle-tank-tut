// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

//Basic logging for player controller
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("There is no posessed tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Posessed tank is: %s"), *GetControlledTank()->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//AimAtCrosshair
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
