#include "Skinchanger.hpp"
#include "Memory.hpp"
#include "Offsets.hpp"
#include "Features.hpp"
#include "Entity.hpp"

Skinchanger cSkinchanger;



void Skinchanger::doSkinchanger() {

	if (!cFeatures.GetCvarValueFast(eVars::skinchangerenable))
		return;

	if (cLocalPlayer.health <= 0)
		return;

	for (int i = 0; i < 8; i++)
	{
		DWORD currentWeapon = mem.Read<DWORD>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_hMyWeapons + i * 0x4) & 0xfff;
		currentWeapon = mem.Read<DWORD>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwEntityList + (currentWeapon - 1) * 0x10);
		if (currentWeapon == 0) { continue; }

		short weaponID = mem.Read<short>(currentWeapon + Offsets.NVARS.m_iItemDefinitionIndex);

		DWORD fallbackPaint = 0;

		switch (weaponID) {
		case offsets::ItemSchemaIndex_e::WEAPON_GLOCK:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerglock18);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_USPS:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerusps);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_P2000:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerp2000);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_P250:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerp250);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_FIVE7:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerfiveseven);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_CZ75:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangercz75auto);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_TEC9:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangertec9);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_DUALS:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerdualberettas);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_DEAGLE:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerdeserteagle);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_R8REVOLVER:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerr8revolver);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_MAG7:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangermag7);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_NOVA:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangernova);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_SAWEDOFF:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangersawedoff);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_XM1014:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerxm1014);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_M249:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerm249);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_NEGEV:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangernegev);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_MAC10:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangermac10);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_MP5SD:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangermp5sd);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_MP7:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangermp7);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_MP9:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangermp9);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_BIZON:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerppbizon);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_UMP45:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerump45);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_P90:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerp90);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_AK47:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerak47);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_AUG:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangeraug);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_FAMAS:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerfamas);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_GALIL:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangergalilar);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_M4A1S:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerm4a1s);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_M4A4:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerm4a4);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_SG553:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangersg553);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_AWP:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerawp);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_G3SG1:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerg3sg1);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_SCAR20:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerscar20);
			break;
		case offsets::ItemSchemaIndex_e::WEAPON_SCOUT:
			fallbackPaint = (DWORD)cFeatures.GetCvarValueFast(eVars::skinchangerssg08);
			break;
		default:
			continue;
		}

		mem.Write<int>(currentWeapon + Offsets.NVARS.m_iItemIDHigh, -1);
		mem.Write<DWORD>(currentWeapon + Offsets.NVARS.m_nFallbackPaintKit, fallbackPaint);
		mem.Write<float>(currentWeapon + Offsets.NVARS.m_flFallbackWear, 0.0001f);
	}
}

void Skinchanger::ForceFullUpdate() {
	DWORD dwClientState = mem.Read<DWORD>((DWORD)Offsets.SDK.iEngineBaseAddress.modBaseAddr + Offsets.SIGS.dwClientState);
	mem.Write<int>(dwClientState + 0x174, -1);
}