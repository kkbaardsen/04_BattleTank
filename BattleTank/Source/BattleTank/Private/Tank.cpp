// 13th_Panic Copyright 2017

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "BattleTank.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);	
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel){ return; }
	auto BarrelRotation = Barrel->GetComponentRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *BarrelRotation);
	auto Projectile = GetWorld()->SpawnActor<AProjectile>
		(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
		);
	Projectile->LaunchProjectile(LaunchSpeed);
}
