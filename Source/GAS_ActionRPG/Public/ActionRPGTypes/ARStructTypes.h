// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ARStructTypes.generated.h"

class UARHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FARHeroWeaponData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};