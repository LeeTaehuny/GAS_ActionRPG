// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AREnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/AREnemyCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "Engine/AssetManager.h"

#include "ARDebugHelper.h"

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

void AAREnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartUpData();
}

void AAREnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartUpData.IsNull()) return;

	// 애셋 매니저의 GetStreamableManager().RequestAsyncLoad() 함수는 비동기 로드 함수
	// * 매개변수 : SoftObjectPath, Callback Delegate(로딩이 완료되면 호출)
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(ASC);

					Debug::Print(TEXT("Enemy StartUpData Loaded"), FColor::Green);
				}
			}
		)
	);
}