/*!
\file
\brief header file

this class contains a description of the t_data class
*/

#pragma once
#ifndef T_DATA_H
#define T_DATA_H

/**
 *@brief class for to create zero and max variables of different data types
 *@tparam T -data type zero
 */
template <typename T>
class t_data{
public:

    /**
     * @brief creates the maximum value for different data types
     * @return max element for differen data type
     */
    T T_MAX();


    /**
     * @brief creates the zero value for different data types
     * @return zero element for differen data type
     */
    T T_NULL();
};


#endif // T_DATA_H
