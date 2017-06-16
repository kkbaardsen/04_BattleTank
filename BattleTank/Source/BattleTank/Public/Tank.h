// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	void Fire();

	void AimAt(FVector HitLocation) const;
	
private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup Firing")
	float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; //TODO REMOVE

	double LastFireTime = 0;
};
