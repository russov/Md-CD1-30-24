#include "../include/Container.h"

template<class fig> 
Container<fig>::Container()
    : data(nullptr), data_size(0), data_capacity(0)
{}

template<> Container<Figure>::Container()
    : data(nullptr), data_size(0), data_capacity(0)
{}
template<> Container<Pyramid>::Container()
    : data(nullptr), data_size(0), data_capacity(0)
{}
template<> Container<Sphere>::Container()
    : data(nullptr), data_size(0), data_capacity(0)
{}
template<> Container<Cylinder>::Container()
    : data(nullptr), data_size(0), data_capacity(0)
{}

template<class fig>
bool Container<fig>::empty() const
{
    return data_size == 0;
}

template<class fig> size_t Container<fig>::size() const
{    return data_size; }


template<class fig> size_t Container<fig>::capacity() const
{    return data_capacity; }
template<> size_t Container<Figure>::capacity() const
{    return data_capacity; }
template<> size_t Container<Sphere>::capacity() const
{    return data_capacity; }
template<> size_t Container<Pyramid>::capacity() const
{    return data_capacity; }
template<> size_t Container<Cylinder>::capacity() const
{    return data_capacity; }


template<class fig>
fig Container<fig>::pop_back() {
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}
template<> Figure Container<Figure>::pop_back() {
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}
template<>Sphere Container<Sphere>::pop_back() {
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}
template<>Cylinder Container<Cylinder>::pop_back() {
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}

template<>Pyramid Container<Pyramid>::pop_back() {
    assert(!empty());
    if (data_size == data_capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), data_capacity / 2));
    }

    --data_size;
    return data[data_size];
}
template<class fig>
void Container<fig>::push_back(const fig& value) {
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}
template<> void Container<Figure>::push_back(const Figure& value) {
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}
template<> void Container<Sphere>::push_back(const Sphere& value) {
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}
template<> void Container<Cylinder>::push_back(const Cylinder& value) {
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}
template<> void Container<Pyramid>::push_back(const Pyramid& value) {
    if (data_size == data_capacity) {
        reserve(std::max(static_cast<size_t>(1), data_capacity * 2));
    }
    data[data_size++] = value;
}

template<class fig>
const fig& Container<fig>::operator [](long _index) const{
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
template<> const Figure& Container<Figure>::operator [](long _index) const{
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
template<> const Pyramid& Container<Pyramid>::operator [](long _index) const{
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
template<> const Sphere& Container<Sphere>::operator [](long _index) const{
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
template<> const Cylinder& Container<Cylinder>::operator [](long _index) const{
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


template<class fig>
void Container<fig>::reserve(size_t new_capacity)
{
    fig* new_data = new fig[new_capacity];
    if (data_size > 0) {
        std::copy(data, data + data_size, new_data);
    }
    delete[] data;
    data = new_data;
    data_capacity = new_capacity;
}

