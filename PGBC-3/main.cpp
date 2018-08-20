#include "MainDisplay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	MainDisplay mainWindow;

	mainWindow.show();

	return application.exec();
}
