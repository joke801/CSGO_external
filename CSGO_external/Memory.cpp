#include "Memory.hpp"

PotMem mem;

PotMem::~PotMem() {
	CloseHandle(hGame);
}


void PotMem::Init(const char* processName) {
	while (!SetProcessID(processName)) {
		Sleep(5000);
	}
	if (!CreateHandle())
		exit(EXIT_CODE_HANDLE);
}

bool PotMem::SetProcessID(const char* processName) {

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE)
		return false;

	PROCESSENTRY32 ProcessEntry;
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &ProcessEntry))
	{
		do
		{
			if (!strcmp(processName, ProcessEntry.szExeFile))
			{
				dProcessID = ProcessEntry.th32ProcessID;
				CloseHandle(hSnapshot);
				return true;
			}
		} while (Process32Next(hSnapshot, &ProcessEntry));
	}
	CloseHandle(hSnapshot);


	return false;
}

HANDLE PotMem::GetHandle() {
	return this->hGame;
}

bool PotMem::CreateHandle() {

	hGame = INVALID_HANDLE_VALUE;

	hGame = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, false, dProcessID);

	if (hGame == INVALID_HANDLE_VALUE)
		return false;
	else
		return true;

}

bool PotMem::ModuleBaseAddress(const char* module_name, MODULEENTRY32& moduleBaseAddress) {

	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dProcessID);
	if (hSnapShot == INVALID_HANDLE_VALUE)
		return false;

	MODULEENTRY32 modEntry = { 0 };
	modEntry.dwSize = sizeof(MODULEENTRY32);
	if (Module32First(hSnapShot, &modEntry)) {
		do {
			if (!strcmp(module_name, modEntry.szModule)) {
				moduleBaseAddress = modEntry;
				CloseHandle(hSnapShot);
				return true;

			}
		} while (Module32Next(hSnapShot, &modEntry));
	}
	CloseHandle(hSnapShot);
	return false;
}

bool PotMem::compare_memory(const byte* data, const char* pattern){
	for (; *pattern; *pattern != ' ' ? ++data : data, ++pattern)
	{
		if (*pattern == ' ' || *pattern == '?') continue;
		if (*data != get_byte(pattern)) return false;
		++pattern;
	}
	return true;
}

DWORD PotMem::pattern_scan(MODULEENTRY32& mod, const char* pattern, int offset, int extra, bool relative, bool subtract){
	DWORD address = 0;

	byte* data = new byte[mod.modBaseSize];
	ReadProcessMemory(this->hGame, (LPCVOID)mod.modBaseAddr, data, mod.modBaseSize, NULL);

	for (DWORD i = 0x1000; i < mod.modBaseSize; i++)
	{
		if (compare_memory((const byte*)(data + i), pattern))
		{
			address = (DWORD)mod.modBaseAddr + i + offset;
			if (relative) { ReadProcessMemory(this->hGame, LPCVOID(address), &address, sizeof(DWORD), NULL); }
			if (subtract) { address -= (DWORD)mod.modBaseAddr; }
			address += extra;
			break;
		}
	}

	delete[] data;
	return address;
}