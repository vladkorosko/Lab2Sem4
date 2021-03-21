#include "t_data.h"
#include <string>


template<> int t_data<int>::T_MAX(){
    return 999;
}

template<> int t_data<int>::T_NULL(){
    return 0;
}

template<> std::string t_data<std::string>::T_MAX(){
    return "zzzzz";
}

template<> std::string t_data<std::string>::T_NULL(){
    return "0";
}

template<> double t_data<double>::T_MAX(){
    return 999;
}

template<> double t_data<double>::T_NULL(){
    return 0;
}
