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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QLineEdit *EnterStartPoint;
    QLabel *labelStartPoint;
    QLabel *labelFinishPoint;
    QLineEdit *EnterFinishPoint;
    QLineEdit *EnterWeightInt;
    QLabel *labelWeightInt;
    QLabel *labelWeightFloat;
    QLabel *labelWeightString;
    QPushButton *ButtonAddEdge;
    QTextEdit *ErrorText;
    QLabel *labelError;
    QLineEdit *EnterWeightDouble;
    QLineEdit *EnterWeightString;
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
        EnterStartPoint = new QLineEdit(centralwidget);
        EnterStartPoint->setObjectName(QString::fromUtf8("EnterStartPoint"));
        EnterStartPoint->setGeometry(QRect(30, 60, 201, 22));
        labelStartPoint = new QLabel(centralwidget);
        labelStartPoint->setObjectName(QString::fromUtf8("labelStartPoint"));
        labelStartPoint->setGeometry(QRect(30, 40, 201, 16));
        labelFinishPoint = new QLabel(centralwidget);
        labelFinishPoint->setObjectName(QString::fromUtf8("labelFinishPoint"));
        labelFinishPoint->setGeometry(QRect(30, 90, 201, 16));
        EnterFinishPoint = new QLineEdit(centralwidget);
        EnterFinishPoint->setObjectName(QString::fromUtf8("EnterFinishPoint"));
        EnterFinishPoint->setGeometry(QRect(30, 110, 201, 22));
        EnterWeightInt = new QLineEdit(centralwidget);
        EnterWeightInt->setObjectName(QString::fromUtf8("EnterWeightInt"));
        EnterWeightInt->setGeometry(QRect(30, 160, 201, 22));
        labelWeightInt = new QLabel(centralwidget);
        labelWeightInt->setObjectName(QString::fromUtf8("labelWeightInt"));
        labelWeightInt->setGeometry(QRect(30, 140, 231, 16));
        labelWeightFloat = new QLabel(centralwidget);
        labelWeightFloat->setObjectName(QString::fromUtf8("labelWeightFloat"));
        labelWeightFloat->setGeometry(QRect(30, 140, 231, 16));
        labelWeightString = new QLabel(centralwidget);
        labelWeightString->setObjectName(QString::fromUtf8("labelWeightString"));
        labelWeightString->setGeometry(QRect(30, 140, 231, 16));
        ButtonAddEdge = new QPushButton(centralwidget);
        ButtonAddEdge->setObjectName(QString::fromUtf8("ButtonAddEdge"));
        ButtonAddEdge->setGeometry(QRect(80, 200, 93, 28));
        ErrorText = new QTextEdit(centralwidget);
        ErrorText->setObjectName(QString::fromUtf8("ErrorText"));
        ErrorText->setGeometry(QRect(30, 260, 201, 141));
        labelError = new QLabel(centralwidget);
        labelError->setObjectName(QString::fromUtf8("labelError"));
        labelError->setGeometry(QRect(30, 240, 121, 16));
        EnterWeightDouble = new QLineEdit(centralwidget);
        EnterWeightDouble->setObjectName(QString::fromUtf8("EnterWeightDouble"));
        EnterWeightDouble->setGeometry(QRect(30, 160, 201, 22));
        EnterWeightString = new QLineEdit(centralwidget);
        EnterWeightString->setObjectName(QString::fromUtf8("EnterWeightString"));
        EnterWeightString->setGeometry(QRect(30, 160, 201, 22));
        MainWindow->setCentralWidget(centralwidget);
        BackButton->raise();
        IntegerButton->raise();
        DoubleButton->raise();
        StringButton->raise();
        ExitButton->raise();
        EnterStartPoint->raise();
        labelStartPoint->raise();
        labelFinishPoint->raise();
        EnterFinishPoint->raise();
        EnterWeightInt->raise();
        labelWeightInt->raise();
        labelWeightFloat->raise();
        labelWeightString->raise();
        ButtonAddEdge->raise();
        ErrorText->raise();
        labelError->raise();
        EnterWeightDouble->raise();
        EnterWeightString->raise();
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
        labelStartPoint->setText(QCoreApplication::translate("MainWindow", "Enter start point [0-999](integer)", nullptr));
        labelFinishPoint->setText(QCoreApplication::translate("MainWindow", "Enter finish point [0-999](integer)", nullptr));
        labelWeightInt->setText(QCoreApplication::translate("MainWindow", "Enter weight of edge[0-999](integer)", nullptr));
        labelWeightFloat->setText(QCoreApplication::translate("MainWindow", "Enter weight of edge[0-999](float)", nullptr));
        labelWeightString->setText(QCoreApplication::translate("MainWindow", "Enter weight of edge[0-ZZZZZ](text)", nullptr));
        ButtonAddEdge->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        labelError->setText(QCoreApplication::translate("MainWindow", "Errors messages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
