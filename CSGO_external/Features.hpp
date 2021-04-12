#pragma once
#include "CommonIncludes.hpp"
#include <string>
#include <vector>

enum class eVars {
	aimlockenable,
	aimlockkey,
	aimlockfov,
	aimlockbone,
	aimlockbonealternative,
	aimlocksmoothx,
	aimlocksmoothy,
	aimlockrandomize,
	aimlockrecoil,
	standalonerecoilenable,
	standalonerecoilhumanize,

	triggerbotenable,
	triggerbotkey,
	triggerbothitchance,
	triggerbotrandomdelay,
	triggerbotreandomburst,

	playerglowenable,
	playerglowtogglekey,
	playerglowonkey,
	playerglowhealth,
	playerglowalpha,
	playerglowcolorr,
	playerglowcolorg,
	playerglowcolorb,
	playerradarenable,
	playerchamsenable,
	playerchamscolorr,
	playerchamscolorg,
	playerchamscolorb,

	weaponglowenable,
	weaponglowcolorr,
	weaponglowcolorg,
	weaponglowcolorb,

	grenadeglowenable,
	grenadeglowdroppedcolorr,
	grenadeglowdroppedcolorg,
	grenadeglowdroppedcolorb,
	grenadeglowthrowncolorr,
	grenadeglowthrowncolorg,
	grenadeglowthrowncolorb,

	miscbhopenable,
	miscbhopchance,
	miscnoflashenable,
	miscnoflashamount,
	miscunloadcheatkey,

	skinchangerenable,
	skinchangerslowdown,
	skinchangerglock18,
	skinchangerusps,
	skinchangerp2000,
	skinchangerp250,
	skinchangerfiveseven,
	skinchangercz75auto,
	skinchangertec9,
	skinchangerdualberettas,
	skinchangerdeserteagle,
	skinchangerr8revolver,
	skinchangermag7,
	skinchangernova,
	skinchangersawedoff,
	skinchangerxm1014,
	skinchangerm249,
	skinchangernegev,
	skinchangermac10,
	skinchangermp5sd,
	skinchangermp7,
	skinchangermp9,
	skinchangerppbizon,
	skinchangerump45,
	skinchangerp90,
	skinchangerak47,
	skinchangeraug,
	skinchangerfamas,
	skinchangergalilar,
	skinchangerm4a1s,
	skinchangerm4a4,
	skinchangersg553,
	skinchangerawp,
	skinchangerg3sg1,
	skinchangerscar20,
	skinchangerssg08,
	loadconfigkey,
	count
};


class Features {

private:
	struct s_cVar {
		std::string varName;
		float varValue;
	};




	std::string filePath;
	std::vector<s_cVar> Vars;

	void AddCvar(std::string varName, float varValue);

public:
	bool LoadSettings();
	bool Init(std::string startUpPath);

	float GetCvarValue(std::string cVarName);
	float GetCvarValueFast(eVars var);
	void ChangeCvarValue(eVars var, float value);

};
extern Features cFeatures;