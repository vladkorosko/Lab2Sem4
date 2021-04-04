#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph_algorithm/graph.h"
#include "transfer_to_matrix.hpp"
#include <QMessageBox>


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

void ShowGraphEdgesInt(const std::vector<Edge<int>>& edge_int)
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
            text->setPos(pos_vertices[i].first +20, pos_vertices[i].second+10);
            text->setDefaultTextColor(Qt::yellow);
            rect->setRect(pos_vertices[i].first, pos_vertices[i].second,50,50);
            Q->addItem(rect);
            Q->addItem(text);
        }
    for (auto i : edge_int)
    {
        QGraphicsLineItem* l = new QGraphicsLineItem();
        l->setLine(pos_vertices[i.GetStart()].first+25, pos_vertices[i.GetStart()].second+25,
                pos_vertices[i.GetFinish()].first+25, pos_vertices[i.GetFinish()].second+25);
        QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i.GetWeight()));
        text->setPos((pos_vertices[i.GetStart()].first + pos_vertices[i.GetFinish()].first)/2 +25,
                (pos_vertices[i.GetStart()].second + pos_vertices[i.GetFinish()].second)/2 + 25);
        text->setDefaultTextColor(Qt::blue);
        Q->addItem(l);
        Q->addItem(text);
    }
    QGraphicsView *view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Graph View");
    view->show();
}

void ShowGraphEdgesDouble(const std::vector<Edge<double>>& edge_int)
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
            text->setPos(pos_vertices[i].first +20, pos_vertices[i].second+10);
            text->setDefaultTextColor(Qt::yellow);
            rect->setRect(pos_vertices[i].first, pos_vertices[i].second,50,50);
            Q->addItem(rect);
            Q->addItem(text);
        }
    for (auto i : edge_int)
    {
        QGraphicsLineItem* l = new QGraphicsLineItem();
        l->setLine(pos_vertices[i.GetStart()].first+25, pos_vertices[i.GetStart()].second+25,
                pos_vertices[i.GetFinish()].first+25, pos_vertices[i.GetFinish()].second+25);
        QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i.GetWeight()));
        text->setPos((pos_vertices[i.GetStart()].first + pos_vertices[i.GetFinish()].first)/2+25,
                (pos_vertices[i.GetStart()].second + pos_vertices[i.GetFinish()].second)/2+25);
        text->setDefaultTextColor(Qt::blue);
        Q->addItem(l);
        Q->addItem(text);
    }
    QGraphicsView *view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Graph View");
    view->show();
}

void ShowGraphEdgesString(const std::vector<Edge<std::string>>& edge_int)
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
            text->setPos(pos_vertices[i].first +20, pos_vertices[i].second+10);
            text->setDefaultTextColor(Qt::yellow);
            rect->setRect(pos_vertices[i].first, pos_vertices[i].second,50,50);
            Q->addItem(rect);
            Q->addItem(text);
        }
    for (int i = 0; i<static_cast<int>(edge_int.size()); i++)
    {
        QGraphicsLineItem* l = new QGraphicsLineItem();
        l->setLine(pos_vertices[edge_int[i].GetStart()].first+25, pos_vertices[edge_int[i].GetStart()].second+25,
                pos_vertices[edge_int[i].GetFinish()].first+25, pos_vertices[edge_int[i].GetFinish()].second+25);
        QGraphicsTextItem* text = new QGraphicsTextItem(QString::fromStdString(edge_int[i].GetWeight()));
        text->setPos((pos_vertices[edge_int[i].GetStart()].first + pos_vertices[edge_int[i].GetFinish()].first)/2+25,
                (pos_vertices[edge_int[i].GetStart()].second + pos_vertices[edge_int[i].GetFinish()].second)/2+25);
        text->setDefaultTextColor(Qt::blue);
        Q->addItem(l);
        Q->addItem(text);
    }
    QGraphicsView *view = new QGraphicsView(Q);
    view->setRenderHints(QPainter::Antialiasing);
    view->setWindowTitle("Graph View");
    view->show();
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
    edge_int.clear();
    edge_double.clear();
    edge_string.clear();
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
    if (type == "string")
    {
        Edge<std::string> a = CreateEdgeString(ui->EnterStartPoint->text(), ui->EnterFinishPoint->text(), ui->EnterWeightString->text());
          edge_string.push_back(a);
        ui->TableGraph->setItem((ui->EnterStartPoint->text().toInt() - 1), (ui->EnterFinishPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightString->text()));
        ui->TableGraph->setItem((ui->EnterFinishPoint->text().toInt() - 1), (ui->EnterStartPoint->text().toInt() - 1),
                                new QTableWidgetItem (ui->EnterWeightString->text()));
        ui->EnterWeightString->clear();
    }


    ui->EnterStartPoint->clear();
    ui->EnterFinishPoint->clear();
    ui->ButtonAddEdge->hide();
}

void MainWindow::on_ShowGraphButton_clicked()
{
   if(type == "int")
   {
       ShowGraphEdgesInt(edge_int);
       std::vector<std::vector<std::pair<int,std::pair<int,int>>>> err=transfer_to_matrix(edge_int);
       matrix_of_graph<int> gr(err);
       Graph_Node_Iterator<int, matrix_of_graph<int>> Graph(gr);
       if(connected_graph(Graph))
           edge_int= algorithm_Kruscall(Graph);
       else
           QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \n добавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
    }
    if(type == "double")
    {
        ShowGraphEdgesDouble(edge_double);
        std::vector<std::vector<std::pair<double,std::pair<int,int>>>> err=transfer_to_matrix(edge_double);
        matrix_of_graph<double> gr(err);
        Graph_Node_Iterator<double, matrix_of_graph<double>> Graph(gr);
        if(connected_graph(Graph))
            edge_double= algorithm_Kruscall(Graph);
        else
            QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \n добавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");

    }
    if(type == "string")
    {
        ShowGraphEdgesString(edge_string);
        std::vector<std::vector<std::pair<string,std::pair<int,int>>>> err=transfer_to_matrix(edge_string);
        matrix_of_graph<string> gr(err);
        Graph_Node_Iterator<string, matrix_of_graph<string>> Graph(gr);
        if(connected_graph(Graph))
           edge_string= algorithm_Kruscall(Graph);
        else
            QMessageBox::information(this,"Попередження","неможливо виконати алгоритма оскільки граф не є звязним \n добавте декілька ребер так щоб можна було здійснити щлях через усі вами уведені вершини");
    }

}
