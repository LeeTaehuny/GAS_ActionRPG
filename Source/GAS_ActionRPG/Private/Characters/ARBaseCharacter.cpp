// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARBaseCharacter.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/ARAttributeSet.h"


AARBaseCharacter::AARBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 데칼이 캐릭터 메쉬에 적용되지 않도록 설정
	GetMesh()->bReceivesDecals = false;

	ASC = CreateDefaultSubobject<UARAbilitySystemComponent>(TEXT("ASC"));
	AS = CreateDefaultSubobject<UARAttributeSet>(TEXT("AS"));
}

UAbilitySystemComponent* AARBaseCharacter::GetAbilitySystemComponent() const
{
	return GetASC();
}

void AARBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ASC)
	{
		ASC->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}
