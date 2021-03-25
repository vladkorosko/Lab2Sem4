#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BackButton->hide();
    ui->labelFinishPoint->hide();
    ui->labelStartPoint->hide();
    ui->labelWeightFloat->hide();
    ui->labelWeightInt->hide();
    ui->labelWeightString->hide();
    ui->ButtonAddEdge->hide();
    ui->EnterFinishPoint->hide();
    ui->EnterStartPoint->hide();
    ui->EnterWeight->hide();
    ui->ErrorText->hide();
    ui->ErrorText->setReadOnly(true);
    ui->labelError->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::DialogMessage(const std::string& quest, const std::string instruction)
{
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, QString::fromStdString(quest), QString::fromStdString(instruction),
      QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes)
    return true;
  else return false;
}

void MainWindow::ShowMenu()
{
    ui->IntegerButton->show();
    ui->DoubleButton->show();
    ui->StringButton->show();
    ui->BackButton->hide();
    ui->ExitButton->show();
}

void MainWindow::HideMenu()
{
    ui->IntegerButton->hide();
    ui->DoubleButton->hide();
    ui->StringButton->hide();
    ui->BackButton->show();
    ui->ExitButton->hide();
}

void MainWindow::ShowLineEdit()
{
    ui->labelFinishPoint->show();
    ui->labelStartPoint->show();
    ui->EnterFinishPoint->show();
    ui->EnterStartPoint->show();
    ui->EnterWeight->show();
    ui->ErrorText->show();
    ui->labelError->show();
}

void MainWindow::HideLineEdit()
{
    ui->labelFinishPoint->hide();
    ui->labelStartPoint->hide();
    ui->EnterFinishPoint->hide();
    ui->EnterStartPoint->hide();
    ui->EnterWeight->hide();
    ui->ErrorText->hide();
    ui->labelError->hide();
}

void MainWindow::on_IntegerButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightInt->show();
}

void MainWindow::on_DoubleButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightFloat->show();
}

void MainWindow::on_StringButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightString->show();
}

void MainWindow::on_BackButton_clicked()
{
    ShowMenu();
    HideLineEdit();
    ui->labelWeightFloat->hide();
    ui->labelWeightInt->hide();
    ui->labelWeightString->hide();
}

void MainWindow::on_ExitButton_clicked()
{
    if(DialogMessage("Quit", "If you want to close programm press 'Yes'."))
        qApp->exit();
}

void MainWindow::on_EnterStartPoint_textEdited(const QString &arg1)
{

}
