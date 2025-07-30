// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AREnemyGameplayAbility.h"
#include "Characters/AREnemyCharacter.h"
#include "Components/Combat/AREnemyCombatComponent.h"

AAREnemyCharacter* UAREnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (CachedEnemyCharacter.IsValid())
	{
		CachedEnemyCharacter =  Cast<AAREnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UAREnemyCombatComponent* UAREnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}