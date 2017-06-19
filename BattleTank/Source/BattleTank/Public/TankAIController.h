// 13th_Panic Copyright 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//forward declarations
class UTankAimingComponent;

/*
 * Responsible for helping the AI aim
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	//How close can the AI can get to the player before firing
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

	UFUNCTION()
	void OnPossessedTankDeath();

private:
	void Tick(float DeltaTime) override;

	void SetPawn(APawn* InPawn) override;	
};
