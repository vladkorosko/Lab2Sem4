#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "template_data/t_data.h"
#include "edge.h"
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

        node = { matrix.get_length(0,0),matrix.get_vertex_num(0,0) };
        i = 0; j = 0;
        end_h=end_v = false;
    };

    void First_horizontal() {

        node = { matrix.get_length(i,0),matrix.get_vertex_num(i,0) };
        j = 0;
        end_h = false;

    };
    void First_verticall() {

        node = { matrix.get_length(0,j),matrix.get_vertex_num(0,j) };
        i = 0;
        end_v = false;

    };
    void First_ficticall() {
        index = 0;
    }


    void Next_horizontal() {

        if (matrix.get_size()-1 > j){
            node.first = matrix.get_length(i, ++j);
            node.second =matrix.get_vertex_num(i,j);}

         if (matrix.get_size() == j)
            end_h = true;

        else  if (matrix.get_size() - 1 == j)
            j++;
    };

    void Next_verticall() {
        if (matrix.get_size() - 1 == i)
            i++;

        else if (matrix.get_size() - 1 > i){
            node.first = matrix.get_length(++i, j);
            node.second= matrix.get_vertex_num(i,j);}

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

    pair<int,int> get_ver_num(){
         return node.second;
    }

    void Set(vector<vector<pair<T,pair<int,int>>>> m) {
        matrix.set(m);
    }

    void Set(vector<Edge<T>> ed){

        int n=ed.size();

        t_data<T>* td = new t_data<T>;
        T null = td->T_NULL();
        delete td;
        vector<pair<T,pair<int,int>>> a(n,{null,{0,0}});

         vector<vector<pair<T,pair<int,int>>>> mt(n,a);
        for(int i=0;i<n;i++){
            if(ed.GetWight()!=null){
          mt[ed.GetStart()-1][ed.GetFinish()-1].first=ed.GetWight();
          mt[ed.GetFinish()-1][ed.GetStart()-1].first=ed.GetWight();
          mt[ed.GetFinish()-1][ed.GetStart()-1].second={ed.GetStart(),ed.GetFinish()};
          mt[ed.GetStart()-1][ed.GetFinish()-1].second={ed.GetStart(),ed.GetFinish()};  }
        }

        int j=0;
        while(j<mt.size()){

            if(mt.size()==a){
             for(int i=j;i<mt.size()-1;i++)
                mt[i]=mt[i+1];
              mt.pop_back();

            }
             else ++j;
        }

        int i=0;

        while(i<mt[0].size()){
            bool t=false;
           for(int k=0;k<mt.size();k++){
               if(mt[i][k]!=null){
                   t=true;
                   break;
               }
           }
           if(!t){
              for(int j=0;j<mt.size();j++){
                  for(int k=i;k<mt[j].size()-1;k++)
                      mt[k][j]=mt[k+1][j];
                  mt[j].pop_back();
              }
           }
           else ++i;
        }

        matrix.set(mt);
    }
};



template <typename T>
class matrix_of_graph {
    friend class Graph_Node_Iterator<T, matrix_of_graph<T>>;
public:

    matrix_of_graph(vector<vector<pair<T,pair<int,int>>>> a) {
        mtrx = a;
    }

    matrix_of_graph() {
        mtrx = { {} };
    }
    void insert(T lenght, int i, int j) {
        mtrx[i][j].first = lenght;
    }

    T get_length(int i, int j) {
        return  mtrx[i][j].first;
    }

    pair<int,int> get_vertex_num(int i, int j){
       return  mtrx[i][j].second;
    }

    int get_size() {
        return mtrx.size();
    }

    void set(vector<vector<pair<T,int>>> m) {
        mtrx = m;
    }

private:
    vector<vector<pair<T,pair<int,int>>>> mtrx;
};



template <typename T>
bool connected_graph(Graph_Node_Iterator<T, matrix_of_graph<T>> Graph) {
    vector<int> vertex;
    t_data<T>* td = new t_data<T>;
    T null = td->T_NULL();
    int P = 0;
    vertex.push_back(P);
    bool t, f;
    int num = 0;
    for (Graph.First_ficticall(); !Graph.isDone_ficticall(); Graph.Next_ficticall())
        num++;
    T node;
    while (vertex.size() < num) {

        f = false;

        for (int i = 0; i < num; i++) {
            Graph.First_absolute();
            for (int k = 0; k < P; k++)
                Graph.Next_verticall();
            for (int k = 0; k < i; k++)
                Graph.Next_horizontal();
            node = Graph.Current();

            if (node != null) {



                t = false;
                for (int k = 0; k < vertex.size(); k++) {
                    if (i == vertex[k])
                        t = true;
                }
                if (!t)
                {
                    f = true;
                    P = i;

                    vertex.push_back(P);
                    break;
                }

            }

        }
        if (!f)
            break;
    }
    if (vertex.size() == num)
        return true;
    else return false;
}


template <typename T>
vector<Edge<T>> algorithm_Kruscall(Graph_Node_Iterator<T, matrix_of_graph<T>>& Graph) {

    t_data<T>* td = new t_data<T>;
    vector< vector<T>> arb = {};
    vector<int> pert = {};
    T INF = td->T_MAX();
    T null = td->T_NULL();

    vector<Edge<T>> kist_graph;

    vector<T> null_ = {};

    for (Graph.First_ficticall(); !Graph.isDone_ficticall(); Graph.Next_ficticall())
        null_.push_back(null);



    int i = 0;
    int arcos = 1;
    for (Graph.First_ficticall(); !Graph.isDone_ficticall(); Graph.Next_ficticall()) {
        arb.push_back(null_);
        pert.push_back(i);
        
        i++;
    }

    int n = i;
    int nA;
    int nB;
    int j;

    int A;
    int B;
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
                    A=Graph.get_ver_num().first;
                    B=Graph.get_ver_num().second;
                }

                j=(j+1)%n;
            }
            i++;
        }



        if (pert[nA] != pert[nB]) {

            arb[nA][nB] = min;
            arb[nB][nA] = min;

            Edge<T> a(A,B,min);
            cout<<A<<" "<<B<<" "<<min<<endl;

            kist_graph.push_back(a);}


            int temp = pert[nB];
            pert[nB] = pert[nA];
            for (int k = 0; k < n; k++)
                if (pert[k] == temp)
                    pert[k] = pert[nA];

            arcos++;
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

    return kist_graph;
}





#endif // GRAPH_H
