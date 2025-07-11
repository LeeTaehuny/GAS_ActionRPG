﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ARGameplayAbility.generated.h"

class UARPawnCombatComponent;

UENUM(BlueprintType)
enum class EARAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven,
};

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "ARAbility")
	EARAbilityActivationPolicy AbilityActivationPolicy = EARAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Ability")
	UARPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;
};
