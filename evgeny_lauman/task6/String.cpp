#include "pch.h"
#include "String.h"


String::String() : String("")
{
}

String::String(size_t n, char c)
{
    str = new char[n + 1];
    len = n;
    for (int i = 0; i < n; i++)
        str[i] = c;
    str[len] = '\0';
}

String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
}

String::String(const char* s, size_t n)
{
    len = n;
    str = new char[n + 1];
    std::memcpy(str, s, n);
    str[len] = '\0';
}

String::String(const String& st, size_t pos)
{
    if (st.len <= pos)
        throw std::out_of_range("out");
    else
    {
        len = st.len - pos;
        str = new char[st.len - pos + 1];
        std::strcpy(str, st.str + pos);
    }
}

String::String(const String& st, size_t pos, size_t n)
{
    if (st.len <= pos)
        throw std::out_of_range("out");
    else
    {
        len = n;
        str = new char[n + 1];
        std::memcpy(str, st.str + pos, n);
        str[len] = '\0';
    }
}

String::String(std::initializer_list<char> il)
{
    len = il.size();
    str = new char[len+1];
    int index = 0;
    for (auto it = il.begin(); it != il.end(); it++)
    {
        str[index] = *it;
        ++index;
    }
    str[len] = '\0';
}

String::String(const String& st)
{
    len = st.len;
    str = new char[st.len + 1];
    std::strcpy(str, st.str);
}

String::String(String&& st)
{
    str = new char[st.len + 1];
    std::strcpy(str, st.str);
    len = st.len;
    st = String{};
}

String::~String()
{
    delete[] str;
}

void String::push_back(char a)
{
    len += 1;
    char* temp = new char[len + 1];
    std::strcpy(temp, str);
    temp[len-1] = a;
    temp[len] = '\0';
    delete[] str;
    str = temp;
}

size_t String::find(const String& st, const size_t index) const
{
    if (len <= index)
        throw std::out_of_range("out");
    else
    {
        for (size_t i = index; i < len; i++)
        {
            for (size_t j = 0; j < st.length(); j++)
            {
                if (str[i + j] == st[j] && (j + 1) == st.length())
                    return i;
                else if (str[i + j] == st[j])
                    continue;
                else
                    break;   
            }
        }
    }
    return -1;
}


size_t String::find(const char* st, const size_t index) const
{
    String st_string{ st };
    if (len <= index)
        throw std::out_of_range("out");
    else
    {
        for (size_t i = index; i < len; i++)
        {
            for (size_t j = 0; j < st_string.length(); j++)
            {
                if (str[i + j] == st_string[j] && (j+1) == st_string.length())
                    return i;
                else if (str[i + j] == st_string[j])
                    continue;
                else
                    break;
            }
        }
    }
    return -1;
}

size_t String::find(const char* st, const size_t index, const size_t n) const
{
    String st_string{ st };
    if (n == 0 || n >= st_string.length())
        return -1;
    if (len <= index)
        throw std::out_of_range("out");
    else
    {
        for (size_t i = index; i < len; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (str[i + j] == st_string[j] && j == n - 1)
                    return i;
                else if (str[i + j] == st_string[j])
                    continue;
                else
                    break;
            }
        }
    }
    return -1;
}

size_t String::find(const char c, size_t index) const
{
    if (len <= index)
        throw std::out_of_range("out");
    else
    {
        for (size_t i = index; i < len; i++)
        {
            if (str[i] == c)
                return i;
        }
    }
    return -1;
}

bool String::empty() const
{
    if (str[0] == NULL) 
        return true; 
    else 
        return false; 
}

char& String::at(size_t index) const
{ 
    if (len <= index)
        throw std::out_of_range("out");
    else
    {
        return str[index];
    }
}

String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char& String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i) const
{
    return str[i];
}


bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
    os << st.str;
    return os;
}