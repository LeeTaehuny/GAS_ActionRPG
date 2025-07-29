// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "ARStructTypes.generated.h"

class UARHeroLinkedAnimLayer;
class UInputMappingContext;
class UARHeroGameplayAbility;

USTRUCT(BlueprintType)
struct FARHeroAbilitySet
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARHeroGameplayAbility> AbilityToGrant;

public:
	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FARHeroWeaponData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FARHeroAbilitySet> DefaultWeaponAbilities;
};