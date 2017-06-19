// 13th_Panic Copyright 2017

#include "Tank.h"
#include "BattleTank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	auto DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	
	CurrentHealth -= DamageToApply;
	if(CurrentHealth <= 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("Player Tank has DIED!!"))
	}

	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

