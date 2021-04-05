/**
 *@file
 *@brief header file containing the definition function transfer_to_matrix
 */

#ifndef TRANSFER_TO_MATRIX_HPP
#define TRANSFER_TO_MATRIX_HPP


#include <vector>
#include "Edge.h"
#include "T_data.h"

using namespace std;


/**
 *@brief converts a list of edges into an adjacency matrix
 *@param edges list of edges
 *@return result -adjency matrix graph
 */
template <typename T>
vector<vector<pair<T,pair<int,int>>>> transfer_to_matrix(vector<Edge<T>> edges){

    if(!edges.size()) return {};

     t_data<T>* td = new t_data<T>;
    T INF = td->T_MAX();
    T null = td->T_NULL();
    delete td;
    std::string noll="0\n";

    vector<pair<T,pair<int,int>>> nil(12,{null,{0,0}});

    vector<vector<pair<T,pair<int,int>>>> result(12,nil);

    for(int i=0;i<edges.size();i++){
        result[edges[i].GetStart()-1][edges[i].GetFinish()-1].first=edges[i].GetWeight();
        result[edges[i].GetFinish()-1][edges[i].GetStart()-1].first=edges[i].GetWeight();
        result[edges[i].GetFinish()-1][edges[i].GetStart()-1].second={edges[i].GetStart(),edges[i].GetFinish()};
        result[edges[i].GetStart()-1][edges[i].GetFinish()-1].second={edges[i].GetStart(),edges[i].GetFinish()};

    }
    int j=0;
    while(j<result.size()){
        if(result[j]==nil){
            for(int i=j;i<result.size()-1;i++)
                result[i]=result[i+1];
            result.pop_back();

        }
        else ++j;
    }



    int v=0;

    while(v<result[0].size()){

        bool t=false;
        for(int k=0;k<result.size();k++){

                if(result[k][v].first!=null){
                    t=true;
                    break;
            }

        }
        if(!t){

            for(int k=0;k<result.size();k++){
                for(int m=v;m<result[0].size();m++)
                    result[k][m]=result[k][m+1];
                result[k].pop_back();
            }



        }
        else { v++;}

    }

    return result;
}







#endif // TRANSFER_TO_MATRIX_HPP
