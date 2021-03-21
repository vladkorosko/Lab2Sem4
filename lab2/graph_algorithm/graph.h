#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "template_data/t_data.h"

#include <iostream>
using namespace std;

template <typename T, typename U>
class Graph_Node_Iterator {
private:
    int index;
   pair<T, pair<int, int>> node;
    int i;
    int j;
    U matrix;
    bool end_h;
    bool end_v;

public:

    Graph_Node_Iterator(U m) {
        matrix = m;
        First_absolute();
        index = 0;
        end_h= false;
        end_v = false;
    }

    void First_absolute() {

        node = { matrix.get_length(0,0),{0,0} };
        i = 0; j = 0;
        end_h=end_v = false;
    };

    void First_horizontal() {

        node = { matrix.get_length(i,0),{i,0} };
        j = 0;
        end_h = false;

    };
    void First_verticall() {

        node = { matrix.get_length(0,j),{0,j} };
        i = 0;
        end_v = false;

    };
    void First_ficticall() {
        index = 0;
    }


    void Next_horizontal() {

        if (matrix.get_size()-1 > j)
            node.first = matrix.get_length(i, ++j);

         if (matrix.get_size() == j)
            end_h = true;

        else  if (matrix.get_size() - 1 == j)
            j++;


    };

    void Next_verticall() {


        if (matrix.get_size() - 1 == i)
            i++;

        else if (matrix.get_size() - 1 > i)
            node.first = matrix.get_length(++i, j);

         if (matrix.get_size() == i)
            end_v = true;


    };

    void Next_ficticall() {
        ++index;
    };



    bool isDone_horizontal() {
        if(end_h)
        j = matrix.get_size() - 1;
        return end_h;
    };

    bool isDone_verticall() {
        if (end_v)
        i = matrix.get_size() - 1;

        return end_v;
    };

    bool isDone_ficticall() {
        if (index == matrix.get_size())
        return true;
        else return false;
    }

    T Current() {
            return node.first;
    };


};



template <typename T>
class matrix_of_graph {
    friend class Graph_Node_Iterator<T, matrix_of_graph<T>>;
public:

    matrix_of_graph(vector<vector<T>> a) {
        mtrx = a;
    }

    matrix_of_graph() {
        mtrx = { {} };
    }
    void insert(T lenght, int i, int j) {
        mtrx[i][j] = lenght;
    }

    T get_length(int i, int j) {
        return  mtrx[i][j];
    }

    int get_size() {
        return mtrx.size();
    }

    void set(vector<vector<T>> m) {
        mtrx = m;
    }

private:
    vector<vector<T>> mtrx;
};


template <typename T>
void algorithm_Kruscall(Graph_Node_Iterator<T, matrix_of_graph<T>>& Graph) {

    t_data<T>* td = new t_data<T>;
    vector< vector<T>> arb = {};
    vector<int> pert = {};
    T INF = td->T_MAX();
    T null = td->T_NULL();


    vector<T> null_ = {};

    for (Graph.First_ficticall(); !Graph.isDone_ficticall(); Graph.Next_ficticall())
        null_.push_back(null);



    int i = 0;
    int arcos = 1;
    for (Graph.First_ficticall(); !Graph.isDone_ficticall(); Graph.Next_ficticall()) {
        arb.push_back(null_);
        pert.push_back(i);
        cout << pert[i] << "--";
        i++;
    }

    int n = i;
    int nA;
    int nB;
    int j;

    Graph.First_ficticall();
    while (arcos<n) {

        T min = INF;

        Graph.First_absolute();
        i = 0;  j = 0;
        for (Graph.First_verticall(); !Graph.isDone_verticall(); Graph.Next_verticall()) {
            for (Graph.First_horizontal(); !Graph.isDone_horizontal(); Graph.Next_horizontal()) {

                if (min > Graph.Current() && pert[i] != pert[j] && Graph.Current() != null) {
                    min = Graph.Current();
                    nA = i;
                    nB = j;
                }

                j=(j+1)%n;
            }
            i++;
        }



        if (pert[nA] != pert[nB]) {

            arb[nA][nB] = min;
            arb[nB][nA] = min;


            int temp = pert[nB];
            pert[nB] = pert[nA];
            for (int k = 0; k < n; k++)
                if (pert[k] == temp)
                    pert[k] = pert[nA];

            arcos++;
        }
    }

    Graph.First_absolute();
    i = 0;
    for (Graph.First_verticall(); !Graph.isDone_verticall(); Graph.Next_verticall()) {
        j = 0;
        for (Graph.First_horizontal(); !Graph.isDone_horizontal(); Graph.Next_horizontal()) {
            cout << arb[i][j];
            j++;
        }
        i++;
        cout << endl;
    }
}

\



#endif // GRAPH_H
