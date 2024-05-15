#pragma once

#include <iostream>
#include <cstring>

class NewString {
public:

    NewString();
    NewString(const NewString& LinkString);
    NewString(const NewString& LinkString, int pos, int len);
    NewString(char* s);
    NewString(const char* buffer);
    NewString(int length, char FillChar);
    NewString(const char* start, const char* end);
    NewString(std::initializer_list<char> initializer);
    NewString(NewString&& object);

    const NewString& operator=(const NewString& ObjectRef);
    bool operator==(const NewString& other) const;

    void Set(const char* s);
    const char* GetChar() const;
    int GetInt() const;

    void push_back(char c);
    int size() const;
    int find(const char* subStr) const;
    void append(const NewString& other);
    char back() const;
    void clear();

    ~NewString(){
        delete[] str;
    };

    private:
        char* str = nullptr;
        int StrLength = 0;

};