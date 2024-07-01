#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdexcept>

class String {
private:
    char* data;
    size_t len;
    
    void copy_from(const String& other) {
        data = new char[other.len + 1];
        std::copy(other.data, other.data + other.len, data);
        data[other.len] = '\0';
        len = other.len;
    }

public:
    static const size_t npos = -1;


    String() : data(new char[1]), len(0) {
        data[0] = '\0';
    }

    String(const char* str) : len(std::strlen(str)) {
        data = new char[len + 1];
        std::copy(str, str + len, data);
        data[len] = '\0';
    }

    String(int count, char c) : len(count) {
        data = new char[len + 1];
        std::fill_n(data, len, c);
        data[len] = '\0';
    }

    String(const String& other) {
        copy_from(other);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            copy_from(other);
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    void push_back(char c) {
        char* new_data = new char[len + 2];
        std::copy(data, data + len, new_data);
        new_data[len] = c;
        new_data[len + 1] = '\0';
        delete[] data;
        data = new_data;
        len++;
    }

    size_t size() const {
        return len;
    }

    size_t find(char c) const {
        for (size_t i = 0; i < len; i++) {
            if (data[i] == c) {
                return i;
            }
        }
        return npos;
    }

    size_t find(const char* str) const {
        const char* pos = std::strstr(data, str);
        if (pos != nullptr) {
            return pos - data;
        }
        return npos;
    }

    String substr(size_t pos, size_t count) const {
        if (pos > len) {
            throw std::out_of_range("pos is out of range");
        }
        size_t rcount = std::min(count, len - pos);
        char* new_data = new char[rcount + 1];
        std::copy(data + pos, data + pos + rcount, new_data);
        new_data[rcount] = '\0';
        String substr(new_data);
        delete[] new_data;
        return substr;
    }

    char at(size_t pos) const {
        if (pos >= len) {
            throw std::out_of_range("pos is out of range");
        }
        return data[pos];
    }

    void append(const char* str) {
        size_t new_len = len + std::strlen(str);
        char* new_data = new char[new_len + 1];
        std::copy(data, data + len, new_data);
        std::copy(str, str + std::strlen(str), new_data + len);
        new_data[new_len] = '\0';
        delete[] data;
        data = new_data;
        len = new_len;
    }

    bool operator<(const String& other) const {
        return std::strcmp(data, other.data) < 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    const char* c_str() const {
        return data;
    }
};

#endif 
