#pragma once

#include <QMainWindow>
#include "ui_DebugDisplay.h"
#include "EngineThread.h"

class DebugDisplay : public QMainWindow
{
private:
	Q_OBJECT

	EngineThread *engineThread = nullptr;

public:
	DebugDisplay(QWidget *parent = Q_NULLPTR);
	~DebugDisplay();

	void init(EngineThread *engineThreadPtr);

	Ui::DebugDisplay ui;

public slots:
	void runHandler();
	void pauseHandler();
	void stepHandler();
	void frameHandler();

	void VRAMbank0Handler();
	void VRAMbank1Handler();

	void updateCPU();
	void updatePPU();
};
