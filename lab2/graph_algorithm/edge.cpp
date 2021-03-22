#include "edge.h"

bool IsNumber(const QString& num)
{
    for (auto i : num)
        if (i > '9' && i < '0')
            return false;
    return true;
}
/*
QString IntegerPartOfNumber(const QString& d)
{
    QString result;
    for (auto i = d.begin(); i != d.end(); i++)
    {
        if(*i=='.')
            break;
        result += *i;
    }
    return result;
}*/

void CheckValues(const QString& start, const QString& finish)
{
    if (start.size() > 3)
        throw std::logic_error("Start point is greater than largest possible value(999): " + start.toStdString());
    if (finish.size() > 3)
        throw std::logic_error("Finish point is greater than largest possible value(999): " + finish.toStdString());
}

Edge<std::string> CreateEdgeString(const QString& start, const QString& finish, const QString& weight)
{
    try {
        CheckValues(start, finish);
    }  catch (std::logic_error& e) {
        throw e;
    }
    t_data<std::string> el;
    if (weight.toStdString() > el.T_MAX())
        throw std::logic_error("Weight is greater than largest possible value(" + el.T_MAX() + "): " + weight.toStdString());
    return Edge<std::string>(start.toInt(), finish.toInt(), weight.toStdString());
}

Edge<int> CreateEdgeInt(const QString& start, const QString& finish, const QString& weight)
{
    try {
        CheckValues(start, finish);
    }  catch (std::logic_error& e) {
        throw e;
    }
    t_data<int> el;
    if (weight > QString::number(el.T_MAX()))
        throw std::logic_error("Weight is greater than largest possible value(" + std::to_string(el.T_MAX()) + "): " + weight.toStdString());
    return Edge<int>(start.toInt(), finish.toInt(), weight.toInt());
}

Edge<double> CreateEdgeDouble(const QString& start, const QString& finish, const QString& weight)
{
    try {
        CheckValues(start, finish);
    }  catch (std::logic_error& e) {
        throw e;
    }
    t_data<double> el;
    if (weight > QString::number(el.T_MAX()))
        throw std::logic_error("Weight is greater than largest possible value(" + std::to_string(el.T_MAX()) + "): " + weight.toStdString());
    return Edge<double>(start.toInt(), finish.toInt(), weight.toDouble());
}
