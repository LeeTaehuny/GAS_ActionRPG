// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ARBaseCharacter.h"
#include "ARHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API AARHeroCharacter : public AARBaseCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
