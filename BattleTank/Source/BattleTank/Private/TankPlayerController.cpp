// 13th_Panic Copyright 2017

#include "TankPlayerController.h"
#include "BattleTank.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
