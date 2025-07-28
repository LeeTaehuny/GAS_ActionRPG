// Fill out your copyright notice in the Description page of Project Settings.


#include "ARFunctionLibrary.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

UARAbilitySystemComponent* UARFunctionLibrary::NativeGetASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UARAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UARFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UARAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	// 만약 해당 컴포넌트에 TagToAdd 태그가 존재하지 않는 경우 태그를 추가합니다.
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UARFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UARAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	// 만약 해당 컴포넌트에 TagToAdd 태그가 존재하는 경우 태그를 제거합니다.
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UARFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UARAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UARFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EActionRPGConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EActionRPGConfirmType::Yes : EActionRPGConfirmType::No;
}
