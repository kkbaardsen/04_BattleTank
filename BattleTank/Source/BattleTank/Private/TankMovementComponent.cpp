// 13th_Panic Copyright 2017

#include "TankMovementComponent.h"
#include "BattleTank.h"


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f:Intend move FORWARD: %f"),Time, Throw);
}
