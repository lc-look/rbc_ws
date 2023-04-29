/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controlWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *controlWindow)
    {
        if (controlWindow->objectName().isEmpty())
            controlWindow->setObjectName(QString::fromUtf8("controlWindow"));
        controlWindow->resize(800, 600);
        centralwidget = new QWidget(controlWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        controlWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(controlWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        controlWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(controlWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        controlWindow->setStatusBar(statusbar);

        retranslateUi(controlWindow);

        QMetaObject::connectSlotsByName(controlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controlWindow)
    {
        controlWindow->setWindowTitle(QApplication::translate("controlWindow", "controlWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class controlWindow: public Ui_controlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
