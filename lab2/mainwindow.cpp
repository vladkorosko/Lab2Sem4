#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph_algorithm/graph.h"
#include "transfer_to_matrix.hpp"


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
    ui->TableGraph->setRowCount(12);
    ui->TableGraph->setColumnCount(12);
    ui->TableGraph->verticalHeader()->setDefaultSectionSize(40);
    ui->TableGraph->horizontalHeader()->setDefaultSectionSize(40);
    ui->TableGraph->hide();
    ui->ShowGraphButton->hide();
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
    ui->TableGraph->show();
    ui->ShowGraphButton->show();
}

void MainWindow::HideLineEdit()
{
    ui->labelFinishPoint->hide();
    ui->labelStartPoint->hide();
    ui->EnterFinishPoint->hide();
    ui->EnterStartPoint->hide();
    ui->ErrorText->hide();
    ui->labelError->hide();
    ui->TableGraph->hide();
    ui->EnterStartPoint->clear();
    ui->EnterFinishPoint->clear();
    ui->labelWeightFloat->hide();
    ui->labelWeightInt->hide();
    ui->labelWeightString->hide();
    ui->EnterWeightInt->clear();
    ui->EnterWeightDouble->clear();
    ui->EnterWeightString->clear();
    start_error = "";
    finish_error="";
    weight_error="";
    start_ok = false;
    finish_ok = false;
    weight_ok = false;
    ui->ErrorText->clear();
    ui->EnterWeightInt->hide();
    ui->EnterWeightDouble->hide();
    ui->EnterWeightString->hide();
    ui->ButtonAddEdge->hide();
    ui->TableGraph->clear();
    ui->ShowGraphButton->hide();
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

        Edge<int> a = CreateEdgeInt(ui->EnterStartPoint->text(), ui->EnterFinishPoint->text(), ui->EnterWeightInt->text());
       edge_int.push_back(a);
        ui->TableGraph->setItem((ui->EnterStartPoint->text().toInt() - 1), (ui->EnterFinishPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightInt->text()));

        ui->EnterWeightInt->clear();
    }
    if (type == "double")
    {
        Edge<double> a = CreateEdgeDouble(ui->EnterStartPoint->text(), ui->EnterFinishPoint->text(), ui->EnterWeightDouble->text());
          edge_double.push_back(a);
        ui->TableGraph->setItem((ui->EnterStartPoint->text().toInt() -1), (ui->EnterFinishPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightDouble->text()));
        ui->EnterWeightDouble->clear();
    }
    if (type == "string")
    {
        Edge<std::string> a = CreateEdgeString(ui->EnterStartPoint->text(), ui->EnterFinishPoint->text(), ui->EnterWeightString->text());
          edge_string.push_back(a);
        ui->TableGraph->setItem((ui->EnterStartPoint->text().toInt() - 1), (ui->EnterFinishPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightString->text()));
        ui->EnterWeightString->clear();
    }


    ui->EnterStartPoint->clear();
    ui->EnterFinishPoint->clear();
    ui->ButtonAddEdge->hide();
}

void MainWindow::on_ShowGraphButton_clicked()
{
   if(type == "int"){
      //
       for(int i =0 ;i<edge_int.size();i++)
           cout<< edge_int[i].GetStart()<<" "<< edge_int[i].GetFinish()<<" "<< edge_int[i].GetWeight()<<endl;
      vector<vector<pair<int,pair<int,int>>>> err=transfer_to_matrix(edge_int);
      for(int i=0;i<err.size();i++){
           for(int j=0;j<err[i].size();j++)
               cout<<err[i][j].first<<" ";
           cout<<endl;
      }
    }
    if(type == "double"){

       //   Graph_Node_Iterator<double, matrix_of_graph<double>> Graph(edge_double);
    }
    if(type == "string"){

        //  Graph_Node_Iterator<string, matrix_of_graph<string>> Graph(edge_string);
    }




    QGraphicsScene* Q = new QGraphicsScene();
    Q->setSceneRect(-500,-500,1000,1000);
    QGraphicsEllipseItem* rect1= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect2= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect3= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect4= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect5= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect6= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect7= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect8= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect9= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect10= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect11= new QGraphicsEllipseItem();
    QGraphicsEllipseItem* rect12= new QGraphicsEllipseItem();
    rect1->setBrush(Qt::blue);
    rect2->setBrush(Qt::blue);
    rect3->setBrush(Qt::blue);
    rect4->setBrush(Qt::blue);
    rect5->setBrush(Qt::blue);
    rect6->setBrush(Qt::blue);
    rect7->setBrush(Qt::blue);
    rect8->setBrush(Qt::blue);
    rect9->setBrush(Qt::blue);
    rect10->setBrush(Qt::blue);
    rect11->setBrush(Qt::blue);
    rect12->setBrush(Qt::blue);
    rect1->setRect(400, 100,50,50);
    Q->addItem(rect1);
    rect2->setRect(400, -100,50,50);
    Q->addItem(rect2);
    rect3->setRect(-400, -100,50,50);
    Q->addItem(rect3);
    rect4->setRect(-400, 100,50,50);
    Q->addItem(rect4);
    rect5->setRect(100, 400,50,50);
    Q->addItem(rect5);
    rect6->setRect(100, -400,50,50);
    Q->addItem(rect6);
    rect7->setRect(-100, -400,50,50);
    Q->addItem(rect7);
    rect8->setRect(-100, 400,50,50);
    Q->addItem(rect8);
    rect9->setRect(300, 300,50,50);
    Q->addItem(rect9);
    rect10->setRect(-300, 300,50,50);
    Q->addItem(rect10);
    rect11->setRect(-300, -300,50,50);
    Q->addItem(rect11);
    rect12->setRect(300, -300,50,50);
    Q->addItem(rect12);
    QGraphicsView *view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Tutorial app");
    view->show();
}
