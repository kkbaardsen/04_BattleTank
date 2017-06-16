// 13th_Panic Copyright 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
* TankTrack is used to set maximum driving force, and to apply forces to the tank.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//set a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle) const;
	
	//max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Input Control")
	float TrackMaxDrivingForce = 20000000; 
};
