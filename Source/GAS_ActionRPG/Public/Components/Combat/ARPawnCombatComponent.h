// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ARExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "ARPawnCombatComponent.generated.h"

class AARWeaponBase;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARPawnCombatComponent : public UARExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AARWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AARWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AARWeaponBase* GetCharacterEquippedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, AARWeaponBase*> CharacterCarriedWeaponMap;
};
