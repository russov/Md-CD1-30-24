#include "pch.h"
#include "StringCustom.h"

StringCustom::StringCustom() : s(new char[1] {'\0'}), strsize(1) {}

StringCustom::StringCustom(const StringCustom& str)
    : s(new char[str.strsize]), strsize(str.strsize) {
    std::strcpy(s, str.s);
}

StringCustom::StringCustom(const StringCustom& str, int pos, int len) {
    if (pos < 0 || len < 0 || static_cast<size_t>(pos + len) > str.strsize - 1) {
        throw std::out_of_range("Invalid position or length");
    }
    strsize = len + 1;
    s = new char[strsize];
    std::strncpy(s, str.s + pos, len);
    s[len] = '\0';
}

StringCustom::StringCustom(const char* cstr) {
    if (!cstr) {
        s = new char[1] {'\0'};
        strsize = 1;
        return;
    }
    strsize = std::strlen(cstr) + 1;
    s = new char[strsize];
    std::strcpy(s, cstr);
}

StringCustom::StringCustom(const char* cstr, int n) {
    if (!cstr || n < 0 || static_cast<size_t>(n) > std::strlen(cstr)) {
        throw std::out_of_range("Invalid length");
    }
    strsize = n + 1;
    s = new char[strsize];
    std::strncpy(s, cstr, n);
    s[n] = '\0';
}

StringCustom::StringCustom(int n, char c) : s(new char[n + 1]), strsize(n + 1) {
    std::fill(s, s + n, c);
    s[n] = '\0';
}

StringCustom::StringCustom(StringCustom&& str) noexcept : s(str.s), strsize(str.strsize) {
    str.s = nullptr;
    str.strsize = 0;
}

StringCustom::~StringCustom() {
    delete[] s;
}

char StringCustom::at(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= strsize - 1) {
        throw std::out_of_range("Index out of range");
    }
    return s[index];
}

size_t StringCustom::size() const {
    return strsize;
}

void StringCustom::push_back(char c) {
    char* new_s = new char[strsize + 1];
    std::strcpy(new_s, s);
    new_s[strsize - 1] = c;
    new_s[strsize] = '\0';
    delete[] s;
    s = new_s;
    ++strsize;
}

void StringCustom::clear() {
    delete[] s;
    s = new char[1] {'\0'};
    strsize = 1;
}

int StringCustom::find(char c) const {
    for (size_t i = 0; i < strsize - 1; ++i) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

size_t StringCustom::length() const {
    return strsize - 1;
}

void StringCustom::append(const StringCustom& other) {
    size_t newSize = strsize + other.strsize - 1;
    char* newS = new char[newSize];
    std::strcpy(newS, s);
    std::strcat(newS, other.s);
    delete[] s;
    s = newS;
    strsize = newSize;
}

void StringCustom::append(const char* cstr) {
    if (!cstr) return;
    size_t cstrLen = std::strlen(cstr);
    size_t newSize = strsize + cstrLen;
    char* newS = new char[newSize];
    std::strcpy(newS, s);
    std::strcat(newS, cstr);
    delete[] s;
    s = newS;
    strsize = newSize;
}

void StringCustom::sort() {
    std::sort(s, s + strsize - 1);
}

bool StringCustom::operator==(const StringCustom& other) const {
    return std::strcmp(s, other.s) == 0;
}

bool StringCustom::operator==(const char* cstr) const {
    if (!cstr) return false;
    return std::strcmp(s, cstr) == 0;
}

bool operator==(const char* cstr, const StringCustom& str) {
    return str == cstr;
}

bool operator<(const StringCustom& str1, const StringCustom& str2) {
    return std::strcmp(str1.s, str2.s) < 0;
}

void StringCustom::set_size(size_t newSize) {
    delete[] s;
    s = new char[newSize];
    strsize = newSize;
}

const char* StringCustom::c_str() const {
    return s;
}
