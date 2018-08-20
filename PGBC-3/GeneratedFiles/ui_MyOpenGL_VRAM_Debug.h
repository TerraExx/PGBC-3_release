/********************************************************************************
** Form generated from reading UI file 'MyOpenGL_VRAM_Debug.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYOPENGL_VRAM_DEBUG_H
#define UI_MYOPENGL_VRAM_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOpenGL_VRAM_Debug
{
public:

    void setupUi(QOpenGLWidget *MyOpenGL_VRAM_Debug)
    {
        if (MyOpenGL_VRAM_Debug->objectName().isEmpty())
            MyOpenGL_VRAM_Debug->setObjectName(QStringLiteral("MyOpenGL_VRAM_Debug"));
        MyOpenGL_VRAM_Debug->resize(400, 300);

        retranslateUi(MyOpenGL_VRAM_Debug);

        QMetaObject::connectSlotsByName(MyOpenGL_VRAM_Debug);
    } // setupUi

    void retranslateUi(QOpenGLWidget *MyOpenGL_VRAM_Debug)
    {
        MyOpenGL_VRAM_Debug->setWindowTitle(QApplication::translate("MyOpenGL_VRAM_Debug", "MyOpenGL_VRAM_Debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOpenGL_VRAM_Debug: public Ui_MyOpenGL_VRAM_Debug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYOPENGL_VRAM_DEBUG_H
