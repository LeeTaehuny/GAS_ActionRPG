// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ARGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UARAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	check(InASC);

	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UARGameplayAbility>>& InAbilitiesToGive, UARAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<UARGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		// GAS에 Ability 등록하는 방법
		// * Spec 생성 후 Ability, SourceObject, Level 설정 (기본)
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASC->GiveAbility(AbilitySpec);
	}
}