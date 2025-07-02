// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UARGameplayAbility;
class UARAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UARAbilitySystemComponent* InASC, int32 ApplyLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUp")
	TArray<TSubclassOf<UARGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUp")
	TArray<TSubclassOf<UARGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UARGameplayAbility>>& InAbilitiesToGive, UARAbilitySystemComponent* InASC, int32 ApplyLevel = 1);
};
