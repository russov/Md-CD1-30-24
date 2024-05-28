#include "Container.h"

Container::Container()
    : data(nullptr), data_size(0), data_capacity(0) 
{}

bool Container::empty() const 
{
    return data_size == 0;
}

size_t Container::size() const 
{
    return data_size;
}
size_t Container::capacity() const 
 {
        return data_capacity;
    }
Figure Container::pop_back()
{
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}

void Container::push_back(const Figure& value)
{
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}

const Figure& Container::operator [](long _index) const
{
    if (_index >= 0) {
        if ((size_t)_index >= size()) {
            throw std::out_of_range("List index out of range");
        }
        return data[_index];
    }
    if ( (size_t)std::abs(_index) > size() ) {
        throw std::out_of_range("List index out of range");
    }
    return data[size() + _index];
}

void Container::reserve(size_t new_capacity)
 {
    Figure* new_data = new Figure[new_capacity];
    if (data_size > 0) {
        std::copy(data, data + data_size, new_data);
    }
    delete[] data;
    data = new_data;
    data_capacity = new_capacity;
}
