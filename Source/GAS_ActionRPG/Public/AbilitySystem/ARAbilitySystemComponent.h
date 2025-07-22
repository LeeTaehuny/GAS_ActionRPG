// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "ActionRPGTypes/ARStructTypes.h"
#include "ARAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);
	
	UFUNCTION(BlueprintCallable, Category = "Ability", meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FARHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Ability", meta = (ApplyLevel = "1"))
	void RemoveGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);
};
