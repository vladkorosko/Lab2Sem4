#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

template <typename T,typename U>
class Graph_Node_Iterator{
    typedef typename  pair<T,pair<int,int>>:: graph_node_iterator  Node ;
public :

    Graph_Node_Iterator(U matrix){
        this->matrix=matrix;
        First_absolute();
    }

    void First_absolute(){

        node={matrix.get_length(0,0),{0,0}};
    };

    void First_horizontal(){

        node={matrix.get_length(node.second.first,0),{node.second.first,0}};
    };
    void First_verticall(){

        node={matrix.get_length(0,node.second.second),{0,node.second.second}};
    };

    void Next_absolute(){
        if(matrix.get_lenght()-1==node.second.first && matrix.get_lenght()-1 >node.second.second ){
            node.first=matrix.get_length(0,++node.second.second);
            node.second.first=0;
        }
         if(matrix.get_lenght()-1>node.second.first && matrix.get_lenght()-1 >node.second.second ){
         node.first=matrix.get_length(node.second.first,++node.second.second);
         }
         else return;
    };

    void Next_horizontal(){
        if( matrix.get_lenght()-1 ==node.second.second ){
            node.first=matrix.get_length(0,++node.second.second);
            node.second.first=0;
        }
         if( matrix.get_lenght()-1 >node.second.second ){
         node.first=matrix.get_length(node.second.first,++node.second.second);
         }
         else return;
    };

    void Next_verticall(){


         if( matrix.get_lenght()-1 >node.second.first ){
         node.first=matrix.get_length(++node.second.first,node.second.second);
         }
         else return;
    };

    bool isDone_absolute(){
        return node.second.first==matrix.size_of_graph()-1 && node.second.second==matrix.size_of_graph()-1;
    };

    bool isDone_horizontal(){
        return  node.second.second==matrix.size_of_graph()-1;
    };
    bool isDone_verticall(){
        return  node.second.first==matrix.size_of_graph()-1;
    };


    T Current(){
        return node.first;
    };

private:
    Node node;
    U matrix;
};

template <typename T>
class matrix_of_graph{
    friend class Graph_Node_Iterator<T,matrix_of_graph>;
   public:

    void insert(T lenght,int i,int j){
    mtrx[i][j]=lenght;
    }

    T get_length(int i,int j){
        return  mtrx[i][j];
    }

    int size_of_graph(){
        return mtrx.size();
    }

    void set(vector<vector<T>> m){
        mtrx=m;
    }

private:
    vector<vector<T>> mtrx;

};




#endif // GRAPH_H
