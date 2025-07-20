// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace ARGameplayTags
{
	/** Input Tags **/
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player Tags **/
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_UnEquip_Axe);

	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	GAS_ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);
}