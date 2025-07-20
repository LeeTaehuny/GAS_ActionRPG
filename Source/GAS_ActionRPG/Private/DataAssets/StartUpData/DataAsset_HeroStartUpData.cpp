// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ARGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UARAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);

	for (const FARHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		// DynamicAbilityTag를 통해 InputTag를 추가하고, 추후 이를 사용해 특정 Ability 검색
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASC->GiveAbility(AbilitySpec);
	}
}
