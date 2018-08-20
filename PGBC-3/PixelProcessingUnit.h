#pragma once

#include "MemoryManagementUnit.h"
#include "CentralProcessingUnit.h"
#include "MyOpenGLWidget.h"
#include "MyOpenGL_VRAM_Debug.h"

using e_ppu_state = enum {
	H_BLANK,
	V_BLANK,
	OAM_SEARCH,
	PIXEL_TRANSFER,
	OFF
};

using StatePPU = struct
{
	e_ppu_state PPUstate = OFF;
	unsigned int PPUclock = 0;
	unsigned char viewPort_X = 0;
	unsigned char viewPort_Y = 0;
	unsigned char lineBeingDrawn = 0;
};

class PixelProcessingUnit
{
private:
	const unsigned short V_LINES = 160;
	const unsigned short H_LINES = 144;

	const unsigned char SCALE = 2;

	const unsigned short SCREEN_WIDTH = V_LINES * SCALE;
	const unsigned short SCREEN_HEIGHT = H_LINES * SCALE;

	MemoryManagementUnit  &MMU;
	CentralProcessingUnit &CPU;

	MyOpenGL_VRAM_Debug * openGLContext_VRAM = nullptr;
	MyOpenGLWidget * openGLContex = nullptr;
	unsigned int vertsIdx = 0;

	using e_bgp = enum
	{
		BLACK = 0x03,
		D_GREY = 0x02,
		L_GREY = 0x01,
		WHITE = 0x00,
		INVALID_BG = 0xFF
	};

	const unsigned int FRAME_LAST_CLOCK = 70224;
	const unsigned int OAM_LAST_CLOCK = 79;
	const unsigned int PIXEL_TRANSFER_LAST_CLOCK = OAM_LAST_CLOCK + 172;
	const unsigned int H_BLANK_LAST_CLOCK = PIXEL_TRANSFER_LAST_CLOCK + 203;
	const unsigned int V_BLANK_LAST_CLOCK = FRAME_LAST_CLOCK - (H_BLANK_LAST_CLOCK + OAM_LAST_CLOCK + PIXEL_TRANSFER_LAST_CLOCK) * H_LINES;

	e_ppu_state PPUstate = OFF;
	unsigned int PPUclock = 0;
	unsigned int PPUclockCurFrame = 0;

	unsigned char viewPort_X = 0;
	unsigned char viewPort_Y = 0;

	unsigned char lineBeingDrawn = 0;

	unsigned short	fetchetTileNum = 0;

	void reset();
	void init();

	void updateViewPort();
	void fetcherUpdateTileNum();

	void drawPoint(e_bgp pallet, unsigned short x, unsigned short y);
	void renderLine();
public:
	void step();
	StatePPU getUpdate();

	PixelProcessingUnit(MemoryManagementUnit &MMU, CentralProcessingUnit &CPU, MyOpenGLWidget * openGLContex);
	~PixelProcessingUnit();
};

