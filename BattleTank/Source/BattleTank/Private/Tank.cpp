// 13th_Panic Copyright 2017

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "BattleTank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

//uses the Aims at HitLocation
void ATank::AimAt(FVector HitLocation) const
{
	if(!TankAimingComponent){return;}
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);	
}

//fires projectile
void ATank::Fire()
{
	auto isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded)
	{
		//TODO Remove commented log when barrel movement is fixed
		//auto BarrelRotation = Barrel->GetComponentRotation().ToString();
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *BarrelRotation);
		
		//spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
