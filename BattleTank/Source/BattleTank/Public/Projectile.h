// 13th_Panic Copyright 2017

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed);
		
private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};
