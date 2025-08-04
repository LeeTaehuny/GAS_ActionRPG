// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ARGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UARAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	check(InASC);

	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);

	// GameplayEffects 적용
	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass) continue;

			// CDO 불러오기
			// * Unreal Engine에서 클래스가 처음 로드될 때 자동으로 생성되는 기본 객체
			// * 인스턴스를 새로 만들지 않고도, 그 클래스의 기본 설정을 참조 가능
			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();

			InASC->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASC->MakeEffectContext());
		}
	}
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