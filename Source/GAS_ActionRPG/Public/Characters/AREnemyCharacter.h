// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ARBaseCharacter.h"
#include "AREnemyCharacter.generated.h"

class UAREnemyCombatComponent;
class UDataAsset_EnemyStartUpData;

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
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UAREnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartUpData();
};
