#include "edge.h"

bool IsNumber(const QString& num)
{
    for (auto i : num)
        if (i > '9' && i < '0')
            return false;
    return true;
}

Edge<std::string> CreateEdge(const QString& start, const QString& finish, const QString& weight)
{
    if (!IsNumber(start))
        throw std::logic_error("Start point isn`t an integer number: " + start.toStdString());
    if (!IsNumber(finish))
        throw std::logic_error("Finish point isn`t an integer number: " + finish.toStdString());
    if (start.size() > 3)
        throw std::logic_error("Start point is greater than largest possible value(999): " + start.toStdString());
    if (finish.size() > 3)
        throw std::logic_error("Finish point is greater than largest possible value(999): " + finish.toStdString());
    t_data<std::string> el;
    if (weight.toStdString() > el.T_MAX())
        throw std::logic_error("Weight is greater than largest possible value(" + el.T_MAX() + "): " + weight.toStdString());
    return Edge<std::string>(start.toInt(), finish.toInt(), weight.toStdString());
}
