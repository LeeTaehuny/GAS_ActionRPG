// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/ARWeaponBase.h"
#include "ActionRPGTypes/ARStructTypes.h"
#include "ARHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API AARHeroWeapon : public AARWeaponBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FARHeroWeaponData HeroWeaponData;
};
