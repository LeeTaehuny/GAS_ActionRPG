// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ARFunctionLibrary.generated.h"

UENUM()
enum class EActionRPGConfirmType : uint8
{
	Yes,
	No,
};

class UARAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// C++
	static UARAbilitySystemComponent* NativeGetASCFromActor(AActor* InActor);

	// C++ & BP
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	// C++
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	// BP
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EActionRPGConfirmType& OutConfirmType);
};
