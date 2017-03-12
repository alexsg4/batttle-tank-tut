// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	//Log AI controlled tanks
	if (!GetAIControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("There is no AI posessed tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI posessed tank is: %s"), *GetAIControlledTank()->GetName());
	}

	//Log AI got player tank
	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController could not get player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController got player tank: %s"),*GetPlayerTank()->GetName());
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetControlledPawn());
}
