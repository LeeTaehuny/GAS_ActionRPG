// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/ARHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/ARHeroAnimInstance.h"

UARHeroAnimInstance* UARHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UARHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
