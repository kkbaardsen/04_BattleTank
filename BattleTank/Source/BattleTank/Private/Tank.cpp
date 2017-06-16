// 13th_Panic Copyright 2017

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "BattleTank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

}

//fires projectile
void ATank::Fire()
{
	//TODO
	if(!ensure(Barrel)) { return; }
	auto isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{
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
