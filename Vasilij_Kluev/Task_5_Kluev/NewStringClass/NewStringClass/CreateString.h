#pragma once
#include <iostream>
class CreateString
{
public:
    CreateString();

    CreateString(const char* str);

    CreateString(const CreateString& other);

    CreateString& operator=(const CreateString& other);


    CreateString& operator=(CreateString&& other) noexcept;



    CreateString operator+(const CreateString& other) const;


    void Print() const;

    int size() const;

    ~CreateString();

    bool operator==(const CreateString& other) const;

    bool operator!=(const CreateString& other) const;


    char& operator[](int index);

    const char& operator[](int index) const;

    void push_back(char c);


    friend std::ostream& operator<<(std::ostream& out, const CreateString& obj);


    friend std::istream& operator>>(std::istream& input, CreateString& inputObj);

    void clear();
    int find(char symbol) const;
    bool replace(const char* from, const char* to);

private:
    char* str;
    int Size;
};

