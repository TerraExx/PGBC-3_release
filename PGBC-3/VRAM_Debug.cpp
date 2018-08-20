#include "VRAM_Debug.h"

void VRAM_Debug::drawPoint(e_bgp pallet, unsigned short x, unsigned short y, MyOpenGL_VRAM_Debug *VRAM_GLcontext)
{
	VRAM_GLcontext->rendBufferBack[vertsIdx++] = x;
	VRAM_GLcontext->rendBufferBack[vertsIdx++] = y;

	switch (pallet)
	{
	case BLACK:
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 13;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 64;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 41;
		break;
	case D_GREY:
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 27;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 127;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 82;
		break;
	case L_GREY:
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 40;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 191;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 123;
		break;
	case WHITE:
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 53;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 255;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 164;
		break;
	default:
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 255;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 255;
		VRAM_GLcontext->rendBufferBack[vertsIdx++] = 255;
		printf("Something is wrong\n");
		break;
	}
}


void VRAM_Debug::drawVRAM(MyOpenGL_VRAM_Debug *VRAM_GLcontext, unsigned char* VRAM_Mem_Ptr, unsigned char bank)
{
	unsigned short offset_X = 0;
	unsigned short offset_Y = 0;

	unsigned short* rowPtr = nullptr;
	unsigned short rowMask = 0x8080;

	unsigned char temp;

	vertsIdx = 0;
	rowPtr = reinterpret_cast<unsigned short*>(VRAM_Mem_Ptr);

	for (unsigned short tile_y = 0; tile_y < 24; ++tile_y)
	{
		for (unsigned short tile_x = 0; tile_x < 16; ++tile_x)
		{
			for (unsigned char line = 0; line < 8; line++)
			{
				rowMask = 0x8080;

				for (unsigned char pixel = 0; pixel < 8; pixel++)
				{
					temp = ((*rowPtr & rowMask) >> (7 - pixel)) | ((*rowPtr & rowMask) >> (7 - pixel));
					drawPoint(static_cast<e_bgp>(temp), offset_X + pixel, offset_Y + line, VRAM_GLcontext);
					rowMask = rowMask >> 1;
				}

				++rowPtr;
			}

			offset_X += 9;
		}

		offset_X = 0;
		offset_Y += 9;
	}


	VRAM_GLcontext->swapBuffers();
	VRAM_GLcontext->update();
}

VRAM_Debug::VRAM_Debug()
{
}


VRAM_Debug::~VRAM_Debug()
{
}
