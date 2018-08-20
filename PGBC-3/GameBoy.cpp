#include "GameBoy.h"

void GameBoy::step()
{
	CPU.step();
	PPU.step();
}

StateCPU GameBoy::getCPUupdate()
{
	return CPU.getUpdate();
}

StatePPU GameBoy::getPPUupdate()
{
	return PPU.getUpdate();
}

unsigned char* GameBoy::getVRAMUpdate(unsigned char bank)
{
	return MMU.getVRAMdebugInfo(bank);
}

GameBoy::GameBoy(char * cartridgeBase, MyOpenGLWidget * openGLContex)
	: CPU(MMU), PPU(MMU, CPU, openGLContex)
{
	/* First Init MMU */
	MMU.initMMU(cartridgeBase);

	/* Then Init CPU */
	CPU.init();
}

GameBoy::~GameBoy()
{
}
