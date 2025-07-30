// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AREnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/AREnemyCombatComponent.h"

AAREnemyCharacter::AAREnemyCharacter()
{
	// 배치 or 시작과 동시에 빙의 시작
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// 컨트롤 방향 회전 비활성화
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	// 회전 관련 설정
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 180.0f, 0.0f);

	// 이동속도 관련 설정
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.0f;

	EnemyCombatComponent = CreateDefaultSubobject<UAREnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}
