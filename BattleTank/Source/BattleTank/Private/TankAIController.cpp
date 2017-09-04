// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		//Aim towards player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
		//Fire projectile at player TODO
		//AimingComponent->Fire();
	}
}
