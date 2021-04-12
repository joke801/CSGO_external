#include "CommonIncludes.hpp"
#include "Memory.hpp"
#include "Offsets.hpp"
#include "Entity.hpp"
#include "Features.hpp"
#include "Glow.hpp"
#include "Radar.hpp"
#include "Chams.hpp"
#include "Random.hpp"
#include "Skinchanger.hpp"
#include "Standalonerecoil.hpp"
#include <iostream>
#include <thread>


void glowthread() {
	while (!GetAsyncKeyState(static_cast<int>(cFeatures.GetCvarValueFast(eVars::miscunloadcheatkey)))) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		if (!cLocalPlayer.localPlayerBase)
			continue;
		cGlow.tGlow();

	}
}


//RADAR, CHAMS, ANTIFLASH, BHOP, TRIGGERBOT
void miscThread() {
	while (!GetAsyncKeyState(static_cast<int>(cFeatures.GetCvarValueFast(eVars::miscunloadcheatkey)))) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
			
		if (!cLocalPlayer.localPlayerBase)
			continue;
		for (unsigned int c = 1; c < 32; ++c) {
			EntityPlayer cEntity = mem.Read<EntityPlayer>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwEntityList + 0x10 * c);

			if (!cEntity.entityBase)
				continue;
			if (cEntity.entityBase==cLocalPlayer.localPlayerBase)
				continue;
			if (cEntity.b_EntityDormant())
				continue;
			if (cEntity.b_TeamCheck())
				continue;
			if (cEntity.i_EntityHealth() <= 0)
				continue;

			cRadar.doRadar(cEntity);

			cChams.doChams(cEntity);
		}

		// BHOP
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && cFeatures.GetCvarValueFast(eVars::miscbhopenable) && (cLocalPlayer.flags == 257|| cLocalPlayer.flags == 261 || cLocalPlayer.flags == 263)) {

			if (cRandomDevice.RandomNum<int>(100, 1) <= cFeatures.GetCvarValueFast(eVars::miscbhopchance)) {
				mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceJump, 6);
			}
			else {
				Sleep(cRandomDevice.RandomNum<int>(18, 10));
				mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceJump, 6);
			}

		} 
		
		//NOFLASH
		if (cFeatures.GetCvarValueFast(eVars::miscnoflashenable)) {
			mem.Write<float>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_flFlashMaxAlpha, cFeatures.GetCvarValueFast(eVars::miscnoflashamount));
		}

		//TRIGGERBOT
		if (cFeatures.GetCvarValueFast(eVars::triggerbotenable)) {
			if ((GetAsyncKeyState((int)cFeatures.GetCvarValueFast(eVars::triggerbotkey)) & 0x8000)) {
				if (cFeatures.GetCvarValueFast(eVars::triggerbothitchance) && (1.f - cLocalPlayer.Accuracy) * 100.f <= 98.6f || cAimlock.WeaponIsSniper()) {
					continue;
				}
				else {
					int CrossId = mem.Read<int>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_iCrosshairId);
					if (CrossId > 0 && CrossId <= 65) {
						EntityPlayer cEntity = mem.Read<EntityPlayer>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwEntityList + ((CrossId) * 0x10));

						if (!cEntity.entityBase || cEntity.b_HasGunGameImmunity() || cEntity.b_TeamCheck()) {
							continue;
						}
						else {
							mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceAttack, 6);
							if (cFeatures.GetCvarValueFast(eVars::triggerbotreandomburst) && !(cAimlock.WeaponIsPistol() || cAimlock.WeaponIsSniper())) {
								std::this_thread::sleep_for(std::chrono::nanoseconds(cRandomDevice.RandomNum<int>(80, 30)));
							}
							else {
								std::this_thread::sleep_for(std::chrono::nanoseconds(cRandomDevice.RandomNum<int>(12, 25)));
							}
							mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceAttack, 4);
							std::this_thread::sleep_for(std::chrono::nanoseconds(cRandomDevice.RandomNum<int>(12, 20)));
							Beep(50,10);
							if (cFeatures.GetCvarValueFast(eVars::triggerbotreandomburst) && (cAimlock.WeaponIsPistol() || cAimlock.WeaponIsSniper())) {
								mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceAttack, 6);
								std::this_thread::sleep_for(std::chrono::nanoseconds(cRandomDevice.RandomNum<int>(12, 25)));
								mem.Write<int>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwForceAttack, 4);
								std::this_thread::sleep_for(std::chrono::nanoseconds(cRandomDevice.RandomNum<int>(12, 20)));
							}
						}
					}
				}
			}
		}


		//STANDALONE RECOIL
		if (cFeatures.GetCvarValueFast(eVars::standalonerecoilenable)) {
			cStandalonerecoil.DoRecoil();
		}
	}
}


void skinthread() {
	while (!GetAsyncKeyState(static_cast<int>(cFeatures.GetCvarValueFast(eVars::miscunloadcheatkey)))) {

		if(cFeatures.GetCvarValueFast(eVars::skinchangerslowdown)|| !cFeatures.GetCvarValueFast(eVars::skinchangerenable))
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));

		if (!cLocalPlayer.localPlayerBase) {
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));
			continue;
		}
		cSkinchanger.doSkinchanger();
	}
}



int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow){

	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	cFeatures.Init(GetCommandLine());
	cFeatures.LoadSettings();

	mem.Init("csgo.exe");

	while (!mem.ModuleBaseAddress("client.dll", Offsets.SDK.iClientBaseAddress)) {
		Sleep(2000);
	}
	if (!mem.ModuleBaseAddress("engine.dll", Offsets.SDK.iEngineBaseAddress)) {
		exit(-2);
	}
	if (!Offsets.bSetOffsets()) {
		exit(-3);
	}

	std::thread GlowThread(glowthread);	
	std::thread IDKTHREAD(miscThread);
	std::thread shit(skinthread);

	GlowThread.detach();
	IDKTHREAD.detach();
	shit.detach();

	int onePress = clock();

	while (!GetAsyncKeyState(static_cast<int>(cFeatures.GetCvarValueFast(eVars::miscunloadcheatkey)))) {
		Sleep(1);

		cLocalPlayer.localPlayerBase = mem.Read<DWORD>(Offsets.SIGS.dwLocalPlayer + (DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr);

		if (!cLocalPlayer.localPlayerBase)
			continue;

		cLocalPlayer.Team = mem.Read<int>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_iTeamNum);
		cLocalPlayer.flags = mem.Read<int>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_fFlags);
		cLocalPlayer.health = mem.Read<int>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_iHealth);

		DWORD currentWeapon = mem.Read<DWORD>(cLocalPlayer.localPlayerBase + Offsets.NVARS.m_hActiveWeapon ) & 0xfff;
		currentWeapon = mem.Read<DWORD>((DWORD)Offsets.SDK.iClientBaseAddress.modBaseAddr + Offsets.SIGS.dwEntityList + (currentWeapon - 1) * 0x10);

		if (currentWeapon) {
			cLocalPlayer.ActiveWeaponID = mem.Read<int>(currentWeapon + Offsets.NVARS.m_iItemDefinitionIndex);
			cLocalPlayer.clipAmmo = mem.Read<int>(currentWeapon + Offsets.NVARS.m_iClip1);
			cLocalPlayer.Accuracy = mem.Read<float>(currentWeapon + Offsets.NVARS.m_fAccuracyPenalty);

		}

		if (clock() - onePress > 300) {
			if (GetAsyncKeyState(static_cast<int>(cFeatures.GetCvarValueFast(eVars::loadconfigkey)))) {
				cFeatures.LoadSettings();
				onePress = clock();
			}
			else if ( GetAsyncKeyState(VK_SUBTRACT) & 0x8000) {
				cSkinchanger.ForceFullUpdate();
				onePress = clock();
			}
			else if (cFeatures.GetCvarValueFast(eVars::playerglowtogglekey) != 0 && GetAsyncKeyState((int)cFeatures.GetCvarValueFast(eVars::playerglowtogglekey))) {
				cFeatures.ChangeCvarValue(eVars::playerglowenable, !((bool)cFeatures.GetCvarValueFast(eVars::playerglowenable)));
				onePress = clock();
			}
		}
	}
	
	cSkinchanger.ForceFullUpdate();

	return 0;
}
