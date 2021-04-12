#pragma once
#include "CommonIncludes.hpp"
#include "Aim.hpp"

class Standalonerecoil : Aimlock {
private:

	float humanizeDir;
	float humanizeCur;


	bool bDoRecoil();


public:

	void DoRecoil();


};
extern Standalonerecoil cStandalonerecoil;