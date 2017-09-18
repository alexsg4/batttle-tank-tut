// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h" //so we can implement OnDeath

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
		
		//Fire projectile at player
		if(AimingComponent->GetFiringState()==EFiringState::Locked)
		{ 
			AimingComponent->Fire(); //TODO limit firing rate
		}
	}
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PosessedTank = Cast<ATank>(InPawn);
		if (!ensure(PosessedTank)) { return; }
		
		PosessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPosessedTankDeath);
	}
}

void ATankAIController::OnPosessedTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
}
