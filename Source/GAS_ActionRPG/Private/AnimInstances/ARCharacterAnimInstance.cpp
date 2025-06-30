// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ARCharacterAnimInstance.h"
#include "Characters/ARBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UARCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AARBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UARCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
}