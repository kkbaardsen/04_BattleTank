// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
		
public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
	
private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup Firing")
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup Firing")
	float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; //TODO REMOVE

	double LastFireTime = 0;
};
