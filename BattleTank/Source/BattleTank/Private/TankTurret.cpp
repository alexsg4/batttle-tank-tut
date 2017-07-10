// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

//TODO
void UTankTurret::Rotate(float RelativeSpeed)
{
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = FMath::Clamp<float>(RelativeRotation.Yaw + RotationChange, MinRotation, MaxRotation);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}



