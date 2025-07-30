// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ARBaseCharacter.h"
#include "AREnemyCharacter.generated.h"

class UAREnemyCombatComponent;

/**
 * 
 */
UCLASS()
class GAS_ACTIONRPG_API AAREnemyCharacter : public AARBaseCharacter
{
	GENERATED_BODY()
	
public:
	AAREnemyCharacter();

public:
	FORCEINLINE UAREnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UAREnemyCombatComponent* EnemyCombatComponent;
};
