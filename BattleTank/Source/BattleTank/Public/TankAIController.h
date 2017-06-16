// 13th_Panic Copyright 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//forward declarations
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

private:
	void Tick(float DeltaTime) override;

	//How close can the AI can get to the player before firing
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 10000;

};
