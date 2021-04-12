#pragma once
#include "CommonIncludes.hpp"
#include "Entity.hpp"
class Radar {
private:
	bool toggledOff;

public:	
	void doRadar(EntityPlayer&);

};
extern Radar cRadar;