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

        if(matrix.get_size())
        node = { matrix.get_length(0,0),matrix.get_vertex_num(0,0) };
        i = 0; j = 0;
        end_h=end_v = false;
    };

    void First_horizontal() {

          if(matrix.get_size())
        node = { matrix.get_length(i,0),matrix.get_vertex_num(i,0) };
        j = 0;
        end_h = false;

    };
    void First_verticall() {

          if(matrix.get_size())
        node = { matrix.get_length(0,j),matrix.get_vertex_num(0,j) };
        i = 0;
        end_v = false;

    };
    void First_ficticall() {
        index = 0;
    }


    void Next_horizontal() {
  if(matrix.get_size()){
        if (matrix.get_size()-1 > j){
            node.first = matrix.get_length(i, ++j);
            node.second =matrix.get_vertex_num(i,j);}

         if (matrix.get_size() == j)
            end_h = true;

        else  if (matrix.get_size() - 1 == j)
            j++;
  }
    };

    void Next_verticall() {
          if(matrix.get_size()){
        if (matrix.get_size() - 1 == i)
            i++;

        else if (matrix.get_size() - 1 > i){
            node.first = matrix.get_length(++i, j);
            node.second= matrix.get_vertex_num(i,j);}

         if (matrix.get_size() == i)
            end_v = true;
          }
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
    bool empty(){
        if(!matrix.get_size())
            return true;
        else return false;
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

    void set(vector<vector<pair<T,pair<int,int>>>> m) {
        mtrx = m;
    }


private:
    vector<vector<pair<T,pair<int,int>>>> mtrx;
};


/*
template <typename T>
bool connected_graph(Graph_Node_Iterator<T, matrix_of_graph<T>> Graph) {

    if(Graph.empty())
        return false;

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
}*/


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


            kist_graph.push_back(a);}


            int temp = pert[nB];
            pert[nB] = pert[nA];
            for (int k = 0; k < n; k++)
                if (pert[k] == temp)
                    pert[k] = pert[nA];

            arcos++;
        }




    return kist_graph;
}

template <typename T>
int find_min(vector<T>& a)
{
    t_data<T>* td = new t_data<T>;
    T INF = td->T_MAX();
    T null = td->T_NULL();

    T min = null;
    int index = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i]!=null && min==null)
        {
            min = a[i];
            index = i;
        }
        if(a[i]!=null && min!=null)
            if (min > a[i])
            {
                min = a[i];
                index = i;
            }
    }
    a[index] = null;
    if (min == null)
        index = -1;
    return index;
}


template<typename T>
vector<int> Tops_that_used(vector<vector<T>> Matrix)
  {
    t_data<T>* td = new t_data<T>;
    T INF = td->T_MAX();
    T null = td->T_NULL();
    vector<int> tops (Matrix.size(),0);
    for (int i = 0; i < Matrix.size(); i++)
      for (int j = 0; j < Matrix.size(); j++)
        if (Matrix[i][j]!=null)
        {
          tops[i] = 1;
          tops[j] = 1;
        }
    return tops;
  }

template<typename T>
  void Connected_tops(int type, vector<int> &tops, vector<int> &way, int index_of_top,vector<vector<T>> Matrix)
  {
      t_data<T>* td = new t_data<T>;
      T INF = td->T_MAX();
      T null = td->T_NULL();
    tops[index_of_top] = 2;
    way.push_back(index_of_top);
    if (type)
    {
      for (int i = 0; i < tops.size(); i++)
      {

        if (Matrix[index_of_top][i]!=null)
          if (tops[i] == 1)
            Connected_tops(type, tops, way, i,Matrix);
      }
    }
    else
    {
      vector<T> a = Matrix[index_of_top];
      int min = find_min(a);
      while (min >= 0)
      {
        if (tops[min] == 1)
          Connected_tops(type, tops, way, min,Matrix);
        min = find_min(a);
      }
    }
  }

  template<typename T>
  bool Check_Connected(vector<vector<pair<T,pair<int,int>>>> arr)
  {
      t_data<T>* td = new t_data<T>;
      T INF = td->T_MAX();
      T null = td->T_NULL();
      vector<T> nil(arr.size(),null);
      vector<vector<T>> Matrix (arr.size(),nil);

      for(int i=0;i<arr.size();i++)
          for(int j=0;j<arr.size();j++)
              Matrix[i][j]=arr[i][j].first;

    bool Connected_graph = true;
    vector<int> tops = Tops_that_used(Matrix);
    vector<vector<T>> table = Matrix;

    int n = 0;
    while (!tops[n])
      n++;
    vector<int> way;
    Connected_tops(1, tops, way, n,Matrix);
    for (int i = 0; i < tops.size(); i++)
      if (tops[i] == 1)
        Connected_graph = false;
    return Connected_graph;
  }





#endif // GRAPH_H
