
/**
  *@file
  *@brief header file
  *
  *contains a classes definition Graph_Node_Iterator,matrix of graph and her methods
  *contains the definition of functions check_connected ,find_min ,allgoritm kruskull, top_that_used
  */


#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "T_data.h"
#include "Edge.h"
#include <iostream>
using namespace std;


/**
 * @brief a class-iterator to bypass the adjacency matrix of the graph
 * @tparam T data type for the edge length of the graph
 * @tparam U the class represented by the graph
 */
template <typename T, typename U>
class Graph_Node_Iterator {
private:
    int index;
   pair<T, pair<int, int>> node;///< rib
    int i;
    int j;
    U matrix;
    bool end_h;
    bool end_v;

public:
    /**
     * @brief Graph_Node_Iterator constructor
     * @param m-object which represents the graph
     */
    Graph_Node_Iterator(U m) {
        matrix = m;
        First_absolute();
        index = 0;
        end_h= false;
        end_v = false;
    }


    /**
     * @brief puts the iterator pointer on the element of the compatibility matrix with indices 1, 1
     */
    void First_absolute() {

        if(matrix.get_size())
        node = { matrix.get_length(0,0),matrix.get_vertex_num(0,0) };
        i = 0; j = 0;
        end_h=end_v = false;
    };
    /**
     * @brief puts the iterator pointer on an element that is in the same row but on the first column
     */
    void First_horizontal() {

          if(matrix.get_size())
        node = { matrix.get_length(i,0),matrix.get_vertex_num(i,0) };
        j = 0;
        end_h = false;

    };

    /**
     * @brief puts the iterator pointer on an element that is in the same column but on the first row
     */
    void First_verticall() {

          if(matrix.get_size())
        node = { matrix.get_length(0,j),matrix.get_vertex_num(0,j) };
        i = 0;
        end_v = false;

    };

    /**
     * @brief resets the pointer number
     */
    void First_ficticall() {
        index = 0;
    }

    /**
     * @brief puts a pointer to the element to the right of the current in the adjacency matrix
     */
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

    /**
     * @brief puts a pointer to an element that is below the current in the adjacency matrix
     */
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

    /**
     * @brief increases the pointer number
     */
    void Next_ficticall() {
        ++index;
    };


    /**
     * @brief checks whether the iterator pointer has not reached the end of the adjacency matrix row
     * @return false if  reached the end of the line , else true
     */
    bool isDone_horizontal() {
        if(end_h)
        j = matrix.get_size() - 1;
        return end_h;
    };


    /**
     * @brief checks whether the iterator pointer has not reached the last row of the adjacency matrix
     * @return  false if  reached the end of the line , else true
     */
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

    /**
     * @brief returns the value of the current edge under the iterator pointer
     * @return value of the current edge
     */
    T Current() {
            return node.first;
    };
\
    /**
     * @brief returns the names of the vertices of the graph which are connected by an edge which is under the iterator pointer
     * @return  names of the vertices of the graph which are connected
     */
    pair<int,int> get_ver_num(){
         return node.second;
    }

    /**
     * @brief inserts an adjacency matrix into an object representing a graph
     * @param m-adjacency matrix of a new graph
     */
    void Set(vector<vector<pair<T,pair<int,int>>>> m) {
        matrix.set(m);
    }

    /**
     * @brief checks the graph to see if it is empty
     * @return true if the graph is not empty ,else false
     */
    bool empty(){
        if(!matrix.get_size())
            return true;
        else return false;
    }


};


/**
 * @brief class for the description and interaction of the graph represented by the adjacency matrix
 * @tparam T data type for the edge length of the graph
 */
template <typename T>
class matrix_of_graph {
    friend class Graph_Node_Iterator<T, matrix_of_graph<T>>;
public:
    /**
     * @brief  constructor a class matrix_of_graph
     * @param a - adjacency matrix of a new graph
     */
    matrix_of_graph(vector<vector<pair<T,pair<int,int>>>> a) {
        mtrx = a;
    }

    /**
     * @brief constructor matrix_of_graph
     */
    matrix_of_graph() {
        mtrx = { {} };
    }

    /**
     * @brief insert an edge between the vertices of the graph i and j
     * @param lenght length of rib
     *@param i -first name vertex rib
     * @param j -second name vertex rib
     */
    void insert(T lenght, int i, int j) {
        mtrx[i][j].first = lenght;
    }

    /**
     * @brief returns the length of the edge lying between the vertices of the graph i and j
     * @param i -first name vertex rib
     * @param j -second name vertex rib
     * @return length of rib
     */
    T get_length(int i, int j) {
        return  mtrx[i][j].first;
    }

    /**
     * @brief returns the name of the vertices lying on the edge with the coefficients in the adjacency matrix i and j
     * @param i first cooficient
     * @param j second cooficient
     * @return names vertex
     */
    pair<int,int> get_vertex_num(int i, int j){
       return  mtrx[i][j].second;
    }
    /**
     * @brief finds the number of vertices in the graph
     * @return number of vertex in graph
     */
    int get_size() {
        return mtrx.size();
    }

    /**
     * @brief inserts an adjacency matrix into an object representing a graph
     * @param m-adjacency matrix of a new graph
     */
    void set(vector<vector<pair<T,pair<int,int>>>> m) {
        mtrx = m;
    }


private:
    vector<vector<pair<T,pair<int,int>>>> mtrx;///<adjacency matrix of graph
};




/**
 *@brief looking for the minimum skeletal tree of the graph
 *@tparam T data type for the edge length of the graph
 *@param Graph - itterator for graph
 *@return kist_graph -a sequential list of skeletal ribs to visualize this algorithm
 */
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

/**
 *@brief looks for the index of the smallest element of the array
 *@tparam T -data type of element array
 *@param a -array
 *@return index of the smallest element
 */
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
/**
*@brief counts uninsulated vertices and writes it to an array tops
*@tparam T  data type of element adjency matrix
*@param Matrix adjency matrix of graph
*@return tops
*/
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

   /**
    *@brief looks for possible paths between different vertices to check for connectivity
    *@tparam T  data type of element adjency matrix
    *@param[in] Matrix adjency matrix of graph
    *@param[in] index_of_top number of tops-array
    *@param[in] type - type of graph
    *@param[out] way -new tops array
    *@return tops
  */
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

  /**
    *@brief checks whether the graph is connected
    *@tparam T  data type of element adjency matrix
    *@param arr adjency matrix of graph
    *@return true if graph is connected else false
   */
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
