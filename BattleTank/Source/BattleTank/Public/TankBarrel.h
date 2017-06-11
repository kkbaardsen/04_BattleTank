// 13th_Panic Copyright 2017

#pragma once

#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS()
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);
	
private:

};
