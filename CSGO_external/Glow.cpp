#include "Glow.hpp"
#include "Features.hpp"
#include "Offsets.hpp"
#include "Memory.hpp"


Glow cGlow;

void Glow::tGlow() {

	if (cFeatures.GetCvarValueFast(eVars::playerglowonkey) == 0||GetAsyncKeyState((int)cFeatures.GetCvarValueFast(eVars::playerglowonkey)) & 0x8000) {

		glow_obj_manager_t glowObj = mem.Read<glow_obj_manager_t>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwGlowObjectManager);

		for (int c = 0; c < glowObj.m_count; ++c) {

			GlowObjectDefinition_r entglowr = mem.Read<GlowObjectDefinition_r>((DWORD)glowObj.m_objects_ptr + 0x38 * c);

			GlowObjectDefinition_w entglow;
			entglow.bFullBloom = entglowr.bFullBloom;
			entglow.vGlowColor = entglowr.vGlowColor;
			entglow.cUnk = entglowr.cUnk;
			entglow.flUnk = entglowr.flUnk;
			entglow.flBloomAmount = entglowr.flBloomAmount;
			entglow.flUnk1 = entglowr.flUnk1;
			entglow.bRenderWhenOccluded = entglowr.bRenderWhenOccluded;
			entglow.bRenderWhenUnoccluded = entglowr.bRenderWhenUnoccluded;
			entglow.bFullBloom = entglowr.bFullBloom;
			entglow.cUnk1 = entglowr.cUnk1;
			entglow.nFullBloomStencilTestValue = entglowr.nFullBloomStencilTestValue;
			entglow.nGlowStyle = entglowr.nGlowStyle;
			entglow.nSplitScreenSlot = entglowr.nSplitScreenSlot;
			entglow.nNextFreeSlot = entglowr.nNextFreeSlot;

			EntityPlayer cEntity;
			cEntity .entityBase= entglowr.pEntity;

			if (!cEntity.entityBase) {
				continue;
			}


			if (cEntity.b_EntityDormant()) {

				continue;

			}
			int entHealth;

			switch (cEntity.i_EntityClassID()) {
			case offsets::ClassIDs::CCSPlayer:

				if (!cFeatures.GetCvarValueFast(eVars::playerglowenable))
					continue;

				if (cEntity.b_TeamCheck())
					continue;

				if (cFeatures.GetCvarValueFast(eVars::playerglowhealth)) {
					entHealth = cEntity.i_EntityHealth();
					if (entHealth <= 0)
						continue;

					entglow.vGlowColor.r = 1.f - entHealth / 100.f;
					entglow.vGlowColor.g = entHealth / 100.f;
					entglow.vGlowColor.b = 0.f;
				}
				else {
					entglow.vGlowColor.r = cFeatures.GetCvarValueFast(eVars::playerglowcolorr) / 255.f;
					entglow.vGlowColor.g = cFeatures.GetCvarValueFast(eVars::playerglowcolorg) / 255.f;
					entglow.vGlowColor.b = cFeatures.GetCvarValueFast(eVars::playerglowcolorb) / 255.f;
				}

				if (cEntity.i_EntityTeam() == 3) {

					if (cEntity.b_IsDefusing()) {

						if (cEntity.b_HasKit()) {
							entglow.vGlowColor.r = 0.f;
							entglow.vGlowColor.g = 1.f;
							entglow.vGlowColor.b = 1.f;
						}
						else {
							entglow.vGlowColor.r = 0.f;
							entglow.vGlowColor.g = 0.f;
							entglow.vGlowColor.b = 1.f;
						}
					}
				}

				entglow.flGlowAlpha = cFeatures.GetCvarValueFast(eVars::playerglowalpha)/255.f;


				break;
			case offsets::ClassIDs::CAK47:
			case offsets::ClassIDs::CWeaponAWP:
			case offsets::ClassIDs::CWeaponAug:
			case offsets::ClassIDs::CWeaponBaseItem:
			case offsets::ClassIDs::CWeaponBizon:
			case offsets::ClassIDs::CWeaponCSBase:
			case offsets::ClassIDs::CWeaponCSBaseGun:
			case offsets::ClassIDs::CWeaponCycler:
			case offsets::ClassIDs::CWeaponElite:
			case offsets::ClassIDs::CWeaponFamas:
			case offsets::ClassIDs::CWeaponG3SG1:
			case offsets::ClassIDs::CWeaponFiveSeven:
			case offsets::ClassIDs::CWeaponGalil:
			case offsets::ClassIDs::CWeaponGalilAR:
			case offsets::ClassIDs::CWeaponGlock:
			case offsets::ClassIDs::CWeaponHKP2000:
			case offsets::ClassIDs::CWeaponM249:
			case offsets::ClassIDs::CWeaponM3:
			case offsets::ClassIDs::CWeaponM4A1:
			case offsets::ClassIDs::CWeaponMAC10:
			case offsets::ClassIDs::CWeaponMag7:
			case offsets::ClassIDs::CWeaponMP5Navy:
			case offsets::ClassIDs::CWeaponMP7:
			case offsets::ClassIDs::CWeaponMP9:
			case offsets::ClassIDs::CWeaponNegev:
			case offsets::ClassIDs::CWeaponNOVA:
			case offsets::ClassIDs::CWeaponP250:
			case offsets::ClassIDs::CWeaponP90:
			case offsets::ClassIDs::CWeaponSawedoff:
			case offsets::ClassIDs::CWeaponSCAR20:
			case offsets::ClassIDs::CWeaponScout:
			case offsets::ClassIDs::CDEagle:
			case offsets::ClassIDs::CWeaponUMP45:
			case offsets::ClassIDs::CWeaponUSP:
			case offsets::ClassIDs::CWeaponXM1014:
			case offsets::ClassIDs::CWeaponSG550:
			case offsets::ClassIDs::CWeaponSG552:
			case offsets::ClassIDs::CWeaponSG556:
			case offsets::ClassIDs::CWeaponSSG08:
				if (!cFeatures.GetCvarValueFast(eVars::weaponglowenable))
					continue;
				entglow.vGlowColor.r = cFeatures.GetCvarValueFast(eVars::weaponglowcolorr) / 255.f;
				entglow.vGlowColor.g = cFeatures.GetCvarValueFast(eVars::weaponglowcolorg) / 255.f;
				entglow.vGlowColor.b = cFeatures.GetCvarValueFast(eVars::weaponglowcolorb) / 255.f;
				entglow.flGlowAlpha = 1.f;
				break;
				//THROWN STUFF
			case offsets::ClassIDs::CBaseCSGrenadeProjectile:
			case offsets::ClassIDs::CDecoyProjectile:
			case offsets::ClassIDs::CMolotovProjectile:
			case offsets::ClassIDs::CSensorGrenadeProjectile:
			case offsets::ClassIDs::CSmokeGrenadeProjectile:
			case offsets::ClassIDs::CBumpMineProjectile:
			case offsets::ClassIDs::CBreachChargeProjectile:
				if (!cFeatures.GetCvarValueFast(eVars::grenadeglowenable))
					continue;
				entglow.vGlowColor.r = cFeatures.GetCvarValueFast(eVars::grenadeglowthrowncolorr) / 255.f;
				entglow.vGlowColor.g = cFeatures.GetCvarValueFast(eVars::grenadeglowthrowncolorg) / 255.f;
				entglow.vGlowColor.b = cFeatures.GetCvarValueFast(eVars::grenadeglowthrowncolorb) / 255.f;
				entglow.flGlowAlpha = 1.f;
				break;

				//DROPPEDSHIT
			case offsets::ClassIDs::CHEGrenade:
			case offsets::ClassIDs::CSmokeGrenade:
			case offsets::ClassIDs::CIncendiaryGrenade:
			case offsets::ClassIDs::CDecoyGrenade:
			case offsets::ClassIDs::CMolotovGrenade:
			case offsets::ClassIDs::CSensorGrenade:
			case offsets::ClassIDs::CFlashbang:
			case offsets::ClassIDs::CBumpMine:
				if (!cFeatures.GetCvarValueFast(eVars::grenadeglowenable))
					continue;
				entglow.vGlowColor.r = cFeatures.GetCvarValueFast(eVars::grenadeglowdroppedcolorr) / 255.f;
				entglow.vGlowColor.g = cFeatures.GetCvarValueFast(eVars::grenadeglowdroppedcolorg) / 255.f;
				entglow.vGlowColor.b = cFeatures.GetCvarValueFast(eVars::grenadeglowdroppedcolorb) / 255.f;
				entglow.flGlowAlpha = 1.f;
				break;
			default:
				continue;
			}

			entglow.bRenderWhenOccluded = true;
			entglow.bRenderWhenUnoccluded = false;
			entglow.nGlowStyle = 0;




			mem.Write<GlowObjectDefinition_w>(glowObj.m_objects_ptr + 0x38 * c +0x4, entglow);
		}
	}
}