// 13th_Panic Copyright 2017

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO move towards the player

		//aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//fire when ready
		ControlledTank->Fire(); //TODO Limit FireRate
	}	
}
