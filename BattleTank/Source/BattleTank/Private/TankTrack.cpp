// 13th_Panic Copyright 2017

#include "TankTrack.h"
#include "BattleTank.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Has Fired at %f"), *Name, Throttle);

	//TODO clamp actual throttle value so player can't over-drive
}
