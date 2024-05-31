#include "Array.h"
#include <iostream>

template <typename T>
T*& Array<T>::operator[](int index)
{
    try 
    {
        return array[index];
    }
    catch (std::out_of_range ex)
    {
        std::cerr << "Out of range error: " << ex.what();
    }
}
