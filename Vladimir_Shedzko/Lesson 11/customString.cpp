#include "customString.h"

#include <cassert>

CustomString::CustomString()
{
    data = nullptr;
    size = 0;
}

CustomString::CustomString(const char inp[], const size_t &start, const size_t &range)
{
    assert(sizeof(inp) / sizeof(inp[0]) - start - range >= 0);

    if (range == -1)
        size = sizeof(inp) / sizeof(inp[0]) - start;
    else
        size = range;
    data = new char[size]();
    for (size_t i = start; i < start + range; i++){
        data[i] = inp[i];
    }
}

CustomString::CustomString(const CustomString &inp, const size_t &range)
{
    assert(inp.size >= range);

    if (range == -1) 
        size = inp.size;
    else
        size = range;
    data = new char[size]();
    for (size_t i = 0; i < range; i++){
        data[i] = inp.data[i];
    }
}

CustomString::CustomString(const size_t &charsize, const char &chr)
{
    size = charsize;
    data = new char[size]();
    for (size_t i = 0; i < size; i++){
        data[i] = chr;
    }
}

CustomString::CustomString(const size_t &charsize, const unsigned int &code)
{
    size = charsize;
    data = new char[size]();
    for (size_t i = 0; i < size; i++){
        data[i] = char(code);
    }
}

CustomString::Iterator CustomString::begin()
{
    return data;
}

CustomString::Iterator CustomString::end()
{
    return data + size;
}

CustomString::~CustomString()
{
    delete data;
}
