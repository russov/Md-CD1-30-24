#ifndef CONTAINER_H
#define CONTAINER_H

#include "Figures.h"

#include <cassert>
#include <stdexcept>

template<class fig = Figure>
class Container
{
public:
    Container();

    bool empty() const;

    size_t size() const;

    size_t capacity() const;

    fig pop_back();

    void push_back(const fig& value);

    const fig& operator [](long _index) const;

private:

    void reserve(size_t new_capacity);

    fig* data;
    size_t data_size;
    size_t data_capacity;
};

#endif // CONTAINER_H
