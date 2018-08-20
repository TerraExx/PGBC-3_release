#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>

#include "ui_MainDisplay.h"
#include "EngineThread.h"
#include "DebugDisplay.h"

class MainDisplay : public QMainWindow
{
private:
	Q_OBJECT

	Ui::MainDisplayClass ui;
	EngineThread *engineThread = nullptr;
	DebugDisplay DbgDisplay;

public:
	MainDisplay(QWidget *parent = Q_NULLPTR);
	~MainDisplay();

public slots:
	void loadROM();
	void loadROMDebug();
};
