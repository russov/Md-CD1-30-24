#pragma once
#include "CreateString.h"
#include <iostream>

CreateString::CreateString() : str(nullptr), Size(0) {}

CreateString::CreateString(const char* str)
{
    Size = std::strlen(str);
    this->str = new char[Size + 1];
    for (int i = 0; i < Size; ++i)
    {
        this->str[i] = str[i];
    }
    this->str[Size] = '\0';
}

CreateString::CreateString(const CreateString& other)
{
    this->Size = other.Size;
    str = new char[Size + 1];
    for (int i = 0; i < Size; ++i)
    {
        str[i] = other.str[i];
    }
    str[Size] = '\0';
}

CreateString& CreateString::operator=(const CreateString& other)
{
    if (this == &other)
        return *this;

    delete[] str;

    Size = other.Size;
    str = new char[Size + 1];
    for (int i = 0; i < Size; ++i)
    {
        str[i] = other.str[i];
    }
    str[Size] = '\0';

    return *this;
}

CreateString& CreateString::operator=(CreateString&& other) noexcept
{
    if (this == &other)
        return *this;

    delete[] str;

    str = other.str;
    Size = other.Size;

    other.str = nullptr;
    other.Size = 0;

    return *this;
}

CreateString CreateString::operator+(const CreateString& other) const
{
    CreateString newStr;

    newStr.Size = Size + other.Size;
    newStr.str = new char[newStr.Size + 1];

    int i = 0;
    for (; i < Size; ++i)
    {
        newStr.str[i] = str[i];
    }
    for (int j = 0; j < other.Size; ++j, ++i)
    {
        newStr.str[i] = other.str[j];
    }
    newStr.str[newStr.Size] = '\0';

    return newStr;
}

void CreateString::Print() const
{
    std::cout << str << std::endl;
}

int CreateString::size() const
{
    return Size;

}

CreateString::~CreateString()
{
    delete[] str;
}

bool CreateString::operator==(const CreateString& other) const
{
    if (Size != other.Size)
        return false;
    for (int i = 0; i < Size; ++i)
    {
        if (str[i] != other.str[i])
            return false;
    }
    return true;
}

bool CreateString::operator!=(const CreateString& other) const
{
    return !(*this == other);
}


char& CreateString::operator[](int index)
{
    if (index < 0 || index >= Size)
        throw std::out_of_range("Index out of range");
    return str[index];
}

const char& CreateString::operator[](int index) const
{
    if (index < 0 || index >= Size)
        throw std::out_of_range("Index out of range");
    return str[index];
}

void CreateString::push_back(char c)
{
    char* newStr = new char[Size + 2];
    for (int i = 0; i < Size; ++i)
    {
        newStr[i] = str[i];
    }
    newStr[Size] = c;
    newStr[Size + 1] = '\0';
    delete[] str;
    str = newStr;
    ++Size;
}

int CreateString::find(char symbol) const 
{
        for (size_t i = 0; i < Size; ++i) 
        {
            if (symbol == str[i]) 
            {
                return static_cast<int>(i);
            }
        }
        return -1; 
    
}

bool CreateString::replace(const char* from, const char* to)
{
    if (from == nullptr || to == nullptr) return false;

    char* start_pos = strstr(str, from);
    if (start_pos == nullptr) return false; 

    size_t fromLength = strlen(from);
    size_t toLength = strlen(to);
    size_t newStrLength = Size - fromLength + toLength;

    char* newStr = new char[newStrLength + 1]; 
    char* temp = newStr;
    for (const char* it = str; it != start_pos; ++it, ++temp) 
    {
        *temp = *it;
    }

    for (const char* it = to; *it; ++it, ++temp) 
    {
        *temp = *it;
    }

    for (const char* it = start_pos + fromLength; *it; ++it, ++temp)
    {
        *temp = *it;
    }
    *temp = '\0'; 
    delete[] str;
    str = newStr;
    Size = newStrLength; 
    return true; 
}

void CreateString::clear()
{
    Size = 0;
    delete[] str;
    str = new char[1];
    str[0] = '\0';
}


   

std::ostream& operator<<(std::ostream& out, const CreateString& obj)
{
    if (obj.str != nullptr)
        out << obj.str;
    return out;
}

std::istream& operator>>(std::istream& input, CreateString& inputObj)
{
    char buffer[1000]; 
    input >> buffer;
    inputObj = CreateString(buffer);
    return input;
}

