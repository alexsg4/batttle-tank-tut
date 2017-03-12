// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	///Log out AI controlled tanks
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play!"));

	if (!GetAIControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no AI posessed tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI posessed tank is: %s"), *GetAIControlledTank()->GetName());
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



