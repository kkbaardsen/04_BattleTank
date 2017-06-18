// 13th_Panic Copyright 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
* TankBarrel defines the minimum, maximum and firing pitch speed as well as moving within those parameters.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 45;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = -5;
};
