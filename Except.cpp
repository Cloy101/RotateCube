#include "Except.h"


template <typename T>
bool Except::exception_less_EPS(T value)
{
    if (value < EPS)
    {
        throw std::invalid_argument("Your argument for function of class less then EPS");
    }
    return false;
}

template<typename T>
bool Except::exception_less_1(T value)
{
    if (value < 1)
    {
        throw std::invalid_argument("Your argument for function of class less then acceptable value");
    }
    return false;
}
