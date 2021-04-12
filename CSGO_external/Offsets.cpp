#include "Offsets.hpp"
#include <iostream>
offsets Offsets;


bool offsets::bSetOffsets() {

	SIGS.dwClientState = mem.pattern_scan(SDK.iEngineBaseAddress, "A1 ? ? ? ? 33 D2 6A 00 6A 00 33 C9 89 B0", 1, 0, true, true);
	if (SIGS.dwClientState == NULL) {
		return false;
	}

	SIGS.dwForceJump = mem.pattern_scan(SDK.iClientBaseAddress, "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02", 2, 0, true, true);
	if (SIGS.dwForceJump == NULL) {
		return false;
	}

	SIGS.dwLocalPlayer = mem.pattern_scan(SDK.iClientBaseAddress, "8D 34 85 ? ? ? ? 89 15 ? ? ? ? 8B 41 08 8B 48 04 83 F9 FF", 3, 4, true, true);
	if (SIGS.dwLocalPlayer == NULL) {
		return false;
	}

	SIGS.dwEntityList = mem.pattern_scan(SDK.iClientBaseAddress, "BB ? ? ? ? 83 FF 01 0F 8C ? ? ? ? 3B F8", 1, 0, true, true);
	if (SIGS.dwEntityList == NULL) {
		return false;
	}

	SIGS.dwGlowObjectManager = mem.pattern_scan(SDK.iClientBaseAddress, "A1 ? ? ? ? A8 01 75 4B", 1, 4, true, true);
	if (SIGS.dwGlowObjectManager == NULL) {
		return false;
	}

	SIGS.m_bDormant = 0xED;//mem.pattern_scan(SDK.iClientBaseAddress, "8A 81 ? ? ? ? C3 32 C0", 2, 8, false, true);
	if (SIGS.m_bDormant == NULL) {
		return false;
	}

	SIGS.dwClientState_ViewAngles = 0x4D90;
	if (SIGS.dwClientState_ViewAngles == NULL) {
		return false;
	}

	SIGS.dwForceAttack = mem.pattern_scan(SDK.iClientBaseAddress, "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04", 2, 0, true, true);
	if (SIGS.dwForceAttack == NULL) {
		return false;
	}
	SIGS.dwGameRulesProxy = mem.pattern_scan(SDK.iClientBaseAddress, "A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 80 B8 ? ? ? ? ? 74 7A", 1, 0, true, true);
	if (SIGS.dwGameRulesProxy == NULL) {
		return false;
	}
	SIGS.dwMouseEnable = mem.pattern_scan(SDK.iClientBaseAddress, "B9 ? ? ? ? FF 50 34 85 C0 75 10", 1, 48, true, true);
	if (SIGS.dwMouseEnable == NULL) {
		return false;
	}


	return true;
}




