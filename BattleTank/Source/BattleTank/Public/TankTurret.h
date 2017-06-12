// 13th_Panic Copyright 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max right speed, and +1 is max left movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 25;
};
