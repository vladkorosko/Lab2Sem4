/*!
\file
\brief file with a description of methods and functions

this file contains a description of the class Edge
*/

#include "Edge.h"


/**
 * @brief checks the entered character in the window or has the type int entered into the window
 * @param num -Qstring elemenr
 * @return  true if it's int else false
 */
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

/**
 * @brief checks the entered character in the window or has the type double entered into the window
 * @param d -Qstring element
 * @return  true if it's double else false
 */
bool IsDouble(const QString& d)
{
    QString aft_p = FloatPartOfNumber(d);
    QString bef_p = IntegerPartOfNumber(d);
    if (bef_p.size()==0)
        return false;
    if(!IsInteger(bef_p))
        return false;
    if (aft_p.size() == 0)
        return bef_p.size() == d.size();
    return IsInteger(aft_p);
}


/**
 * @brief checks the equality of two elements entered in the window
 * @param lhs - first QString element
 * @param rhs - second QString element
 * @return true if they are equal else false
 */
bool BiggerQString(const QString& lhs, const QString& rhs)
{
    if (lhs.size()==0&&rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return true;
    if (rhs.size() > lhs.size())
        return false;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
    {
        if(lhs[i]<rhs[i])
            return false;
        if(lhs[i]>rhs[i])
            return true;
    }
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
    {
        if(lhs[i]<rhs[i])
            return false;
        if(lhs[i]>rhs[i])
            return true;
    }
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
    {
        if(lhs[i]>rhs[i])
            return false;
        if(lhs[i]<rhs[i])
            return true;
    }
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}


/**
 * @brief checks at once two edits a line on correctness of input of edges
 * @param lhs  - first line edit
 * @param rhs  - second line edit
 * @return  true if all correct else false
 */
bool SmallerQString(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size()==0 && rhs.size()==0)
        return false;
    if (lhs.size() > rhs.size())
        return false;
    if (rhs.size() > lhs.size())
        return true;
    for (int i = 0; i < static_cast<int>(lhs.size()); i++)
    {
        if(lhs[i]>rhs[i])
            return false;
        if(lhs[i]<rhs[i])
            return true;
    }
    if (*lhs.rbegin() == *rhs.rbegin())
        return false;
    return true;
}

void CheckEndsOfEdge(const QString& point, const QString& name)
{
    if(!IsInteger(point))
        throw std::logic_error(name.toStdString() + " point is not an integer number: " + point.toStdString() + ". ");
    if (BiggerQString(point, "12") || SmallerQString(point, "1") || point == "00")
        throw std::logic_error(name.toStdString() + " point is greater than largest possible value(12): " + point.toStdString()+ ". ");
}


/**
 * @brief checks if there is a type of rib length - int
 * @param weight -Qstring element
 * @return  true if it's int  else false
 */
void CheckWeightInt(const QString& weight)
{
    if(!IsInteger(weight))
        throw std::logic_error("Weight is not an integer number: " + weight.toStdString() + ". ");
    if (weight.size() > 3)
        throw std::logic_error("Weight is greater than largest possible value(999): " + weight.toStdString()+ ". ");
}


/**
 * @brief checks if there is a type of rib length - double
 * @param weight -Qstring element
 * @return  true if it's double  else false
 */
void CheckWeightDouble(const QString& weight)
{
    if(!IsDouble(weight))
        throw std::logic_error("Weight is not an float number: " + weight.toStdString() + ". ");
    t_data<double> el;
    if (IntegerPartOfNumber(weight).size() > 3 || FloatPartOfNumber(weight).size() > 3)
        throw std::logic_error("Weight is greater than largest possible value(" +
                               std::to_string(el.T_MAX()) + "): " + weight.toStdString() + ". ");
}


/**
 * @brief checks if there is a type of rib length - string
 * @param weight -Qstring element
 * @return  true if it's string  else false
 */
void CheckWeightString(const QString& weight)
{
    t_data<std::string> el;
    if (BiggerQString(weight.toStdString(), el.T_MAX()))
        throw std::logic_error("Weight is greater than largest possible value(" + el.T_MAX() + "): " + weight.toStdString() + ". ");
}



/**
 * @brief creates an edge with a pattern int
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<int> CreateEdgeInt(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<int>(start.toInt(), finish.toInt(), weight.toInt());
}

/**
 * @brief creates an edge with a pattern double
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<double> CreateEdgeDouble(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<double>(start.toInt(), finish.toInt(), weight.toDouble());
}


/**
 * @brief creates an edge with a pattern string
 * @param start - name  first vertex
 * @param finish - name second vertex
 * @param weight length of rib
 * @return edge
 */
Edge<std::string> CreateEdgeString(const QString& start, const QString& finish, const QString& weight)
{
    return Edge<std::string>(start.toInt(), finish.toInt(), weight.toStdString());
}
