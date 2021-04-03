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
    vector<vector<pair<int,pair<int,int>>>> err(4);
     err[0] = { {0,{0,0}},{4,{0,1}},{5,{0,2}},{6,{0,3}} };
     err[1] = { {4,{1,0}},{0,{1,1}},{6,{1,2}},{3,{1,3}} };
     err[2] = { {5,{2,0}},{6,{2,1}},{0,{2,2}},{6,{2,3}}};
     err[3] = { {6,{3,0}},{3,{3,1}},{6,{3,2}},{0,{3,3}} };
    matrix_of_graph<int> gr(err);


    Graph_Node_Iterator<int, matrix_of_graph<int>> Graph(gr);

    algorithm_Kruscall(Graph);
    w.show();


    return a.exec();

}
