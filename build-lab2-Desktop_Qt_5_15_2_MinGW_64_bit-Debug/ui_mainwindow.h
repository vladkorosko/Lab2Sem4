/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *IntegerButton;
    QPushButton *DoubleButton;
    QPushButton *StringButton;
    QPushButton *ExitButton;
    QPushButton *BackButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(825, 585);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        IntegerButton = new QPushButton(centralwidget);
        IntegerButton->setObjectName(QString::fromUtf8("IntegerButton"));
        IntegerButton->setGeometry(QRect(260, 40, 251, 81));
        DoubleButton = new QPushButton(centralwidget);
        DoubleButton->setObjectName(QString::fromUtf8("DoubleButton"));
        DoubleButton->setGeometry(QRect(260, 170, 251, 81));
        StringButton = new QPushButton(centralwidget);
        StringButton->setObjectName(QString::fromUtf8("StringButton"));
        StringButton->setGeometry(QRect(260, 300, 251, 81));
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(260, 430, 251, 81));
        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(260, 430, 251, 81));
        MainWindow->setCentralWidget(centralwidget);
        BackButton->raise();
        IntegerButton->raise();
        DoubleButton->raise();
        StringButton->raise();
        ExitButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 825, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        IntegerButton->setText(QCoreApplication::translate("MainWindow", "Integer Graph", nullptr));
        DoubleButton->setText(QCoreApplication::translate("MainWindow", "Double Graph", nullptr));
        StringButton->setText(QCoreApplication::translate("MainWindow", "String Graph", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        BackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
