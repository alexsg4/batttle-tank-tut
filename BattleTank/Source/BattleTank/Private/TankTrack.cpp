// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	auto SplippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	
	//work out required acceleration this frame for correction
	auto CorrectiveAcceleration = -SplippageSpeed / DeltaTime * GetRightVector();

	//calculate and apply sideways force
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent()); //cast to simpler component in order to add force at location
	auto CorrectionForce = TankRoot->GetMass() * CorrectiveAcceleration / 2; //for 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //cast to simpler component in order to add force at location
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
