/********************************************************************************
** Form generated from reading UI file 'DebugDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGDISPLAY_H
#define UI_DEBUGDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "myopengl_vram_debug.h"

QT_BEGIN_NAMESPACE

class Ui_DebugDisplay
{
public:
    QAction *actionStep;
    QAction *actionRunToFrame;
    QAction *actionRun;
    QAction *actionPause;
    QWidget *centralWidget;
    QGroupBox *groupCPU;
    QGridLayout *gridLayout_2;
    QLabel *CPU_N_Left;
    QLabel *CPU_N_Right;
    QLabel *CPU_AF_Right;
    QLabel *CPU_BC_Right;
    QLabel *CPU_DE_Left;
    QLabel *CPU_AF_Left;
    QLabel *CPU_BC_Left;
    QLabel *CPU_Z_Left;
    QLabel *CPU_Z_Right;
    QLabel *CPU_CY_Right;
    QLabel *CPU_CY_Left;
    QLabel *CPU_PC_Left;
    QLabel *CPU_IME_Left;
    QLabel *CPU_Clock_Left;
    QLabel *CPU_SP_Left;
    QLabel *CPU_PC_Right;
    QLabel *CPU_Clock_Right;
    QLabel *CPU_SP_Right;
    QLabel *CPU_IME_Right;
    QLabel *CPU_DE_Right;
    QLabel *CPU_HL_Left;
    QLabel *CPU_HL_Right;
    QLabel *CPU_H_Right;
    QLabel *CPU_H_Left;
    QGroupBox *groupPPU;
    QGridLayout *gridLayout;
    QLabel *PPU_View_X_Left;
    QLabel *PPU_View_X_Right;
    QLabel *PPU_Clock_Right;
    QLabel *PPU_State_Left;
    QLabel *PPU_State_Right;
    QLabel *PPU_Line_Left;
    QLabel *PPU_Line_Right;
    QLabel *PPU_Clock_Left;
    QLabel *PPU_View_Y_Left;
    QLabel *PPU_View_Y_Right;
    QGroupBox *groupVRAM;
    MyOpenGL_VRAM_Debug *OpenGLVRAM;
    QPushButton *pushBtnVRAMbank0;
    QPushButton *pushBtnVRAMbank1;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *DebugDisplay)
    {
        if (DebugDisplay->objectName().isEmpty())
            DebugDisplay->setObjectName(QStringLiteral("DebugDisplay"));
        DebugDisplay->resize(438, 660);
        DebugDisplay->setMinimumSize(QSize(0, 0));
        DebugDisplay->setCursor(QCursor(Qt::ArrowCursor));
        actionStep = new QAction(DebugDisplay);
        actionStep->setObjectName(QStringLiteral("actionStep"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/step_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon);
        actionRunToFrame = new QAction(DebugDisplay);
        actionRunToFrame->setObjectName(QStringLiteral("actionRunToFrame"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/frame_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRunToFrame->setIcon(icon1);
        actionRun = new QAction(DebugDisplay);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/run_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon2);
        actionPause = new QAction(DebugDisplay);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/pause_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon3);
        centralWidget = new QWidget(DebugDisplay);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupCPU = new QGroupBox(centralWidget);
        groupCPU->setObjectName(QStringLiteral("groupCPU"));
        groupCPU->setGeometry(QRect(10, 10, 221, 141));
        gridLayout_2 = new QGridLayout(groupCPU);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(10);
        CPU_N_Left = new QLabel(groupCPU);
        CPU_N_Left->setObjectName(QStringLiteral("CPU_N_Left"));

        gridLayout_2->addWidget(CPU_N_Left, 4, 2, 1, 1);

        CPU_N_Right = new QLabel(groupCPU);
        CPU_N_Right->setObjectName(QStringLiteral("CPU_N_Right"));

        gridLayout_2->addWidget(CPU_N_Right, 4, 3, 1, 1);

        CPU_AF_Right = new QLabel(groupCPU);
        CPU_AF_Right->setObjectName(QStringLiteral("CPU_AF_Right"));

        gridLayout_2->addWidget(CPU_AF_Right, 2, 1, 1, 1);

        CPU_BC_Right = new QLabel(groupCPU);
        CPU_BC_Right->setObjectName(QStringLiteral("CPU_BC_Right"));

        gridLayout_2->addWidget(CPU_BC_Right, 2, 3, 1, 1);

        CPU_DE_Left = new QLabel(groupCPU);
        CPU_DE_Left->setObjectName(QStringLiteral("CPU_DE_Left"));

        gridLayout_2->addWidget(CPU_DE_Left, 3, 0, 1, 1);

        CPU_AF_Left = new QLabel(groupCPU);
        CPU_AF_Left->setObjectName(QStringLiteral("CPU_AF_Left"));

        gridLayout_2->addWidget(CPU_AF_Left, 2, 0, 1, 1);

        CPU_BC_Left = new QLabel(groupCPU);
        CPU_BC_Left->setObjectName(QStringLiteral("CPU_BC_Left"));

        gridLayout_2->addWidget(CPU_BC_Left, 2, 2, 1, 1);

        CPU_Z_Left = new QLabel(groupCPU);
        CPU_Z_Left->setObjectName(QStringLiteral("CPU_Z_Left"));

        gridLayout_2->addWidget(CPU_Z_Left, 4, 0, 1, 1);

        CPU_Z_Right = new QLabel(groupCPU);
        CPU_Z_Right->setObjectName(QStringLiteral("CPU_Z_Right"));

        gridLayout_2->addWidget(CPU_Z_Right, 4, 1, 1, 1);

        CPU_CY_Right = new QLabel(groupCPU);
        CPU_CY_Right->setObjectName(QStringLiteral("CPU_CY_Right"));

        gridLayout_2->addWidget(CPU_CY_Right, 5, 3, 1, 1);

        CPU_CY_Left = new QLabel(groupCPU);
        CPU_CY_Left->setObjectName(QStringLiteral("CPU_CY_Left"));

        gridLayout_2->addWidget(CPU_CY_Left, 5, 2, 1, 1);

        CPU_PC_Left = new QLabel(groupCPU);
        CPU_PC_Left->setObjectName(QStringLiteral("CPU_PC_Left"));

        gridLayout_2->addWidget(CPU_PC_Left, 1, 2, 1, 1);

        CPU_IME_Left = new QLabel(groupCPU);
        CPU_IME_Left->setObjectName(QStringLiteral("CPU_IME_Left"));

        gridLayout_2->addWidget(CPU_IME_Left, 0, 2, 1, 1);

        CPU_Clock_Left = new QLabel(groupCPU);
        CPU_Clock_Left->setObjectName(QStringLiteral("CPU_Clock_Left"));

        gridLayout_2->addWidget(CPU_Clock_Left, 0, 0, 1, 1);

        CPU_SP_Left = new QLabel(groupCPU);
        CPU_SP_Left->setObjectName(QStringLiteral("CPU_SP_Left"));

        gridLayout_2->addWidget(CPU_SP_Left, 1, 0, 1, 1);

        CPU_PC_Right = new QLabel(groupCPU);
        CPU_PC_Right->setObjectName(QStringLiteral("CPU_PC_Right"));

        gridLayout_2->addWidget(CPU_PC_Right, 1, 3, 1, 1);

        CPU_Clock_Right = new QLabel(groupCPU);
        CPU_Clock_Right->setObjectName(QStringLiteral("CPU_Clock_Right"));

        gridLayout_2->addWidget(CPU_Clock_Right, 0, 1, 1, 1);

        CPU_SP_Right = new QLabel(groupCPU);
        CPU_SP_Right->setObjectName(QStringLiteral("CPU_SP_Right"));

        gridLayout_2->addWidget(CPU_SP_Right, 1, 1, 1, 1);

        CPU_IME_Right = new QLabel(groupCPU);
        CPU_IME_Right->setObjectName(QStringLiteral("CPU_IME_Right"));

        gridLayout_2->addWidget(CPU_IME_Right, 0, 3, 1, 1);

        CPU_DE_Right = new QLabel(groupCPU);
        CPU_DE_Right->setObjectName(QStringLiteral("CPU_DE_Right"));

        gridLayout_2->addWidget(CPU_DE_Right, 3, 1, 1, 1);

        CPU_HL_Left = new QLabel(groupCPU);
        CPU_HL_Left->setObjectName(QStringLiteral("CPU_HL_Left"));

        gridLayout_2->addWidget(CPU_HL_Left, 3, 2, 1, 1);

        CPU_HL_Right = new QLabel(groupCPU);
        CPU_HL_Right->setObjectName(QStringLiteral("CPU_HL_Right"));

        gridLayout_2->addWidget(CPU_HL_Right, 3, 3, 1, 1);

        CPU_H_Right = new QLabel(groupCPU);
        CPU_H_Right->setObjectName(QStringLiteral("CPU_H_Right"));

        gridLayout_2->addWidget(CPU_H_Right, 5, 1, 1, 1);

        CPU_H_Left = new QLabel(groupCPU);
        CPU_H_Left->setObjectName(QStringLiteral("CPU_H_Left"));

        gridLayout_2->addWidget(CPU_H_Left, 5, 0, 1, 1);

        groupPPU = new QGroupBox(centralWidget);
        groupPPU->setObjectName(QStringLiteral("groupPPU"));
        groupPPU->setGeometry(QRect(240, 10, 191, 141));
        gridLayout = new QGridLayout(groupPPU);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        PPU_View_X_Left = new QLabel(groupPPU);
        PPU_View_X_Left->setObjectName(QStringLiteral("PPU_View_X_Left"));

        gridLayout->addWidget(PPU_View_X_Left, 4, 0, 1, 1);

        PPU_View_X_Right = new QLabel(groupPPU);
        PPU_View_X_Right->setObjectName(QStringLiteral("PPU_View_X_Right"));

        gridLayout->addWidget(PPU_View_X_Right, 4, 1, 1, 1);

        PPU_Clock_Right = new QLabel(groupPPU);
        PPU_Clock_Right->setObjectName(QStringLiteral("PPU_Clock_Right"));

        gridLayout->addWidget(PPU_Clock_Right, 0, 1, 1, 1);

        PPU_State_Left = new QLabel(groupPPU);
        PPU_State_Left->setObjectName(QStringLiteral("PPU_State_Left"));

        gridLayout->addWidget(PPU_State_Left, 2, 0, 1, 1);

        PPU_State_Right = new QLabel(groupPPU);
        PPU_State_Right->setObjectName(QStringLiteral("PPU_State_Right"));

        gridLayout->addWidget(PPU_State_Right, 2, 1, 1, 1);

        PPU_Line_Left = new QLabel(groupPPU);
        PPU_Line_Left->setObjectName(QStringLiteral("PPU_Line_Left"));

        gridLayout->addWidget(PPU_Line_Left, 3, 0, 1, 1);

        PPU_Line_Right = new QLabel(groupPPU);
        PPU_Line_Right->setObjectName(QStringLiteral("PPU_Line_Right"));

        gridLayout->addWidget(PPU_Line_Right, 3, 1, 1, 1);

        PPU_Clock_Left = new QLabel(groupPPU);
        PPU_Clock_Left->setObjectName(QStringLiteral("PPU_Clock_Left"));

        gridLayout->addWidget(PPU_Clock_Left, 0, 0, 1, 1);

        PPU_View_Y_Left = new QLabel(groupPPU);
        PPU_View_Y_Left->setObjectName(QStringLiteral("PPU_View_Y_Left"));

        gridLayout->addWidget(PPU_View_Y_Left, 5, 0, 1, 1);

        PPU_View_Y_Right = new QLabel(groupPPU);
        PPU_View_Y_Right->setObjectName(QStringLiteral("PPU_View_Y_Right"));

        gridLayout->addWidget(PPU_View_Y_Right, 5, 1, 1, 1);

        groupVRAM = new QGroupBox(centralWidget);
        groupVRAM->setObjectName(QStringLiteral("groupVRAM"));
        groupVRAM->setGeometry(QRect(10, 160, 422, 457));
        OpenGLVRAM = new MyOpenGL_VRAM_Debug(groupVRAM);
        OpenGLVRAM->setObjectName(QStringLiteral("OpenGLVRAM"));
        OpenGLVRAM->setGeometry(QRect(10, 16, 286, 430));
        OpenGLVRAM->setMinimumSize(QSize(286, 430));
        pushBtnVRAMbank0 = new QPushButton(groupVRAM);
        pushBtnVRAMbank0->setObjectName(QStringLiteral("pushBtnVRAMbank0"));
        pushBtnVRAMbank0->setGeometry(QRect(321, 19, 75, 23));
        pushBtnVRAMbank1 = new QPushButton(groupVRAM);
        pushBtnVRAMbank1->setObjectName(QStringLiteral("pushBtnVRAMbank1"));
        pushBtnVRAMbank1->setGeometry(QRect(321, 56, 75, 23));
        DebugDisplay->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(DebugDisplay);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DebugDisplay->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionStep);
        mainToolBar->addAction(actionRunToFrame);

        retranslateUi(DebugDisplay);

        QMetaObject::connectSlotsByName(DebugDisplay);
    } // setupUi

    void retranslateUi(QMainWindow *DebugDisplay)
    {
        DebugDisplay->setWindowTitle(QApplication::translate("DebugDisplay", "DebugDisplay", nullptr));
        actionStep->setText(QApplication::translate("DebugDisplay", "Step", nullptr));
        actionRunToFrame->setText(QApplication::translate("DebugDisplay", "Frame", nullptr));
        actionRun->setText(QApplication::translate("DebugDisplay", "Run", nullptr));
        actionPause->setText(QApplication::translate("DebugDisplay", "Pause", nullptr));
        groupCPU->setTitle(QApplication::translate("DebugDisplay", "CPU", nullptr));
        CPU_N_Left->setText(QApplication::translate("DebugDisplay", "N:", nullptr));
        CPU_N_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_AF_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_BC_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_DE_Left->setText(QApplication::translate("DebugDisplay", "DE:", nullptr));
        CPU_AF_Left->setText(QApplication::translate("DebugDisplay", "AF:", nullptr));
        CPU_BC_Left->setText(QApplication::translate("DebugDisplay", "BC:", nullptr));
        CPU_Z_Left->setText(QApplication::translate("DebugDisplay", "Z:", nullptr));
        CPU_Z_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_CY_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_CY_Left->setText(QApplication::translate("DebugDisplay", "CY:", nullptr));
        CPU_PC_Left->setText(QApplication::translate("DebugDisplay", "PC:", nullptr));
        CPU_IME_Left->setText(QApplication::translate("DebugDisplay", "IME:", nullptr));
        CPU_Clock_Left->setText(QApplication::translate("DebugDisplay", "Clock:", nullptr));
        CPU_SP_Left->setText(QApplication::translate("DebugDisplay", "SP:", nullptr));
        CPU_PC_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_Clock_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_SP_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_IME_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_DE_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_HL_Left->setText(QApplication::translate("DebugDisplay", "HL:", nullptr));
        CPU_HL_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_H_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        CPU_H_Left->setText(QApplication::translate("DebugDisplay", "H:", nullptr));
        groupPPU->setTitle(QApplication::translate("DebugDisplay", "PPU", nullptr));
        PPU_View_X_Left->setText(QApplication::translate("DebugDisplay", "View X:", nullptr));
        PPU_View_X_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        PPU_Clock_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        PPU_State_Left->setText(QApplication::translate("DebugDisplay", "State:", nullptr));
        PPU_State_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        PPU_Line_Left->setText(QApplication::translate("DebugDisplay", "Line:", nullptr));
        PPU_Line_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        PPU_Clock_Left->setText(QApplication::translate("DebugDisplay", "Clock:", nullptr));
        PPU_View_Y_Left->setText(QApplication::translate("DebugDisplay", "View Y:", nullptr));
        PPU_View_Y_Right->setText(QApplication::translate("DebugDisplay", "n/a", nullptr));
        groupVRAM->setTitle(QApplication::translate("DebugDisplay", "VRAM", nullptr));
        pushBtnVRAMbank0->setText(QApplication::translate("DebugDisplay", "Bank 0", nullptr));
        pushBtnVRAMbank1->setText(QApplication::translate("DebugDisplay", "Bank 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugDisplay: public Ui_DebugDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGDISPLAY_H
