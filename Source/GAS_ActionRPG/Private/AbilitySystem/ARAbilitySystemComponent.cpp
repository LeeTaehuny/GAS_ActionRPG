// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ARAbilitySystemComponent.h"

void UARAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	// 활성화 가능한 모든 어빌리티 목록을 확인합니다.
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		// DynamicAbilityTags에 InInputTag와 일치하는 항목이 없다면 건너뛰기
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		// 해당 Ability를 활성화합니다.
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UARAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
