#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <algorithm>

class StringCustom {
public:
    
    StringCustom();
    explicit StringCustom(const StringCustom& str);
    StringCustom(const StringCustom& str, int pos, int len);
    explicit StringCustom(const char* cstr);
    StringCustom(const char* cstr, int n);
    StringCustom(int n, char c);
    StringCustom(StringCustom&& str) noexcept;

    ~StringCustom();

    char at(int index) const;
    size_t size() const;
    void push_back(char c);
    void clear();
    int find(char c) const;
    size_t length() const;
    void append(const StringCustom& other);
    void append(const char* cstr);
    void sort();

    bool operator==(const StringCustom& other) const;
    bool operator==(const char* cstr) const;

    friend bool operator==(const char* cstr, const StringCustom& str);
    friend bool operator<(const StringCustom& str1, const StringCustom& str2);

    const char* c_str() const;

private:
    char* s;       
    size_t strsize;

    void set_size(size_t newSize);
};
