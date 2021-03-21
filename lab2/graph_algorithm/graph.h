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








#endif // GRAPH_H
