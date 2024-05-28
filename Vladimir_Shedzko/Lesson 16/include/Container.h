#ifndef CONTAINER_H
#define CONTAINER_H

#include "Figures.h"

#include <cassert>
#include <stdexcept>

class Container
{
public:
    Container();

    bool empty() const;

    size_t size() const;

    size_t capacity() const;

    Figure pop_back();

    void push_back(const Figure& value);

    const Figure& operator [](long _index) const;

private:

    void reserve(size_t new_capacity);

    Figure* data;
    size_t data_size;
    size_t data_capacity;
};

#endif // CONTAINER_H
