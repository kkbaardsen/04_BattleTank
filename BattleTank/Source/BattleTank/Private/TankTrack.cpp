// 13th_Panic Copyright 2017

#include "TankTrack.h"
#include "BattleTank.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UE_LOG(LogTemp, Warning, TEXT("Ticking"));

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	//Work-out the required acceleration thir frame to correct
	auto CorrectingAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	
	//Calculate and apply sideways (F = m*a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectingAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle) const
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
