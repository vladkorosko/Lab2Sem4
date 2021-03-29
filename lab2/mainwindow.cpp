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

void MainWindow::ShowErrors()
{
    QString res = start_error + finish_error + weight_error;
    ui->ErrorText->setText(res);
}

void MainWindow::on_IntegerButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightInt->show();
    ui->EnterWeightInt->show();
    type="int";
}

void MainWindow::on_DoubleButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightFloat->show();
    ui->EnterWeightDouble->show();
    type = "double";
}

void MainWindow::on_StringButton_clicked()
{
    HideMenu();
    ShowLineEdit();
    ui->labelWeightString->show();
    ui->EnterWeightString->show();
    type = "string";
}
/*
void MainWindow::Read(QString& value, QString& error, bool& is_ok, void (*f)(const QString&, const QString&), const QString &arg1)
{
    value = arg1;
    try{
        f(arg1, "Start");
        ui->EnterStartPoint->setStyleSheet("color: green");
        ui->ErrorText->clear();
        is_ok = true;
        error="";
    } catch (const std::logic_error& e) {
        ui->EnterStartPoint->setStyleSheet("color: red");
        error = e.what();
        is_ok = false;
    }
    if(arg1.size()==0)
    {
        is_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        error = "Field is empty.";
    }
    ShowAddEdge();
}*/

void MainWindow::on_EnterStartPoint_textEdited(const QString &arg1)
{
    start = arg1;
    try{
        CheckEndsOfEdge(arg1, "Start");
        ui->EnterStartPoint->setStyleSheet("color: green");
        ui->ErrorText->clear();
        start_ok = true;
        start_error="";
    } catch (const std::logic_error& e) {
        ui->EnterStartPoint->setStyleSheet("color: red");
        start_error = e.what();
        start_error += '\n';
        start_ok = false;
    }
    if(arg1.size()==0)
    {
        start_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        start_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
}

void MainWindow::on_EnterFinishPoint_textEdited(const QString &arg1)
{
    finish = arg1;
    try{
        CheckEndsOfEdge(arg1, "Finish");
        ui->EnterFinishPoint->setStyleSheet("color: green");
        ui->ErrorText->clear();
        finish_ok = true;
        finish_error="";
    } catch (const std::logic_error& e) {
        ui->EnterFinishPoint->setStyleSheet("color: red");
        finish_error = e.what();
        finish_error += '\n';
        finish_ok = false;
    }
    if(arg1.size()==0)
    {
        finish_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        finish_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
}

void MainWindow::on_EnterWeightInt_textEdited(const QString &arg1)
{
    weight = arg1;
    try{
        CheckWeightInt(arg1);
        ui->EnterWeightInt->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
        weight_error = "";
    } catch (const std::logic_error& e) {
        ui->EnterWeightInt->setStyleSheet("color: red");
        weight_error = e.what();
        weight_error += '\n';
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        weight_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
}

void MainWindow::on_EnterWeightDouble_textEdited(const QString &arg1)
{
    weight = arg1;
    try{
        CheckWeightDouble(arg1);
        ui->EnterWeightDouble->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
        weight_error = "";
    } catch (const std::logic_error& e) {
        ui->EnterWeightDouble->setStyleSheet("color: red");
        weight_error = e.what();
        weight_error += '\n';
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
        weight_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
}

void MainWindow::on_EnterWeightString_textEdited(const QString &arg1)
{
    weight = arg1;
    try{
        CheckWeightString(arg1);
        ui->EnterWeightString->setStyleSheet("color: green");
        ui->ErrorText->clear();
        weight_ok = true;
        weight_error = "";
    } catch (const std::logic_error& e) {
        ui->EnterWeightString->setStyleSheet("color: red");
        weight_error = e.what();
        weight_error += '\n';
        weight_ok = false;
    }
    if(arg1.size()==0)
    {
        weight_ok=false;
        ui->EnterWeightString->setStyleSheet("color: red");
        weight_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
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



void MainWindow::on_ButtonAddEdge_clicked()
{
    if (type == "int")
    {
        Edge<int> a = CreateEdgeInt(start, finish, weight);
        ui->EnterWeightInt->clear();
    }
    if (type == "double")
    {
        Edge<int> a = CreateEdgeInt(start, finish, weight);
        ui->EnterWeightDouble->clear();
    }
    if (type == "string")
    {
        Edge<int> a = CreateEdgeInt(start, finish, weight);
        ui->EnterWeightString->clear();
    }
    ui->EnterStartPoint->clear();
    ui->EnterFinishPoint->clear();
}
