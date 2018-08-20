#pragma once

#include "MyOpenGLWidget.h"
#include "MyOpenGL_VRAM_Debug.h"
#include "MemoryManagementUnit.h"
#include "CentralProcessingUnit.h"
#include "PixelProcessingUnit.h"

class GameBoy
{
private:
	MemoryManagementUnit MMU;
	CentralProcessingUnit CPU;
	PixelProcessingUnit PPU;

public:
	void step();

	StateCPU getCPUupdate();
	StatePPU getPPUupdate();

	unsigned char* getVRAMUpdate(unsigned char bank);

	GameBoy(char* cartridgeBase, MyOpenGLWidget *openGLContex);
	~GameBoy();
};

