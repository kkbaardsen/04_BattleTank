// 13th_Panic Copyright 2017

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

//forward declaration
class UTankTrack;

/*
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	//TODO Check best protection
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw) const;

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw) const;

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnLeft(float Throw) const;

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveBackward(float Throw) const;

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
