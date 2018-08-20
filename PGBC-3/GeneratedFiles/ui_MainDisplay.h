/********************************************************************************
** Form generated from reading UI file 'MainDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDISPLAY_H
#define UI_MAINDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainDisplayClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionLoad_Rom;
    QAction *actionExit_2;
    QAction *actionLoad_Rom_Debug;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    MyOpenGLWidget *MainOpenGLDisplay;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDebug;

    void setupUi(QMainWindow *MainDisplayClass)
    {
        if (MainDisplayClass->objectName().isEmpty())
            MainDisplayClass->setObjectName(QStringLiteral("MainDisplayClass"));
        MainDisplayClass->resize(480, 432);
        MainDisplayClass->setMinimumSize(QSize(160, 144));
        actionOpen = new QAction(MainDisplayClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainDisplayClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLoad_Rom = new QAction(MainDisplayClass);
        actionLoad_Rom->setObjectName(QStringLiteral("actionLoad_Rom"));
        actionExit_2 = new QAction(MainDisplayClass);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        actionLoad_Rom_Debug = new QAction(MainDisplayClass);
        actionLoad_Rom_Debug->setObjectName(QStringLiteral("actionLoad_Rom_Debug"));
        centralWidget = new QWidget(MainDisplayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainOpenGLDisplay = new MyOpenGLWidget(centralWidget);
        MainOpenGLDisplay->setObjectName(QStringLiteral("MainOpenGLDisplay"));

        verticalLayout->addWidget(MainOpenGLDisplay);

        MainDisplayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainDisplayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        MainDisplayClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuFile->addAction(actionLoad_Rom);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuDebug->addAction(actionLoad_Rom_Debug);

        retranslateUi(MainDisplayClass);

        QMetaObject::connectSlotsByName(MainDisplayClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainDisplayClass)
    {
        MainDisplayClass->setWindowTitle(QApplication::translate("MainDisplayClass", "PGBC-3", nullptr));
        actionOpen->setText(QApplication::translate("MainDisplayClass", "Loda ROM", nullptr));
        actionExit->setText(QApplication::translate("MainDisplayClass", "Exit", nullptr));
        actionLoad_Rom->setText(QApplication::translate("MainDisplayClass", "Load Rom", nullptr));
        actionExit_2->setText(QApplication::translate("MainDisplayClass", "Exit", nullptr));
        actionLoad_Rom_Debug->setText(QApplication::translate("MainDisplayClass", "Load Rom", nullptr));
        menuFile->setTitle(QApplication::translate("MainDisplayClass", "File", nullptr));
        menuDebug->setTitle(QApplication::translate("MainDisplayClass", "Debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDisplayClass: public Ui_MainDisplayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDISPLAY_H
