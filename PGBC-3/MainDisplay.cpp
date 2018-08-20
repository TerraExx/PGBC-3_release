#include "MainDisplay.h"

#include <QFileDialog>
#include <fstream>

MainDisplay::MainDisplay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionLoad_Rom, SIGNAL(triggered()), this, SLOT(loadROM()));
	connect(ui.actionLoad_Rom_Debug, SIGNAL(triggered()), this, SLOT(loadROMDebug()));
}

MainDisplay::~MainDisplay()
{
	/* Clean up all pointers */
	if (engineThread != nullptr)
	{
		delete engineThread;
	}
}

void MainDisplay::loadROM()
{
	/* Get ROM directory */
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));

	/* Instantiate new engine and create a GameBoy */
	engineThread = new EngineThread(Engine::RUN);
	engineThread->initGB(fileName, ui.MainOpenGLDisplay, nullptr);

	/* Start the "worker" thread */
	engineThread->start();
}

void MainDisplay::loadROMDebug()
{
	/* Get ROM directory */
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));

	/* Instantiate new engine and create a GameBoy */
	engineThread = new EngineThread(Engine::BREAKPOINT);
	engineThread->initGB(fileName, ui.MainOpenGLDisplay, DbgDisplay.ui.OpenGLVRAM);


	/* Init and show Debug Display */
	DbgDisplay.init(engineThread);
	DbgDisplay.show();
}

