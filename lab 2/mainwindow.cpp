
/**
*@file
*@brief file with a description of methods and functions
*
*this file contains a description of the class  mainwindow
*/




#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Graph.h"
#include "transfer_to_matrix.hpp"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>




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
   // ui->labelWeightString->hide();
    ui->ButtonAddEdge->hide();
    ui->EnterFinishPoint->hide();
    ui->EnterStartPoint->hide();
    ui->EnterWeightInt->hide();
    ui->EnterWeightDouble->hide();
    ui->HideGraphButton->hide();
   // ui->EnterWeightString->hide();
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
    ui->EnterFinishPoint->setMaxLength(10);
    ui->EnterStartPoint->setMaxLength(10);
    ui->EnterWeightInt->setMaxLength(10);
    ui->EnterWeightDouble->setMaxLength(10);
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

    ui->BackButton->hide();
    ui->ExitButton->show();
}

void MainWindow::HideMenu()
{
    ui->IntegerButton->hide();
    ui->DoubleButton->hide();

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
    //ui->labelWeightString->hide();
    ui->EnterWeightInt->clear();
    ui->EnterWeightDouble->clear();
    //ui->EnterWeightString->clear();
    start_error = "";
    finish_error="";
    weight_error="";
    start_ok = false;
    finish_ok = false;
    weight_ok = false;
    ui->ErrorText->clear();
    ui->EnterWeightInt->hide();
    ui->EnterWeightDouble->hide();
    //ui->EnterWeightString->hide();
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



/**
 * @brief when you click on the "show graph" button, it displays in the window a visualization of the construction of a minimal skeletal tree of a graph with a template int
 * @param edge_int -initial graph
 * @param ed_int - min kist tree
 */

void ShowGraphEdgesInt(const std::vector<Edge<int>>& edge_int,const std::vector<Edge<int>>& ed_int, QGraphicsView* view)
{
    std::map<int, int> vertices;
    std::map<int, std::pair<int,int>> pos_vertices;
    pos_vertices[1] = std::make_pair(100, -400);
    pos_vertices[2] = std::make_pair(300, -300);
    pos_vertices[3] = std::make_pair(400, -100);
    pos_vertices[4] = std::make_pair(400, 100);
    pos_vertices[5] = std::make_pair(300, 300);
    pos_vertices[6] = std::make_pair(100, 400);
    pos_vertices[12] = std::make_pair(-100, -400);
    pos_vertices[11] = std::make_pair(-300, -300);
    pos_vertices[10] = std::make_pair(-400, -100);
    pos_vertices[9] = std::make_pair(-400, 100);
    pos_vertices[8] = std::make_pair(-300, 300);
    pos_vertices[7] = std::make_pair(-100, 400);
    for (auto i = edge_int.begin(); i != edge_int.end(); i++)
    {
        vertices[i->GetStart()] = 1;
        vertices[i->GetFinish()] = 1;
    }
    QGraphicsScene* Q = new QGraphicsScene();
    Q->setSceneRect(-500,-500,1000,1000);
    for (int i = 1; i < 13; i++)
        if (vertices[i])
        {
            QGraphicsEllipseItem* rect= new QGraphicsEllipseItem();
            rect->setBrush(Qt::blue);
            QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i));
            text->setPos(pos_vertices[i].first +30, pos_vertices[i].second);
            text->setDefaultTextColor(Qt::yellow);
            rect->setRect(pos_vertices[i].first, pos_vertices[i].second,50,50);
            Q->addItem(rect);
            Q->addItem(text);
        }

    vector<pair<QGraphicsLineItem*,pair<int,int>>> arr;
    for (auto i : edge_int)
    {
        QGraphicsLineItem* l = new QGraphicsLineItem();
        l->setLine(pos_vertices[i.GetStart()].first+25, pos_vertices[i.GetStart()].second+25,
                pos_vertices[i.GetFinish()].first+25, pos_vertices[i.GetFinish()].second+25);
        arr.push_back({l,{i.GetStart(),i.GetFinish()}});
        QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i.GetWeight()));
        text->setPos((pos_vertices[i.GetStart()].first + pos_vertices[i.GetFinish()].first)/2 +25,
                (pos_vertices[i.GetStart()].second + pos_vertices[i.GetFinish()].second)/2 + 25);
        text->setDefaultTextColor(Qt::blue);
        Q->addItem(l);
        Q->addItem(text);
    }

    view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Graph View");
    view->show();

    auto *effect = new QGraphicsDropShadowEffect(nullptr);

    effect->setColor(Qt::blue);
    effect->setOffset(0);
    effect->setBlurRadius(5);

    for(auto i : ed_int){
     //this_thread::sleep_for(chrono::milliseconds(3000));



        for(int j=0;j < static_cast<int>(arr.size());j++){
            if(arr[j].second.first==i.GetStart() && arr[j].second.second==i.GetFinish()){
                arr[j].first->setPen(QPen(Qt::green, 5));
                arr[j].first->setGraphicsEffect(effect);

               /* long long k=0;
                while(k<500000000)
                        k++;*/
                view->repaint();
                break;
            }
        }

    }
}

void MainWindow::CloseView()
{

}
/**
 * @brief when you click on the "show graph" button, it displays in the window a visualization of the construction of a minimal skeletal tree of a graph with a template double
 * @param edge_int -initial graph
 * @param ed_int - min kist tree
*/
void ShowGraphEdgesDouble(const std::vector<Edge<double>>& edge_int,const std::vector<Edge<double>>& ed_int, QGraphicsView *view)
{
    std::map<int, int> vertices;
    std::map<int, std::pair<int,int>> pos_vertices;
    pos_vertices[1] = std::make_pair(100, -400);
    pos_vertices[2] = std::make_pair(300, -300);
    pos_vertices[3] = std::make_pair(400, -100);
    pos_vertices[4] = std::make_pair(400, 100);
    pos_vertices[5] = std::make_pair(300, 300);
    pos_vertices[6] = std::make_pair(100, 400);
    pos_vertices[12] = std::make_pair(-100, -400);
    pos_vertices[11] = std::make_pair(-300, -300);
    pos_vertices[10] = std::make_pair(-400, -100);
    pos_vertices[9] = std::make_pair(-400, 100);
    pos_vertices[8] = std::make_pair(-300, 300);
    pos_vertices[7] = std::make_pair(-100, 400);
    for (auto i = edge_int.begin(); i != edge_int.end(); i++)
    {
        vertices[i->GetStart()] = 1;
        vertices[i->GetFinish()] = 1;
    }
    QGraphicsScene* Q = new QGraphicsScene();
    Q->setSceneRect(-500,-500,1000,1000);
    for (int i = 1; i < 13; i++)
        if (vertices[i])
        {
            QGraphicsEllipseItem* rect= new QGraphicsEllipseItem();
            rect->setBrush(Qt::blue);
            QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i));
            text->setPos(pos_vertices[i].first +30, pos_vertices[i].second);
            text->setDefaultTextColor(Qt::yellow);
            rect->setRect(pos_vertices[i].first, pos_vertices[i].second,50,50);
            Q->addItem(rect);
            Q->addItem(text);
        }

    vector<pair<QGraphicsLineItem*,pair<int,int>>> arr;

    for (auto i : edge_int)
    {
        QGraphicsLineItem* l = new QGraphicsLineItem();
        l->setLine(pos_vertices[i.GetStart()].first+25, pos_vertices[i.GetStart()].second+35,
                pos_vertices[i.GetFinish()].first+25, pos_vertices[i.GetFinish()].second+25);

        arr.push_back({l,{i.GetStart(),i.GetFinish()}});

        QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i.GetWeight()));

        text->setPos((pos_vertices[i.GetStart()].first + pos_vertices[i.GetFinish()].first)/2+25,
                (pos_vertices[i.GetStart()].second + pos_vertices[i.GetFinish()].second)/2+25);
        text->setDefaultTextColor(Qt::blue);
        Q->addItem(l);
        Q->addItem(text);

    }



    view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Graph View");
    view->show();



       auto *effect = new QGraphicsDropShadowEffect(nullptr);

       effect->setColor(Qt::blue);
       effect->setOffset(0);
       effect->setBlurRadius(5);

       for(auto i : ed_int){
        //this_thread::sleep_for(chrono::milliseconds(3000));


           for(int j=0;j < static_cast<int>(arr.size());j++){
               if(arr[j].second.first==i.GetStart() && arr[j].second.second==i.GetFinish()){
                   arr[j].first->setPen(QPen(Qt::green, 5));
                   arr[j].first->setGraphicsEffect(effect);

                  /* long long k=0;
                   while(k<500000000)
                           k++;*/
                   view->repaint();
                   break;
               }
           }

       }




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
        ui->EnterStartPoint->setStyleSheet("color: red");
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
        ui->EnterFinishPoint->setStyleSheet("color: red");
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
        ui->EnterWeightInt->setStyleSheet("color: red");
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
        ui->EnterWeightDouble->setStyleSheet("color: red");
        ui->ErrorText->setText("Field is empty.");
        weight_error = "Field is empty.\n";
    }
    ShowAddEdge();
    ShowErrors();
}



void MainWindow::on_BackButton_clicked()
{
    ShowMenu();
    HideLineEdit();
    ui->HideGraphButton->hide();
    edge_int.clear();
    edge_double.clear();

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
        ui->TableGraph->setItem((ui->EnterFinishPoint->text().toInt() - 1), (ui->EnterStartPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightInt->text()));
        ui->EnterWeightInt->clear();
    }
    if (type == "double")
    {
        Edge<double> a = CreateEdgeDouble(ui->EnterStartPoint->text(), ui->EnterFinishPoint->text(), ui->EnterWeightDouble->text());
          edge_double.push_back(a);
        ui->TableGraph->setItem((ui->EnterStartPoint->text().toInt() -1), (ui->EnterFinishPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightDouble->text()));
        ui->TableGraph->setItem((ui->EnterFinishPoint->text().toInt() - 1), (ui->EnterStartPoint->text().toInt() -1),
                                new QTableWidgetItem (ui->EnterWeightDouble->text()));
        ui->EnterWeightDouble->clear();
    }

    start_ok = false;
    finish_ok = false;
    weight_ok = false;
    ui->EnterStartPoint->clear();
    ui->EnterFinishPoint->clear();
    ui->ButtonAddEdge->hide();
}

void MainWindow::on_ShowGraphButton_clicked()
{
   if(type == "int")
   {
       if(edge_int.size())
       {
           std::vector<std::vector<std::pair<int,std::pair<int,int>>>> err=transfer_to_matrix(edge_int);
           matrix_of_graph<int> gr(err);
           Graph_Node_Iterator<int, matrix_of_graph<int>> Graph(gr);
           if(Check_Connected(err))
           {
               auto ed_int= algorithm_Kruscall(Graph);
               ShowGraphEdgesInt(edge_int,ed_int,view);
           }
           else
               QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \nдобавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
       }
       else
           QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \nдобавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
    }
    if(type == "double")
    {
        if(edge_double.size())
        {
            std::vector<std::vector<std::pair<double,std::pair<int,int>>>> err=transfer_to_matrix(edge_double);
            matrix_of_graph<double> gr(err);
            Graph_Node_Iterator<double, matrix_of_graph<double>> Graph(gr);
            if(Check_Connected(err))
            {
                auto  ed_double= algorithm_Kruscall(Graph);
                ShowGraphEdgesDouble(edge_double,ed_double, view);
            }
            else
                QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \nдобавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
        }
        else
            QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \nдобавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
    }
    ui->HideGraphButton->show();
    ui->ShowGraphButton->hide();
}

void MainWindow::on_HideGraphButton_clicked()
{
    view=nullptr;
    ui->ShowGraphButton->show();
    ui->HideGraphButton->hide();
}
