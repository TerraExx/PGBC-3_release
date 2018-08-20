#pragma once

#include <QThread>

#include "GameBoy.h"
#include "MyOpenGLWidget.h"
#include "VRAM_Debug.h"

namespace Engine
{
	using engineState = enum
	{
		RUN,
		RUN_TO_FRAME,
		STEP,
		BREAKPOINT,
		INVALID
	};

	using requestUpdate = enum
	{
		CPU_UPDATE,
		INVALID_UPDATE
	};

}

class EngineThread : public QThread
{
private:
	Q_OBJECT

	GameBoy *GB = nullptr;
	Engine::engineState state = Engine::INVALID;
	Engine::engineState newState = Engine::INVALID;
	unsigned char VRAMbank = 0;
	unsigned char newVRAMbank = 0;
	bool shouldStop = false;
	StateCPU stateCPU;
	StatePPU statePPU;
	MyOpenGL_VRAM_Debug *VRAM_GLcontext;

	VRAM_Debug VRAM_DBG;

	unsigned int tempPPUclock = 0;

	void updateStateCPU();
	void updateStatePPU();

	void updateDebugWindow();

public:
	void initGB(QString ROMdir, MyOpenGLWidget *openGLContex, MyOpenGL_VRAM_Debug *opGLContex_VRAM);

	EngineThread(Engine::engineState state);
	~EngineThread();

	void stop();
	void setState(Engine::engineState newState);
	void setVRAMbank(unsigned char bank);

	StateCPU getStateCPU();
	StatePPU getStatePPU();

signals:
	void gotUpdateCPU();
	void gotUpdatePPU();

protected:
	void run();
};

