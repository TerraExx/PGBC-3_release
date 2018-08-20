#pragma once

#include "MyOpenGL_VRAM_Debug.h"
#include <vector>

class VRAM_Debug
{
private:
	using e_bgp = enum
	{
		BLACK = 0x03,
		D_GREY = 0x02,
		L_GREY = 0x01,
		WHITE = 0x00,
		INVALID_BG = 0xFF
	};

	unsigned int vertsIdx = 0;

	void VRAM_Debug::drawPoint(e_bgp pallet, unsigned short x, unsigned short y, MyOpenGL_VRAM_Debug *VRAM_GLcontext);

public:
	void drawVRAM(MyOpenGL_VRAM_Debug *VRAM_GLcontext, unsigned char* VRAM_Mem_Ptr, unsigned char bank);

	VRAM_Debug();
	~VRAM_Debug();
};

