/********************************************************************************
** Form generated from reading UI file 'MyOpenGLWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYOPENGLWIDGET_H
#define UI_MYOPENGLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOpenGLWidget
{
public:

    void setupUi(QOpenGLWidget *MyOpenGLWidget)
    {
        if (MyOpenGLWidget->objectName().isEmpty())
            MyOpenGLWidget->setObjectName(QStringLiteral("MyOpenGLWidget"));
        MyOpenGLWidget->resize(400, 300);

        retranslateUi(MyOpenGLWidget);

        QMetaObject::connectSlotsByName(MyOpenGLWidget);
    } // setupUi

    void retranslateUi(QOpenGLWidget *MyOpenGLWidget)
    {
        MyOpenGLWidget->setWindowTitle(QApplication::translate("MyOpenGLWidget", "MyOpenGLWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOpenGLWidget: public Ui_MyOpenGLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYOPENGLWIDGET_H
