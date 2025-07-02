// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class GAS_ACTIONRPG_API AARWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AARWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() { return WeaponCollisionBox; } 
};
