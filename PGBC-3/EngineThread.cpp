#include <fstream>
#include <iostream>

#include "EngineThread.h"

EngineThread::EngineThread(Engine::engineState state)
	: state(state)
{
}

EngineThread::~EngineThread()
{
}

void EngineThread::updateStateCPU()
{
	stateCPU = GB->getCPUupdate();
}

void EngineThread::updateStatePPU()
{
	statePPU = GB->getPPUupdate();
}

void EngineThread::updateDebugWindow()
{
	updateStateCPU();
	updateStatePPU();
	emit gotUpdateCPU();
	emit gotUpdatePPU();

	VRAM_DBG.drawVRAM(VRAM_GLcontext, GB->getVRAMUpdate(VRAMbank), VRAMbank);
}

void EngineThread::initGB(QString ROMdir, MyOpenGLWidget *openGLContex, MyOpenGL_VRAM_Debug *opGLContex_VRAM)
{
	/* SAve VRAM Open GL Context */
	VRAM_GLcontext = opGLContex_VRAM;

	/* Open and Binary Read the ROM file */
	std::ifstream file(ROMdir.toLocal8Bit().constData(), std::ios::in | std::ios::binary | std::ios::ate);

	if (file.is_open() == false)
	{
		std::cout << "Unable to open file\n";
		exit(1);
	}

	unsigned int size = file.tellg();
	char* cartridgeBase = new char[size];
	file.seekg(0, std::ios::beg);
	file.read(cartridgeBase, size);
	file.close();

	/* Create a new GameBoy instance */
	GB = new GameBoy(cartridgeBase, openGLContex);
}

void EngineThread::run()
{
	/* Init */
	/* If in BREAKPOINT, handle updates */
	if (state == Engine::BREAKPOINT)
	{
		updateStateCPU();
		updateStatePPU();
		emit gotUpdateCPU();
		emit gotUpdatePPU();
	}

	while (!shouldStop)
	{
		/********* Check Requests *********/
		/* Check if new state was requested */
		if (newState != Engine::INVALID)
		{
			state = newState;
			newState = Engine::INVALID;

			/* If BREAKPOINT was requested (Pause button) */
			if (state == Engine::BREAKPOINT)
			{
				updateDebugWindow();
			}
		}

		/* Check if VRAM bank was requested */
		if (newVRAMbank != VRAMbank)
		{
			VRAMbank = newVRAMbank;
			VRAM_DBG.drawVRAM(VRAM_GLcontext, GB->getVRAMUpdate(VRAMbank), VRAMbank);
		}

		/********* Handle state *********/
		if(state != Engine::BREAKPOINT)
		{
			GB->step();
		}

		if (state == Engine::STEP)
		{
			updateDebugWindow();
			state = Engine::BREAKPOINT;
		}
		else if (state == Engine::RUN_TO_FRAME)
		{
			updateStatePPU();
			if (statePPU.PPUstate == OAM_SEARCH && statePPU.lineBeingDrawn == 0 && (statePPU.PPUclock - tempPPUclock) > 79 )
			{
				tempPPUclock = statePPU.PPUclock;

				updateDebugWindow();
				state = Engine::BREAKPOINT;
			}
		}

	}
}

void EngineThread::stop()
{
	shouldStop = true;
}

void EngineThread::setState(Engine::engineState reqState)
{
	newState = reqState;
}

void EngineThread::setVRAMbank(unsigned char bank)
{
	newVRAMbank = bank;
}

StateCPU EngineThread::getStateCPU()
{
	return stateCPU;
}

StatePPU EngineThread::getStatePPU()
{
	return statePPU;
}

