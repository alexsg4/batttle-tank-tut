// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();

	FMath::Clamp<float>(Throttle, -1.f, 1.f);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //cast to simpler component in order to add force at location

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
