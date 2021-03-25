#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H
#include <iostream>
#include <exception>
#include "template_data/t_data.h"
#include "QString"

template <class T>
class Edge
{
private:
    int start_point;
    int finish_point;
    T weight;
public:
    Edge(const int& start, const int& finish, const T& w) : start_point(start), finish_point(finish), weight(w) {};

    int GetStart() const
    {
        return start_point;
    }

    int GetFinish() const
    {
        return finish_point;
    }

    T GetWeight() const
    {
        return weight;
    }
};

bool IsInteger(const QString& num);
bool IsDouble(const QString& d);

Edge<std::string> CreateEdgeString(const QString& start, const QString& finish, const QString& weight);
Edge<int> CreateEdgeInt(const QString& start, const QString& finish, const QString& weight);
Edge<double> CreateEdgeDouble(const QString& start, const QString& finish, const QString& weight);

#endif // GRAPH_LIST_H
