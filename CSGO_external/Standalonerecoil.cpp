#include "Standalonerecoil.hpp"
#include "Entity.hpp"
#include "Features.hpp"
#include "Memory.hpp"
#include "Offsets.hpp"
#include <cmath>

Standalonerecoil cStandalonerecoil;

bool Standalonerecoil::bDoRecoil() {

	switch (cLocalPlayer.ActiveWeaponID) {
	case offsets::ItemSchemaIndex_e::WEAPON_AK47:
	case offsets::ItemSchemaIndex_e::WEAPON_AUG:
	case offsets::ItemSchemaIndex_e::WEAPON_FAMAS:
	case offsets::ItemSchemaIndex_e::WEAPON_GALIL:
	case offsets::ItemSchemaIndex_e::WEAPON_M249:
	case offsets::ItemSchemaIndex_e::WEAPON_M4A4:
	case offsets::ItemSchemaIndex_e::WEAPON_M4A1S:
	case offsets::ItemSchemaIndex_e::WEAPON_NEGEV:
	case offsets::ItemSchemaIndex_e::WEAPON_SG553:
	case offsets::ItemSchemaIndex_e::WEAPON_MAC10:
	case offsets::ItemSchemaIndex_e::WEAPON_P90:
	case offsets::ItemSchemaIndex_e::WEAPON_UMP45:
	case offsets::ItemSchemaIndex_e::WEAPON_BIZON:
	case offsets::ItemSchemaIndex_e::WEAPON_MP7:
	case offsets::ItemSchemaIndex_e::WEAPON_MP9:
		break;
	default:
		return false;
	}


	if (!cLocalPlayer.clipAmmo)
		return false;
	return true;
}


void Standalonerecoil::DoRecoil(){

	if (!bDoRecoil())
		return;
	int IsFiring = mem.Read<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceAttack);

	static vec3_t vOldPunch;


	if (IsFiring != 5) {
		vOldPunch = { 0,0,0 };
		return;
	}
	else
	{

		DWORD dwClientState = mem.Read<DWORD>((DWORD)Offsets.SDK.iEngineBaseAddress.modBaseAddr + Offsets.SIGS.dwClientState);

		vec3_t vViewAngles = mem.Read<vec3_t>(dwClientState + Offsets.NVARS.dwClientState_ViewAngles);
		vec3_t pLocal_Punch = mem.Read<vec3_t>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_aimPunchAngle);
		float rcssmooth = 5 / 100;
		vec3_t vNewPunch = pLocal_Punch;


		float multiply = (float)std::floor((1.65f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.95 - 1.60)))) / 0.01f + 0.5f) * 0.01f;

		vNewPunch = vec3_t({ vNewPunch.x * 2, vNewPunch.y * 2, vNewPunch.z * 2 });
	
		//vNewPunch = vec3_t({ vNewPunch.x - vOldPunch.x,vNewPunch.y - vOldPunch.y,vNewPunch.z - vOldPunch.z });
		//vNewPunch = vec3_t({ vNewPunch.x * rcssmooth, vNewPunch.y * rcssmooth, vNewPunch.z * rcssmooth });
		//vNewPunch = vec3_t({ vNewPunch.x + vOldPunch.x, vNewPunch.y + vOldPunch.y, vNewPunch.z + vOldPunch.z });


		vec3_t vFinal = vec3_t({ vViewAngles.x - vNewPunch.x + vOldPunch.x,vViewAngles.y - vNewPunch.y + vOldPunch.y ,vViewAngles.z - vNewPunch.z + vOldPunch.z  });

		vec3_t idk = vec3_t({ vFinal.x - vViewAngles.x,vFinal.y - vViewAngles.y ,vFinal.z - vViewAngles.z });

		idk.x *= 0.5;
		idk.y *= 0.67;
		idk.z *= 0;

		idk = vec3_t({ idk.x + vViewAngles.x,idk.y + vViewAngles.y ,idk.z + vViewAngles.z });

		NormalizeVector(idk);
		ClampAngles(idk);


		//mem.Write<vec3_t>(dwClientState + Offsets.NVARS.dwClientState_ViewAngles, idk);

		vOldPunch = vec3_t({ vNewPunch.x ,vNewPunch.y ,vNewPunch.z });
	}
}