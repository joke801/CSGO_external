#include "Features.hpp"
#include <fstream>

Features cFeatures;

bool Features::LoadSettings() {

	std::ifstream File;
	File.open(filePath);

	if (!File.is_open())
		return false;
	while (!File.eof()) {
		std::string Buffer;
		std::getline(File, Buffer);
		int varNameIndex=0;

		for (unsigned int c = 0; c < Buffer.length(); ++c) {
			if (Buffer[c] == ':') {
				varNameIndex = c;
				break;
			}
		}
		for (unsigned int c = 0; c < Vars.size(); ++c) {
			if (Buffer.substr(0, varNameIndex) == Vars[c].varName) {
				Vars[c].varValue = (float)atof(Buffer.substr(varNameIndex + 1, std::string::npos).c_str());
				break;
			}
		}
	}

	File.close();
	return true;
}


void Features::AddCvar(std::string varName, float varValue) {
	Vars.push_back(Features::s_cVar{ varName,varValue });
}

bool Features::Init(std::string startUpPath) {

	startUpPath.erase(startUpPath.find("\""),1);
	startUpPath.erase(startUpPath.find("\""), 1);

	for (int c = startUpPath.length() - 1; c >= 0; --c) {
		if (startUpPath[c] == '\\') {
			startUpPath.erase(c+1);
			break;
		}


	}
	startUpPath += "\\config.txt";
	this->filePath = startUpPath;

	AddCvar("aimlock.enable", 0);
	AddCvar("aimlock.key", 5);
	AddCvar("aimlock.fov", 8);
	AddCvar("aimlock.bone", 6);
	AddCvar("aimlock.bonealternative", 30.f);
	AddCvar("aimlock.smooth.x", 30.f);
	AddCvar("aimlock.smooth.y", 30.f);
	AddCvar("aimlock.randomize", 1.f);
	AddCvar("aimlock.recoil", 1);

	AddCvar("standalonerecoil.enable", 0);
	AddCvar("standalonerecoil.humanize", 0);

	AddCvar("triggerbot.enable", 1);
	AddCvar("triggerbot.key", 5);
	AddCvar("triggerbot.hitchance", 1);
	AddCvar("triggerbot.randomdelay", 0);
	AddCvar("triggerbot.randomburst", 0);

	AddCvar("player.glow.enable", 1);
	AddCvar("player.glow.togglekey", 97);
	AddCvar("player.glow.onkey", 0);
	AddCvar("player.glow.health", 1);
	AddCvar("player.glow.alpha", 178.5f);
	AddCvar("player.glow.color.r", 0);
	AddCvar("player.glow.color.g", 0);
	AddCvar("player.glow.color.b", 0);
	AddCvar("player.radar.enable", 0);
	AddCvar("player.chams.enable", 1);
	AddCvar("player.chams.color.r", 255);
	AddCvar("player.chams.color.g", 0);
	AddCvar("player.chams.color.b", 0);

	AddCvar("weapon.glow.enable", 1);
	AddCvar("weapon.glow.color.r", 255);
	AddCvar("weapon.glow.color.g", 255);
	AddCvar("weapon.glow.color.b", 255);

	AddCvar("grenade.glow.enable", 1);
	AddCvar("grenade.glow.dropped.color.r", 255);
	AddCvar("grenade.glow.dropped.color.g", 165);
	AddCvar("grenade.glow.dropped.color.b", 0);
	AddCvar("grenade.glow.thrown.color.r", 255);
	AddCvar("grenade.glow.thrown.color.g", 0);
	AddCvar("grenade.glow.thrown.color.b", 255);

	AddCvar("misc.bhop.enable", 1);
	AddCvar("misc.bhop.chance", 60);
	AddCvar("misc.noflash.enable", 1);
	AddCvar("misc.noflash.amount", 100);
	AddCvar("misc.unloadcheat.key", 107);


	AddCvar("skinchanger.enable", 1);
	AddCvar("skinchanger.slowdown", 0);
	AddCvar("skinchanger.glock-18.skin", 38);
	AddCvar("skinchanger.usp-s.skin", 504);
	AddCvar("skinchanger.p2000.skin", 389);
	AddCvar("skinchanger.p250.skin", 551);
	AddCvar("skinchanger.five-seven.skin", 660);
	AddCvar("skinchanger.cz75-auto.skin", 322);
	AddCvar("skinchanger.tec-9.skin", 555);
	AddCvar("skinchanger.dual-berettas.skin", 491);
	AddCvar("skinchanger.desert-eagle.skin", 37);
	AddCvar("skinchanger.r8-revolver.skin", 523);

	AddCvar("skinchanger.mag-7.skin", 39);
	AddCvar("skinchanger.nova.skin", 158);
	AddCvar("skinchanger.sawed-off.skin", 246);
	AddCvar("skinchanger.xm1014.skin", 557);
	AddCvar("skinchanger.m249.skin", 547);
	AddCvar("skinchanger.negev.skin", 610);

	AddCvar("skinchanger.mac-10.skin", 433);
	AddCvar("skinchanger.mp5-sd.skin", 781);
	AddCvar("skinchanger.mp7.skin", 102);
	AddCvar("skinchanger.mp9.skin", 39);
	AddCvar("skinchanger.pp-bizon.skin", 203);
	AddCvar("skinchanger.ump-45.skin", 333);
	AddCvar("skinchanger.p90.skin", 359);


	AddCvar("skinchanger.ak-47.skin", 180);
	AddCvar("skinchanger.aug.skin", 455);
	AddCvar("skinchanger.famas.skin", 723);
	AddCvar("skinchanger.galil-ar.skin", 647);
	AddCvar("skinchanger.m4a1-s.skin", 321);
	AddCvar("skinchanger.m4a4.skin", 309);
	AddCvar("skinchanger.sg-553.skin", 487);

	AddCvar("skinchanger.awp.skin", 344);
	AddCvar("skinchanger.g3sg1.skin", 545);
	AddCvar("skinchanger.scar-20.skin", 642);
	AddCvar("skinchanger.ssg-08.skin", 222);

	AddCvar("loadconfig.key", 45);//insert

	

	std::ofstream oFile;
	oFile.open(filePath);
	if (!oFile.is_open())
		return false;

		std::string TitleName = "aimlock";

		oFile << "[" << TitleName << "]" << std::endl << std::endl;

		for (unsigned int c = 0; c < Vars.size(); ++c) {

			int pos = Vars[c].varName.find(".");

			if (Vars[c].varName.substr(0, pos) != TitleName) {
				TitleName = Vars[c].varName.substr(0, pos);
				oFile<<std::endl<<std::endl<< "[" << TitleName << "]" << std::endl << std::endl;
			}

			oFile << Vars[c].varName << ":" << std::to_string(Vars[c].varValue)<<std::endl;
		}



	return true;
}

float Features::GetCvarValue(std::string cVarName) {
	for (unsigned int c = 0; c < Vars.size(); ++c) {
		if (cVarName == Vars[c].varName) {
			return Vars[c].varValue;
		}
	}
	return 0;
}
float Features::GetCvarValueFast(eVars var) {
	return Vars[static_cast<int>(var)].varValue;
}

void Features::ChangeCvarValue(eVars var,float value) {
	Vars[static_cast<int>(var)].varValue = value;
}