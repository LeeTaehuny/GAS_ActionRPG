// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/ARPawnCombatComponent.h"
#include "ARHeroCombatComponent.generated.h"

class AARHeroWeapon;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARHeroCombatComponent : public UARPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AARHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};
