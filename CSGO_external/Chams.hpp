#pragma once
#include "CommonIncludes.hpp"
#include "Entity.hpp"
class Chams {

	struct chamsColor {
		BYTE r, g, b;
	};
public:
	void doChams(EntityPlayer&);
};
extern Chams cChams;