// 13th_Panic Copyright 2017

#pragma once

#include "Engine.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

};
