#pragma once
#include "CommonIncludes.hpp"
#include <TlHelp32.h>

#define EXIT_CODE_HANDLE 2
#define EXIT_CODE_MODULE_FAIL 3

#define in_range(x, a, b) (x >= a && x <= b)
#define get_bits(x) (in_range(x, '0', '9') ? (x - '0') : ((x & (~0x20)) - 'A' + 0xa))
#define get_byte(x) (get_bits(x[0]) << 4 | get_bits(x[1]))

class PotMem {
private:
	HANDLE hGame;
	DWORD dProcessID;


	bool SetProcessID(const char* processName);

	bool CreateHandle();

	typedef NTSYSAPI NTSTATUS NTAPI NtReadVirtualMemory_t(IN HANDLE    ProcessHandle,IN PVOID    BaseAddress,OUT PVOID    Buffer,IN ULONG    NumberOfBytesToRead,OUT PULONG    NumberOfBytesRead OPTIONAL);
	

	NtReadVirtualMemory_t* m_pNtReadVirtualMemory = (NtReadVirtualMemory_t*)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtReadVirtualMemory");

	bool compare_memory(const byte* data, const char* pattern);

public:
	~PotMem();

	void Init(const char* processName);

	HANDLE GetHandle();

	DWORD pattern_scan(MODULEENTRY32& mod, const char* pattern, int offset, int extra, bool relative, bool subtract);

	bool ModuleBaseAddress(const char* module_name, MODULEENTRY32& moduleBaseAddress);


	template <class T> 
	T Read(DWORD addy){
		T value;
		//ReadProcessMemory(hGame, (LPCVOID)addy, (LPVOID)&value, sizeof(value), NULL);
		m_pNtReadVirtualMemory(hGame, (LPVOID)(addy), &value, sizeof(T), 0);
		return value;
	}

	template<class T>
	void Write(DWORD addy, T value) {
		WriteProcessMemory(hGame, (LPVOID)addy, (LPCVOID)&value, sizeof(value), NULL);
	}
};

extern PotMem mem;