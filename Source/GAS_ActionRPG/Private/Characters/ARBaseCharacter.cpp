// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARBaseCharacter.h"

AARBaseCharacter::AARBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 데칼이 캐릭터 메쉬에 적용되지 않도록 설정
	GetMesh()->bReceivesDecals = false;
}
