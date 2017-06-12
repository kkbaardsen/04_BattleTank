// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward declarations
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

private:
	ATank * GetControlledTank() const;

	void Tick(float DeltaTime) override;
		
	void AimTowardsCrosshair();

	//Crosshair locations corresponding to UI TODO link to UI
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
