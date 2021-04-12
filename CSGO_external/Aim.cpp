#include "Aim.hpp"
#include "Features.hpp"
#include "Offsets.hpp"
#include "Memory.hpp"


Aimlock cAimlock;

void Aimlock::ClampAngles(vec3_t& Vectors) {
	if (Vectors.x > 89.f)
		Vectors.x = 89.f;
	if (Vectors.x < -89.f)
		Vectors.x = -89.f;
	if (Vectors.y > 180.f)
		Vectors.y = 180.f;
	if (Vectors.y < -180.f)
		Vectors.y = -180.f;

	Vectors.z = 0.f;
}
void Aimlock::NormalizeVector(vec3_t& vec) {
	while (vec.x > 180.f)
		vec.x -= 360.f;

	while (vec.x < -180.f)
		vec.x += 360.f;
	while (vec.y > 180.f)
		vec.y -= 360.f;
	while (vec.y < -180.f)
		vec.y += 360.f;
	vec.z = 0.f;
}

bool Aimlock::EntityIsVisible(EntityPlayer ent) {





}

bool Aimlock::WeaponIsPistol() {

	switch (cLocalPlayer.ActiveWeaponID) {
	case offsets::ItemSchemaIndex_e::WEAPON_TEC9:
	case offsets::ItemSchemaIndex_e::WEAPON_USPS:
	case offsets::ItemSchemaIndex_e::WEAPON_CZ75:
	case offsets::ItemSchemaIndex_e::WEAPON_GLOCK:
	case offsets::ItemSchemaIndex_e::WEAPON_DEAGLE:
	case offsets::ItemSchemaIndex_e::WEAPON_FIVE7:
	case offsets::ItemSchemaIndex_e::WEAPON_DUALS:
	case offsets::ItemSchemaIndex_e::WEAPON_R8REVOLVER:

		return true;
	default:
		return false;
	}

}
bool Aimlock::WeaponIsSniper() {


	switch (cLocalPlayer.ActiveWeaponID) {
	case offsets::ItemSchemaIndex_e::WEAPON_AWP:
	case offsets::ItemSchemaIndex_e::WEAPON_SCAR20:
	case offsets::ItemSchemaIndex_e::WEAPON_SCOUT:
	case offsets::ItemSchemaIndex_e::WEAPON_G3SG1:
	
		return true;
	default:
		return false;
	}
}