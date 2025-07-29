// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionRPGTypes/ARStructTypes.h"
#include "AbilitySystem/Abilities/ARHeroGameplayAbility.h"

bool FARHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}