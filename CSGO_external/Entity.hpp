#pragma once
#include "CommonIncludes.hpp"


struct LocalPlayer {
	DWORD localPlayerBase;
	int Team;
	int flags;
	int health;

	int ActiveWeaponID;
	int clipAmmo;
	float Accuracy;
};
extern LocalPlayer cLocalPlayer;


class EntityPlayer {
private:
	struct boneMatrix3x4 {
		float matrix[3][4];
	}cBoneMatrix3x4 = { 0 };


public:
	unsigned int entityBase = NULL;


	int i_EntityHealth();
	int i_EntityClassID();
	int i_GlowIndex();
	int i_EntityTeam();
	
	bool b_EntityDormant();
	bool b_IsDefusing();
	bool b_HasKit();
	bool b_TeamCheck();
	bool b_HasGunGameImmunity();

	vec3_t vec3_Bone_position(int bone);
};



