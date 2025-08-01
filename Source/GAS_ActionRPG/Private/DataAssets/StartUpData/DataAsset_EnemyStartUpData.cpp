// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Abilities/AREnemyGameplayAbility.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UARAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UAREnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec Spec(AbilityClass);
			Spec.SourceObject = InASC->GetAvatarActor();
			Spec.Level = ApplyLevel;

			InASC->GiveAbility(Spec);
		}
	}
}
