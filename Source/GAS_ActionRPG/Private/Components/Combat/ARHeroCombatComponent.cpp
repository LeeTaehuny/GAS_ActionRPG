// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/ARHeroCombatComponent.h"
#include "Items/Weapons/ARHeroWeapon.h"

AARHeroWeapon* UARHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AARHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
