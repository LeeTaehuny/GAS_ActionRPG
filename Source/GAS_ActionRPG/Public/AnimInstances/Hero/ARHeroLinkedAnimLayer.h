// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ARBaseAnimInstance.h"
#include "ARHeroLinkedAnimLayer.generated.h"

class UARHeroAnimInstance;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API UARHeroLinkedAnimLayer : public UARBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UARHeroAnimInstance* GetHeroAnimInstance() const;
};
