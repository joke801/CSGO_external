#pragma once
#include "CommonIncludes.hpp"
#include "Entity.hpp"
#include <cmath>

class Aimlock {
private:

protected:

	void ClampAngles(vec3_t& Vectors);
	void NormalizeVector(vec3_t& vec);


public:
	bool EntityIsVisible(EntityPlayer ent);

	bool WeaponIsPistol();
	bool WeaponIsSniper();

};
extern Aimlock cAimlock;

