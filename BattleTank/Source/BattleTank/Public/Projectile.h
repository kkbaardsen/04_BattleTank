// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

//forward declaration
class UProjectileMovementComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

protected:
	void BeginPlay() override;

public:	
	void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed) const;
		
private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};
