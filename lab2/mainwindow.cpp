#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BackButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HideMenu()
{
    ui->IntegerButton->hide();
    ui->DoubleButton->hide();
    ui->StringButton->hide();
    ui->BackButton->show();
    ui->ExitButton->hide();
}

void MainWindow::ShowMenu()
{
    ui->IntegerButton->show();
    ui->DoubleButton->show();
    ui->StringButton->show();
    ui->BackButton->hide();
    ui->ExitButton->show();
}

void MainWindow::on_IntegerButton_clicked()
{
    HideMenu();
}

void MainWindow::on_DoubleButton_clicked()
{
    HideMenu();
}

void MainWindow::on_StringButton_clicked()
{
    HideMenu();
}

void MainWindow::on_BackButton_clicked()
{
    ShowMenu();
}
/*
void MainWindow::on_ExitButton_clicked()
{
    delete ui;
}*/
