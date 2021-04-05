/*!
\file
\brief header file

this class contains a description of the Edge class
*/



#ifndef GRAPH_LIST_H
#define EDGE_H
#pragma once
#include <iostream>
#include <exception>
#include "T_data.h"
#include "QString"



/**
 *@brief iterator for the list of edges of the graph
 *@tparam T  data type of rib
 */
template <class T>
class Edge
{
private:
    int start_point;
    int finish_point;
    T weight;
public:
    /**
     * @brief constructor a class Edge
     * @param start - first vertex of rib
     * @param finish - second vertex of rib
     * @param w - length of rib
     */
    Edge(const int& start, const int& finish, const T& w) : start_point(start), finish_point(finish), weight(w) {};

    /**
     * @brief  return name first vertex of rib
     * @return first vertex of rib
     */
    int GetStart() const
    {
        return start_point;
    }

    /**
     * @brief  return name second vertex of rib
     * @return second vertex of rib
     */
    int GetFinish() const
    {
        return finish_point;
    }

    /**
     * @brief  return length of rib
     * @return lenght of rib
     */
    T GetWeight() const
    {
        return weight;
    }
};

/**
 * @brief checks the entered character in the window or has the type int entered into the window
 * @param num -Qstring elemenr
 * @return  true if it's int else false
 */
bool IsInteger(const QString& num);

/**
 * @brief checks the entered character in the window or has the type double entered into the window
 * @param num -Qstring element
 * @return  true if it's double else false
 */
bool IsDouble(const QString& d);

/**
 * @brief checks whether the vertex vertex names entered in the window are empty
 * @param point - name  first  vertex
 * @param name  - name second vertex
 */
void CheckEndsOfEdge(const QString& point, const QString& name);


/**
 * @brief checks the equality of two elements entered in the window
 * @param lhs - first QString element
 * @param rhs - second QString element
 * @return true if they are equal else false
 */
bool BiggerQString(const QString& lhs, const QString& rhs);
//bool BiggerQString(const std::string& lhs, const std::string& rhs);


/**
 * @brief checks at once two edits a line on correctness of input of edges
 * @param lhs  - first line edit
 * @param rhs  - second line edit
 * @return  true if all correct else false
 */
bool SmallerQString(const QString& lhs, const QString& rhs);
//bool SmallerQString(const std::string& lhs, const std::string& rhs);



/**
 * @brief checks if there is a type of rib length - int
 * @param weight -Qstring element
 * @return  true if it's int  else false
 */
void CheckWeightInt(const QString& weight);

/**
 * @brief checks if there is a type of rib length - double
 * @param weight -Qstring element
 * @return  true if it's double  else false
 */
void CheckWeightDouble(const QString& weight);

/**
 * @brief checks if there is a type of rib length - string
 * @param weight -Qstring element
 * @return  true if it's string  else false
 */
void CheckWeightString(const QString& weight);


/**
 * @brief creates an edge with a pattern string
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<std::string> CreateEdgeString(const QString& start, const QString& finish, const QString& weight);

/**
 * @brief creates an edge with a pattern int
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<int> CreateEdgeInt(const QString& start, const QString& finish, const QString& weight);

/**
 * @brief creates an edge with a pattern double
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<double> CreateEdgeDouble(const QString& start, const QString& finish, const QString& weight);

#endif // GRAPH_LIST_H
