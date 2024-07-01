#include "MyString.h"

MyString::string::string()
{
}

MyString::string::string(const char* text)
{
    m_len = strlen(text);
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len; ++i)
    {
        m_text[i] = text[i];
    }
}

MyString::string::string(const char* text, size_t size)
{
    m_len = size;
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len; ++i)
    {
        m_text[i] = text[i];
    }

}

MyString::string::string(const std::initializer_list<char>& list)
{
    m_len = list.size();
    m_text = new char[m_len];
    int index = 0;
    for (auto a : list)
    {
        m_text[index] = a;
        ++index;
    }
}

MyString::string::string(const string& str, const size_t start, size_t size)
{
    if (start + size > str.m_len)
    {
        m_len = str.m_len - start;
    }
    else
    {
        m_len = size;
    }
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len; ++i)
    {
        m_text[i] = str.m_text[start + i];
    }
}

MyString::string::string(int size, char fill)
{
    m_len = size;
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len; ++i)
    {
        m_text[i] = fill;
    }
}

MyString::string::string(const string& str)
{
    m_len = str.m_len;
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len; ++i)
    {
        this->m_text[i] = str.m_text[i];
    }
}

MyString::string::string(string&& move) noexcept
{
    m_len = move.m_len;
    m_text = new char[m_len];
    for (size_t i = 0; i < this->m_len; ++i)
    {
        m_text[i] = move.m_text[i];
    }
    move.m_text = nullptr;
    move.m_len = 0;
}

MyString::string::~string()
{
    if(m_text != nullptr)
    {
        delete[] m_text;
    }
}

bool MyString::string::operator==(const char* text) const
{
    if (m_len != strlen(text))
    {
        return false;
    }
    for (size_t i = 0; i < m_len; ++i)
    {
        if (m_text[i] != text[i])
        {
            return false;
        }
    }
    return true;
}

bool MyString::string::operator==(const string str) const
{
    if (m_len != str.m_len)
    {
        return false;
    }
    for (size_t i = 0; i < m_len; ++i)
    {
        if (m_text[i] != str.m_text[i])
            return false;
    }
    return true;
}

void MyString::string::push_back(const char& sym)
{
    char* text = m_text;
    ++m_len;
    m_text = new char[m_len];
    for (size_t i = 0; i < m_len - 1; ++i)
    {
        m_text[i] = text[i];
    }
    delete[] text;
    m_text[m_len - 1] = sym;
}

int MyString::string::find(const char& sym, const size_t& start) const 
{
    for (int i = start; i < m_len; ++i)
    {
        if (m_text[i] == sym) 
        {
            return i;
        }
    }
    return npos;
}

int MyString::string::find(const string& str, const size_t& start) const
{
    int found{ 0 };
    int last_checkable_index = m_len - str.m_len + 1;
    for (int i = start; i < last_checkable_index; ++i)          //проверка на совпадение первого элемента
    {
        if (m_text[i] == str.m_text[0]) 
        {
            found = 1;
            for (int j = 0; j < str.m_len; ++j)                //проверка на совпадение оставшихся элементов
            {
                if (m_text[j+i] == str.m_text[found])
                {
                    ++found;
                    if (found == str.m_len) 
                    {
                        return i;
                    }
                }
            }
        }
    }
    return npos;
}

size_t MyString::string::size() const
{
    return m_len;
}

char* MyString::string::getText()
{
    return m_text;
}

char& MyString::string::front()
{
    if (m_text != nullptr) 
    {
        return m_text[0];
    }
}

void MyString::string::erase(const size_t& er_start, size_t er_size)
{
    if (m_len > 0) 
    {
        if (er_start > m_len) 
        {
            throw std::out_of_range("invalid string position");
        }
        if (er_start + er_size > m_len)
        {
            er_size = m_len - er_start;
        }
        char* buff = m_text;
        int buff_size = m_len;
        m_len -= er_size;
        m_text = new char[m_len];
        for (size_t i = 0; i < er_start; ++i)
        {
            m_text[i] = buff[i];
        }
        for (size_t i = er_start + er_size; i < m_len + er_size; ++i)
        {
            m_text[i - er_size] = buff[i];
        }
        delete[] buff;
    }
}