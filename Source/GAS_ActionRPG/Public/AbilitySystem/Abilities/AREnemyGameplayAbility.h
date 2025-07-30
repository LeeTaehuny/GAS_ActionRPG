// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ARGameplayAbility.h"
#include "AREnemyGameplayAbility.generated.h"

class AAREnemyCharacter;
class UAREnemyCombatComponent;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UAREnemyGameplayAbility : public UARGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AAREnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UAREnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AAREnemyCharacter> CachedEnemyCharacter;
};
