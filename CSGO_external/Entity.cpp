#include "Entity.hpp"
#include "Memory.hpp"
#include "Offsets.hpp"


LocalPlayer cLocalPlayer;


int EntityPlayer::i_EntityClassID() {
	return mem.Read<int>(mem.Read<int>(mem.Read<int>(mem.Read<int>(entityBase + 0x8) + 0x8) + 0x1) + 0x14);
}

vec3_t EntityPlayer::vec3_Bone_position(int bone) {
	vec3_t vec3_Temp = {0};
	const auto temp = mem.Read<DWORD>(entityBase + Offsets.NVARS.m_dwBoneMatrix);

	cBoneMatrix3x4 = mem.Read<boneMatrix3x4>(temp + (0x30 * bone));
	vec3_Temp.x = cBoneMatrix3x4.matrix[0][3];
	vec3_Temp.y = cBoneMatrix3x4.matrix[1][3];
	vec3_Temp.z = cBoneMatrix3x4.matrix[2][3];
	return vec3_Temp;
}

int EntityPlayer::i_EntityHealth() {
	return mem.Read<int>(entityBase + Offsets.NVARS.m_iHealth);
}

int EntityPlayer::i_EntityTeam() {
	return mem.Read<int>(entityBase + Offsets.NVARS.m_iTeamNum);
}

bool EntityPlayer::b_EntityDormant() {
	return mem.Read<bool>(entityBase + Offsets.SIGS.m_bDormant);
}


//RETURNS TRUE IF ON THE SAME TEAM
bool EntityPlayer::b_TeamCheck() {

	DWORD dGameRules = mem.Read<DWORD>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwGameRulesProxy);

	bool bIsDangerZone = (mem.Read<DWORD>(dGameRules + Offsets.NVARS.m_SurvivalGameRuleDecisionTypes));

	int entTeam = mem.Read<int>(entityBase + Offsets.NVARS.m_iTeamNum);

	if (!bIsDangerZone) {
		return (entTeam == cLocalPlayer.Team);
	}
	else {
		return false;
	}
}

int EntityPlayer::i_GlowIndex() {
	return mem.Read<int>(entityBase + Offsets.NVARS.m_iGlowIndex);
}

bool EntityPlayer::b_IsDefusing() {
	return mem.Read<bool>(entityBase + Offsets.NVARS.m_bIsDefusing);
}

bool EntityPlayer::b_HasKit() {
	return mem.Read<bool>(entityBase + Offsets.NVARS.m_bHasDefuser);
}
	
bool EntityPlayer::b_HasGunGameImmunity() {
	return mem.Read<bool>(entityBase + Offsets.NVARS.m_bGunGameImmunity);
}