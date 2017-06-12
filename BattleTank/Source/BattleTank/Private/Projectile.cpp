// 13th_Panic Copyright 2017

#include "Projectile.h"
#include "BattleTank.h"

AProjectile::AProjectile()
{
 	PrimaryActorTick.bCanEverTick = true;

	//adds projectile movement commponent to be used in unreal
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//used in fire method to launch projectile
void AProjectile::LaunchProjectile(float Speed) const
{
	//TODO LOG WARNING
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Has Fired at %f"), Time, Speed); //TODO remove Output Log
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}
