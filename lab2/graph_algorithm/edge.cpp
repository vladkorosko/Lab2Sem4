#include "edge.h"

bool IsInteger(const QString& num)
{
    for (auto i : num)
        if (i > '9' || i < '0')
            return false;
    return true;
}

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
}

QString FloatPartOfNumber(const QString& d)
{
    QString result;
    bool start = false;
    for (auto i = d.begin();i != d.end(); i++)
    {
        if(start)
            result += *i;
        if(*i=='.')
            start = true;
    }
    return result;
}

bool IsDouble(const QString& d)
{
    return (IntegerPartOfNumber(d).size() != 0
            && IsInteger(FloatPartOfNumber(d)) && IsInteger(IntegerPartOfNumber(d)));
}

bool BiggerQString(const QString& lhs, const QString& rhs)
{
    if (lhs.size()==0&&rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return true;
    if (rhs.size() > lhs.size())
        return false;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
        if(lhs[i]<rhs[i])
            return false;
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}

bool BiggerQString(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size()==0&&rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return true;
    if (rhs.size() > lhs.size())
        return false;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
        if(lhs[i]<rhs[i])
            return false;
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}

bool SmallerQString(const QString& lhs, const QString& rhs)
{
    if (lhs.size()==0 && rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return false;
    if (rhs.size() > lhs.size())
        return true;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
        if(lhs[i]>rhs[i])
            return false;
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}

bool SmallerQString(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size()==0 && rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return false;
    if (rhs.size() > lhs.size())
        return true;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
        if(lhs[i]>rhs[i])
            return false;
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}

void CheckEndsOfEdge(const QString& point, const QString& name)
{
    if(!IsInteger(point))
        throw std::logic_error(name.toStdString() + " point is not an integer number: " + point.toStdString() + ". ");
    if (point.size() > 3)
        throw std::logic_error(name.toStdString() + " point is greater than largest possible value(999): " + point.toStdString()+ ". ");
}

void CheckWeightInt(const QString& weight)
{
    if(!IsInteger(weight))
        throw std::logic_error("Weight is not an integer number: " + weight.toStdString() + ". ");
    if (weight.size() > 3)
        throw std::logic_error("Weight is greater than largest possible value(999): " + weight.toStdString()+ ". ");
}

void CheckWeightDouble(const QString& weight)
{
    if(!IsDouble(weight))
        throw std::logic_error("Weight is not an float number: " + weight.toStdString() + ". ");
    t_data<double> el;
    if (IntegerPartOfNumber(weight).size() > 3 || FloatPartOfNumber(weight).size() > 3)
        throw std::logic_error("Weight is greater than largest possible value(" +
                               std::to_string(el.T_MAX()) + "): " + weight.toStdString() + ". ");
}

void CheckWeightString(const QString& weight)
{
    t_data<std::string> el;
    if (BiggerQString(weight.toStdString(), el.T_MAX()))
        throw std::logic_error("Weight is greater than largest possible value(" + el.T_MAX() + "): " + weight.toStdString() + ". ");
}

Edge<int> CreateEdgeInt(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<int>(start.toInt(), finish.toInt(), weight.toInt());
}

Edge<double> CreateEdgeDouble(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<double>(start.toInt(), finish.toInt(), weight.toDouble());
}

Edge<std::string> CreateEdgeString(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<std::string>(start.toInt(), finish.toInt(), weight.toStdString());
}
