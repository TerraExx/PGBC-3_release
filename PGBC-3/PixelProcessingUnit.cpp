#include "PixelProcessingUnit.h"
#include "Reg_Info.h"
#include "Memory_Info.h"

#include <fstream>
#include <cstdio>

void PixelProcessingUnit::reset()
{
	PPUstate = OFF;
	MMU.write(STAT, 0x01);
}

void PixelProcessingUnit::init()
{
	PPUclock = CPU.getCurrentClock();

	PPUstate = OAM_SEARCH;
	MMU.write(STAT, OAM_SEARCH);

	viewPort_X = MMU.getReg(SCX);
	viewPort_Y = MMU.getReg(SCY);

	fetcherUpdateTileNum();

	lineBeingDrawn = 0;

	MMU.write(LY, lineBeingDrawn);
}

void PixelProcessingUnit::updateViewPort()
{
	unsigned char viewPort_X_new = MMU.getReg(SCX);
	unsigned char viewPort_Y_new = MMU.getReg(SCY);

	if (viewPort_X < viewPort_X_new)
	{
		++viewPort_X;
	}
	else if (viewPort_X > viewPort_X_new)
	{
		--viewPort_X;
	}

	if (viewPort_Y < viewPort_Y_new)
	{
		++viewPort_Y;
	}
	else if (viewPort_Y > viewPort_Y_new)
	{
		--viewPort_Y;
	}
}

void PixelProcessingUnit::fetcherUpdateTileNum()
{
	unsigned char offsetX = (viewPort_X) % 256;
	unsigned char offsetY = (viewPort_Y + lineBeingDrawn) % 256;

	fetchetTileNum = (offsetX) / 8 + ((offsetY) / 8) * 32;
}

void PixelProcessingUnit::drawPoint(e_bgp pallet, unsigned short x, unsigned short y)
{
	openGLContex->rendBufferBack[vertsIdx++] = x;
	openGLContex->rendBufferBack[vertsIdx++] = y;

	switch (pallet)
	{
	case BLACK:
		openGLContex->rendBufferBack[vertsIdx++] = 13;
		openGLContex->rendBufferBack[vertsIdx++] = 64;
		openGLContex->rendBufferBack[vertsIdx++] = 41;
		break;
	case D_GREY:
		openGLContex->rendBufferBack[vertsIdx++] = 27;
		openGLContex->rendBufferBack[vertsIdx++] = 127;
		openGLContex->rendBufferBack[vertsIdx++] = 82;
		break;
	case L_GREY:
		openGLContex->rendBufferBack[vertsIdx++] = 40;
		openGLContex->rendBufferBack[vertsIdx++] = 191;
		openGLContex->rendBufferBack[vertsIdx++] = 123;
		break;
	case WHITE:
		openGLContex->rendBufferBack[vertsIdx++] = 53;
		openGLContex->rendBufferBack[vertsIdx++] = 255;
		openGLContex->rendBufferBack[vertsIdx++] = 164;
		break;
	default:
		openGLContex->rendBufferBack[vertsIdx++] = 255;
		openGLContex->rendBufferBack[vertsIdx++] = 255;
		openGLContex->rendBufferBack[vertsIdx++] = 255;
		printf("Something is wrong\n");
		break;
	}
}

void PixelProcessingUnit::renderLine()
{
	unsigned short newFetchetTileNum = fetchetTileNum;
	unsigned short tileCode = 0;
	unsigned char  tileRow[2] = { 0, 0 };
	unsigned char  pixelLine[168] = {0};
	unsigned char  *pixelLinePtr = pixelLine;
	unsigned short row = 0;
	unsigned short bit_mask = 0;
	unsigned short value = 0;

	for (char tileNum = 0; tileNum < 21; ++tileNum)
	{
		if (tileNum != 0)
		{
			++newFetchetTileNum;
			if ((newFetchetTileNum % 32) == 0)
			{
				newFetchetTileNum -= 32;
			}
		}

		tileCode = MMU.read(BGD1_OFFSET + newFetchetTileNum);

		if (tileCode != 0)
		{
			char proba = 0;
			proba++;
		}

		tileRow[0] =
			MMU.read(CRAM_OFFSET + tileCode * 0x10 + ((viewPort_Y + lineBeingDrawn) % 8) * 0x02);
		tileRow[1] =
			MMU.read(CRAM_OFFSET + tileCode * 0x10 + ((viewPort_Y + lineBeingDrawn) % 8) * 0x02 + 1);

		row = (tileRow[0] << 8) | tileRow[1];
		bit_mask = 0x8080;

		for (char Pixel = 0; Pixel < 8; ++Pixel)
		{
			value = (row & bit_mask) >> (7 - Pixel);
			value = (value & 0x01) | value >> 7;

			bit_mask = bit_mask >> 1;
			*pixelLinePtr = value;
			++pixelLinePtr;
		}
	}

	pixelLinePtr = pixelLine + viewPort_X % 8;

	for (unsigned char pixel = 0; pixel < 160; ++pixel)
	{
		drawPoint(static_cast<e_bgp>(*pixelLinePtr), pixel, lineBeingDrawn);
		++pixelLinePtr;
	}
}

void PixelProcessingUnit::step()
{
	unsigned char LCDC_displayState = MMU.getReg(LCDC, LCDC_DISPLAY_ENABLE);
	unsigned int  newCPUclock = 0;
	e_ppu_state   newPPUstate = OFF;

	if (0 == LCDC_displayState)
	{
		if (OFF != PPUstate)
		{
			reset();
			PPUclockCurFrame = 0;
		}
		return;
	}
	else
	{
		if (OFF == PPUstate)
		{
			init();
		}
	}

	newCPUclock = CPU.getCurrentClock();
	PPUclockCurFrame += newCPUclock - PPUclock;
	PPUclock = newCPUclock;

	if ((PPUclockCurFrame % 456) < OAM_LAST_CLOCK)
	{
		newPPUstate = OAM_SEARCH;
	}
	else if ((PPUclockCurFrame % 456) < PIXEL_TRANSFER_LAST_CLOCK)
	{
		newPPUstate = PIXEL_TRANSFER;
	}
	else if ((PPUclockCurFrame % 456) < H_BLANK_LAST_CLOCK)
	{
		newPPUstate = H_BLANK;
	}

	if (newPPUstate != PPUstate)
	{
		if (PPUstate == V_BLANK)
		{
			lineBeingDrawn = (PPUclockCurFrame / 456);
			MMU.write(LY, lineBeingDrawn);

			if (PPUclockCurFrame > FRAME_LAST_CLOCK)
			{
				PPUclockCurFrame = PPUclockCurFrame % FRAME_LAST_CLOCK;

				lineBeingDrawn = 0;
				MMU.write(LY, lineBeingDrawn);

				updateViewPort();
				fetchetTileNum =
					(viewPort_X) / 8 + (((viewPort_Y + lineBeingDrawn) % 256) / 8) * 32;

				PPUstate = OAM_SEARCH;
				MMU.write(STAT, OAM_SEARCH);
			}
		}
		else
		{
			switch (newPPUstate)
			{
			case OAM_SEARCH:
				lineBeingDrawn = (PPUclockCurFrame / 456);
				MMU.write(LY, lineBeingDrawn);

				updateViewPort();
				fetchetTileNum =
					(viewPort_X) / 8 + (((viewPort_Y + lineBeingDrawn) % 256) / 8) * 32;

				if (lineBeingDrawn == 144)
				{
					//Update screen
					openGLContex->swapBuffers();
					openGLContex->update();
					vertsIdx = 0;

					PPUstate = V_BLANK;
					MMU.write(STAT, V_BLANK);
				}
				else
				{
					PPUstate = OAM_SEARCH;
					MMU.write(STAT, OAM_SEARCH);
				}
				break;

			case PIXEL_TRANSFER:
				PPUstate = PIXEL_TRANSFER;
				MMU.write(STAT, PIXEL_TRANSFER);
				break;

			case H_BLANK:
				renderLine();

				PPUstate = H_BLANK;
				MMU.write(STAT, H_BLANK);
				break;
			}
		}
	}
}

StatePPU PixelProcessingUnit::getUpdate()
{
	StatePPU state;

	state.PPUstate = PPUstate;
	state.PPUclock = PPUclock;
	state.viewPort_X = viewPort_X;
	state.viewPort_Y = viewPort_Y;
	state.lineBeingDrawn = lineBeingDrawn;

	return state;
}

PixelProcessingUnit::PixelProcessingUnit(MemoryManagementUnit &MMU, CentralProcessingUnit &CPU, MyOpenGLWidget * openGLContex)
	: MMU(MMU),
	CPU(CPU),
	openGLContex(openGLContex),
	openGLContext_VRAM(openGLContext_VRAM)
{
}


PixelProcessingUnit::~PixelProcessingUnit()
{
}
