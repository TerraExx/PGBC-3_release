#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <functional>

#include "Cartridge_Info.h"

class MemoryManagementUnit
{
private:
	Cartridge_Info cartInfo;

	bool runningBootCode = true;
	unsigned char *BP = nullptr;

	////////////////////MBC////////////////////////
	using eBankingMode = enum
	{
		ROM_BANKING_MODE,
		RAM_BANKING_MODE,
	};

	eBankingMode bankingMode = ROM_BANKING_MODE;

	void MBC_1(unsigned short address, unsigned char value);

	//////////////Memory Banks/////////////////////
	unsigned char selected_ROM_bank  = 0;
	unsigned char selected_ERAM_bank = 0;
	unsigned char selected_IROM_bank = 0;

	unsigned char ROM_banks  = 0;
	unsigned char ERAM_banks = 0;
	unsigned char IROM_banks = 8;

	//////////////Memory Base Pointers//////////////
	unsigned char* baseROM_0   = nullptr;
	std::vector<unsigned char*>  baseROM_n;
	std::vector<unsigned char*>  baseCRAM;
	std::vector<unsigned char*>  baseBGD1;
	std::vector<unsigned char*>  baseBGD2;
	std::vector<unsigned char*>  baseERAM_n;
	unsigned char* baseIRAM_0  = nullptr;
	std::vector<unsigned char*>  baseIRAM_n;
	unsigned char* baseEchoRAM = nullptr;
	unsigned char* baseOAM     = nullptr;
	unsigned char* baseUUM     = nullptr;
	unsigned char* baseIOREG   = nullptr;
	unsigned char* baseZP      = nullptr;

	///////////////IO Register Offests//////////////
	std::unordered_map<unsigned short, unsigned char> offsetHash;

public:
	void initMMU(char * cartridgeBase);

	///////////////IO functions//////////////
	void write(unsigned short address, unsigned char value);
	unsigned char read(unsigned short address);

	///////////////IO Register functions//////////////
	unsigned char getReg(const unsigned short& reg, const unsigned char& bit = 0xFF);

	///////////////Debug functions//////////////
	unsigned char* getVRAMdebugInfo(unsigned char bank);

	MemoryManagementUnit();
	~MemoryManagementUnit();
};

