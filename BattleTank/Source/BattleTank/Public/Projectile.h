// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

//forward declaration
class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* LaunchBlast = nullptr;
};
