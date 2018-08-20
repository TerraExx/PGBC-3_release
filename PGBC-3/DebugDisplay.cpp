#include "DebugDisplay.h"

#include <iostream>
#include <QString>

DebugDisplay::DebugDisplay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

	connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(runHandler()));
	connect(ui.actionPause, SIGNAL(triggered()), this, SLOT(pauseHandler()));
	connect(ui.actionStep, SIGNAL(triggered()), this, SLOT(stepHandler()));
	connect(ui.actionRunToFrame, SIGNAL(triggered()), this, SLOT(frameHandler()));

	connect(ui.pushBtnVRAMbank0, SIGNAL(clicked()), this, SLOT(VRAMbank0Handler()));
	connect(ui.pushBtnVRAMbank1, SIGNAL(clicked()), this, SLOT(VRAMbank1Handler()));
}

DebugDisplay::~DebugDisplay()
{
}

void DebugDisplay::init(EngineThread * engineThreadPtr)
{
	engineThread = engineThreadPtr;
	connect(engineThread, SIGNAL(gotUpdateCPU()), this, SLOT(updateCPU()));
	connect(engineThread, SIGNAL(gotUpdatePPU()), this, SLOT(updatePPU()));

	/* Start the "worker" thread */
	engineThread->start();
}

void DebugDisplay::updateCPU()
{
	StateCPU state = engineThread->getStateCPU();

	const char ZERO_FLAG_MASK = 0x80;
	const char SUB_FLAG_MASK = 0x40;
	const char HALF_CARRY_FLAG_MASK = 0x20;
	const char CARRY_FLAG_MASK = 0x10;

	const char ZERO_FLAG_OFFSET = 0x07;
	const char SUB_FLAG_OFFSET = 0x06;
	const char HALF_CARRY_FLAG_OFFSET = 0x05;
	const char CARRY_FLAG_OFFSET = 0x04;

	ui.CPU_Clock_Right->setText(QString("%1").arg(state.CurrentClock, 0, 10, QLatin1Char('0')));
	ui.CPU_SP_Right->setText(QString("0x") + QString("%1").arg(state.SP, 4, 16, QLatin1Char('0')).toUpper());
	ui.CPU_PC_Right->setText(QString("0x") + QString("%1").arg(state.PC, 4, 16, QLatin1Char('0')).toUpper());
	ui.CPU_IME_Right->setText(QString("%1").arg(state.IME, 0, 16));

	ui.CPU_AF_Right->setText(QString("0x") + QString("%1").arg(state.AF, 4, 16, QLatin1Char('0')).toUpper());
	ui.CPU_BC_Right->setText(QString("0x") + QString("%1").arg(state.BC, 4, 16, QLatin1Char('0')).toUpper());
	ui.CPU_DE_Right->setText(QString("0x") + QString("%1").arg(state.DE, 4, 16, QLatin1Char('0')).toUpper());
	ui.CPU_HL_Right->setText(QString("0x") + QString("%1").arg(state.HL, 4, 16, QLatin1Char('0')).toUpper());

	ui.CPU_Z_Right->setText(QString("%1").arg((static_cast<unsigned char>(state.AF) & ZERO_FLAG_MASK) >> ZERO_FLAG_OFFSET));
	ui.CPU_N_Right->setText(QString("%1").arg((static_cast<unsigned char>(state.AF) & SUB_FLAG_MASK) >> SUB_FLAG_OFFSET));
	ui.CPU_H_Right->setText(QString("%1").arg((static_cast<unsigned char>(state.AF) & HALF_CARRY_FLAG_MASK) >> HALF_CARRY_FLAG_OFFSET));
	ui.CPU_CY_Right->setText(QString("%1").arg((static_cast<unsigned char>(state.AF) & CARRY_FLAG_MASK) >> CARRY_FLAG_OFFSET));
}

void DebugDisplay::updatePPU()
{
	StatePPU state = engineThread->getStatePPU();

	ui.PPU_Clock_Right->setText(QString("%1").arg(state.PPUclock, 0, 10, QLatin1Char('0')));

	switch (state.PPUstate)
	{
	case H_BLANK:
		ui.PPU_State_Right->setText(QString("H BLANK"));
		break;
	case V_BLANK:
		ui.PPU_State_Right->setText(QString("V BLANK"));
		break;
	case OAM_SEARCH:
		ui.PPU_State_Right->setText(QString("OAM SEARCH"));
		break;
	case PIXEL_TRANSFER:
		ui.PPU_State_Right->setText(QString("PIXEL TRANSFER"));
		break;
	case OFF:
		ui.PPU_State_Right->setText(QString("OFF"));
		break;
	}

	ui.PPU_Line_Right->setText(QString("%1").arg(state.lineBeingDrawn, 0, 10, QLatin1Char('0')));
	ui.PPU_View_X_Right->setText(QString("%1").arg(state.viewPort_X, 0, 10, QLatin1Char('0')));
	ui.PPU_View_Y_Right->setText(QString("%1").arg(state.viewPort_Y, 0, 10, QLatin1Char('0')));
}

void DebugDisplay::runHandler()
{
	engineThread->setState(Engine::RUN);
}

void DebugDisplay::pauseHandler()
{
	engineThread->setState(Engine::BREAKPOINT);
}

void DebugDisplay::stepHandler()
{
	engineThread->setState(Engine::STEP);
}

void DebugDisplay::frameHandler()
{
	engineThread->setState(Engine::RUN_TO_FRAME);
}

void DebugDisplay::VRAMbank0Handler()
{
	engineThread->setVRAMbank(0);
}

void DebugDisplay::VRAMbank1Handler()
{
	engineThread->setVRAMbank(1);
}