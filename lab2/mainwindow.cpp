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
    ui->EnterWeightInt->hide();
    ui->EnterWeightDouble->hide();
    ui->EnterWeightString->hide();
    ui->ErrorText->hide();
    ui->ErrorText->setReadOnly(true);
    ui->labelError->hide();
    ui->ErrorText->setTextColor(Qt::red);
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
    ui->ErrorText->show();
    ui->labelError->show();
}

void MainWindow::HideLineEdit()
{
    ui->labelFinishPoint->hide();
    ui->labelStartPoint->hide();
    ui->EnterFinishPoint->hide();
    ui->EnterStartPoint->hide();
    ui->ErrorText->hide();
    ui->labelError->hide();
}

void MainWindow::ShowAddEdge()
{
    if (start_ok && finish_ok && weight_ok)
        ui->ButtonAddEdge->show();
    else ui->ButtonAddEdge->hide();
}

void MainWindow::on_IntegerButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightInt->show();
    ui->EnterWeightInt->show();
}

void MainWindow::on_DoubleButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightFloat->show();
    ui->EnterWeightDouble->show();
}

void MainWindow::on_StringButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightString->show();
    ui->EnterWeightString->show();
}

void MainWindow::on_EnterStartPoint_textEdited(const QString &arg1)
{
    try{
        CheckEndsOfEdge(arg1, "Start");
        ui->EnterStartPoint->setStyleSheet("color: green");
        ui->ErrorText->clear();
        start_ok = true;
    } catch (const std::logic_error& e) {
        ui->EnterStartPoint->setStyleSheet("color: red");
        ui->ErrorText->setText(e.what());
        start_ok = false;
    }
    if(arg1.size()==0)
    {
        start_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
    }
    ShowAddEdge();
}

void MainWindow::on_EnterFinishPoint_textEdited(const QString &arg1)
{
    try{
        CheckEndsOfEdge(arg1, "Finish");
        ui->EnterFinishPoint->setStyleSheet("color: green");
        ui->ErrorText->clear();
        finish_ok = true;
    } catch (const std::logic_error& e) {
        ui->EnterFinishPoint->setStyleSheet("color: red");
        ui->ErrorText->setText(e.what());
        finish_ok = false;
    }
    if(arg1.size()==0)
    {
        finish_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
    }
    ShowAddEdge();
}

void MainWindow::on_EnterWeightInt_textEdited(const QString &arg1)
{
    try{
        CheckWeightInt(arg1);
        ui->EnterWeightInt->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
    } catch (const std::logic_error& e) {
        ui->EnterWeightInt->setStyleSheet("color: red");
        ui->ErrorText->setText(e.what());
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
    }
    ShowAddEdge();
}

void MainWindow::on_EnterWeightDouble_textEdited(const QString &arg1)
{
    try{
        CheckWeightDouble(arg1);
        ui->EnterWeightDouble->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
    } catch (const std::logic_error& e) {
        ui->EnterWeightDouble->setStyleSheet("color: red");
        ui->ErrorText->setText(e.what());
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
    }
    ShowAddEdge();
}

void MainWindow::on_EnterWeightString_textEdited(const QString &arg1)
{
    try{
        CheckWeightString(arg1);
        ui->EnterWeightString->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
    } catch (const std::logic_error& e) {
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText(e.what());
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
    }
    ShowAddEdge();
}

void MainWindow::on_BackButton_clicked()
{
    ShowMenu();
    HideLineEdit();
    ui->labelWeightFloat->hide();
    ui->labelWeightInt->hide();
    ui->labelWeightString->hide();
    ui->EnterWeightInt->hide();
    ui->EnterWeightDouble->hide();
    ui->EnterWeightString->hide();
    ui->ButtonAddEdge->hide();
}

void MainWindow::on_ExitButton_clicked()
{
    if(DialogMessage("Quit", "If you want to close programm press 'Yes'."))
        qApp->exit();
}



