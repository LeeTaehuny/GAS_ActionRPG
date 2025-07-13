// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ARGameplayAbility.h"
#include "ARHeroGameplayAbility.generated.h"

class AARHeroCharacter;
class AARHeroController;
class UARHeroCombatComponent;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARHeroGameplayAbility : public UARGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Ability")
	AARHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ability")
	AARHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ability")
	UARHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AARHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AARHeroController> CachedHeroController;
};
