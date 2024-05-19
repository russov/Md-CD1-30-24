#include "customString.h"

#include <cassert>

CustomString::CustomString() : data(nullptr), data_size(0), capacity(0){}

CustomString::CustomString(const char inp[], const size_t &range) 
: data(nullptr), data_size(0), capacity(0) {
    
    if (range == -1)
        reserve(std::strlen(inp));
    else {
        assert(range <= std::strlen(inp));
        reserve(range);
    }
    for (size_t i = 0; i < capacity; i++)
        push_back(inp[i]);
    
}

CustomString::CustomString(const std::initializer_list<char>& inp, const size_t &range)
: data(nullptr), data_size(0), capacity(0) {
    if (range == -1)
        reserve(inp.size());
    else {
        assert(inp.size() >= range);
        reserve(range);
    }
    for (size_t i = 0; i < capacity; i++)
        push_back(*(inp.begin() + i));
    
   
}

CustomString::CustomString(const CustomString &inp, const size_t &start, const size_t &range)
: data(nullptr), data_size(0), capacity(0) {
    if (range == -1)
        reserve(inp.size() - start);
    else {
        assert(inp.size() >= start + range);
        reserve(range);
    }
    data_size = capacity;
    std::copy(inp.data + start, inp.data + start + data_size, data);
}

CustomString::CustomString(const size_t &charsize, const char &chr)
: data(nullptr), data_size(0), capacity(0) {
    reserve(charsize);
    for (size_t i = 0; i < charsize; i++) {
        push_back(chr);
    }
}

CustomString::CustomString(CustomString::Iterator startpos, CustomString::Iterator endpos)
: data(nullptr), data_size(0), capacity(0) {
    reserve(endpos - startpos);

    data_size = endpos - startpos;
    std::copy(startpos, endpos, data);
}

CustomString::Iterator CustomString::begin() {
    return data;
}

CustomString::Iterator CustomString::end() {
    return data + size();
}

size_t CustomString::size() const noexcept {
    return data_size;
}

bool CustomString::empty() const {
    return data_size == 0;
}

CustomString& CustomString::operator=(CustomString other)
{
    swap(other);
    return *this;
}

char& CustomString::operator[](size_t _index) const
{
    assert(_index < size());
    return data[_index];
}

const char& CustomString::operator[](long _index) const {
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

bool CustomString::operator==(const CustomString& other) const {
    if (data_size != other.data_size) return false;
    return std::equal(data, data + data_size, other.data);
}

bool CustomString::operator==(const char other[]) const
{
    return *this == CustomString(other);
}

bool CustomString::operator !=(const CustomString& other){
    return !(*this == other);
}

void CustomString::push_back(const char &chr) noexcept {
    if (data_size == capacity) {
        reserve(std::max(static_cast<size_t>(1), capacity * 2));
    }

    data[data_size++] = chr;
}

void CustomString::pop_back() noexcept {
    assert(!empty());

    if (data_size <= capacity / 4) {
        reserve(std::max(static_cast<size_t>(1), capacity / 2));
    }

    --data_size;
}

size_t CustomString::find(const char &chr, const size_t &startpos) const noexcept {
    for (size_t i = startpos; i < size(); i++)
        if (data[i] == chr)
            return i;
    return -1;
}

size_t CustomString::find(const unsigned int &code, const size_t &startpos) const noexcept {
    for (size_t i = startpos; i < size(); i++)
        if (data[i] == char(code))
            return i;
    return -1;
}

size_t CustomString::find(const char inp[], const size_t &startpos) noexcept
{
    size_t inp_size = std::strlen(inp);
    assert(inp_size + startpos <= size());
    bool found;
    for (size_t i = startpos; i <= size() - inp_size; i++) {
        found = true;
        for (size_t j = 0; j < inp_size; j++)
            if (data[i + j] != inp[j]){
                found = false;
                break;
            }
        if (found) {
            return i;
        }
    }
    return -1;
}

void CustomString::resize(const size_t &newsize, char fillchar) {
    data = (char*)realloc(data, sizeof(char) * (newsize));
    for (size_t i = data_size; i < newsize; i++)
        data[i] = fillchar;
    data_size = newsize;
}

void CustomString::swap(CustomString &other) {
    std::swap(other.data, data);
    std::swap(other.data_size, data_size);
    std::swap(other.capacity, capacity);
}

void CustomString::reserve(size_t new_capacity) {
    char* new_data = new char[new_capacity];
    if (data_size > 0) {
        std::copy(data, data + data_size, new_data);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

CustomString::~CustomString()
{
    delete data;
}
