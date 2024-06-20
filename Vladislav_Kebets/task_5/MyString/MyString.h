#pragma once
#include <cstring>
#include <iostream>
namespace MyString
{
    const int npos = -1;
    class string
    {
    private:
        char* m_text = nullptr;
        size_t m_len = 0;
    public:

        string(); //EmptyStringConstructor

        string(const char* text); //FromCstring

        string(const char* text, size_t size); //FromSequence

        string(const std::initializer_list<char>& list); //InitializerList

        string(const string& str, const size_t start, size_t size); //SubstringConstructor

        string(int size, char fill); //FillConstructor

        string(const string& str); //CopyConstructor

        string(string&& move) noexcept; //MoveConstructor

        ~string();

        bool operator== (const char* text) const;

        bool operator== (const string str) const;

        void push_back(const char& sym);

        int find(const char& sym, const size_t& start = 0) const;

        int find(const string& str, const size_t& start = 0) const;

        size_t size() const;

        char* getText();

        char& front();

        void erase(const size_t& start, size_t er_size);
    };
}
