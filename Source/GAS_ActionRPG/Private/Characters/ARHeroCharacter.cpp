// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARHeroCharacter.h"

// Debug
#include "ARDebugHelper.h"

void AARHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
