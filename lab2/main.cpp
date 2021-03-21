#include "mainwindow.h"
#include "graph_algorithm/graph.h"
#include <QApplication>
#include <iostream>

#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
