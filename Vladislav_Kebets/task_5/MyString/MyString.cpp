#include <iostream>
#include <cstring>
namespace MyString
{
    const const const int npos = -1;
    typedef unsigned int uint;
    class string
    {
    private:
        char* m_text = nullptr;
        uint m_len = 0;
    public:

        string() //EmptystringConstructor
        {
        }

        string(const char* text) //FromCstring
        {
            m_len = strlen(text);
            m_text = new char[m_len + 1];
            for (uint i = 0; i < m_len; ++i)
            {
                this->m_text[i] = text[i];
            }
        }

        string(const char* text, uint size) //FromSequence
        {
            if (size > strlen(text))
                throw std::exception();
            m_len = size;
            m_text = new char[m_len + 1];
            for (uint i = 0; i < m_len; ++i)
            {
                this->m_text[i] = text[i];
            }

        }

        string(const std::initializer_list<char>& list) //InitializerList
        {
            m_len = std::size(list);
            m_text = new char[m_len + 1];
            int index = 0;
            for (auto a : list)
            {
                m_text[index] = a;
                ++index;
            }
        }

        string(const string& str, const uint start, uint size) //SubstringConstructor
        {
            if (start + size > str.m_len)
            {
                this->m_len = str.m_len - start;
            }
            else
            {
                this->m_len = size;
            }
            this->m_text = new char[m_len];
            for (uint i = 0; i < m_len; ++i)
            {
                this->m_text[i] = str.m_text[start + i];
            }
        }

        string(int size, char fill) //FillConstructor
        {
            m_len = size;
            m_text = new char[m_len];
            for (uint i = 0; i < m_len; ++i)
            {
                m_text[i] = fill;
            }
        }

        string(const string& str) //CopyConstructor
        {
            this->m_len = str.m_len;
            this->m_text = new char[m_len + 1];
            for (uint i = 0; i < m_len; ++i)
            {
                this->m_text[i] = str.m_text[i];
            }
        }

        string(string&& move) noexcept//MoveConstructor
        {
            m_len = move.m_len;
            this->m_text = new char[m_len];
            for (uint i = 0; i < this->m_len; ++i)
            {
                this->m_text[i] = move.m_text[i];
            }
            move.m_text = nullptr;
            move.m_len = 0;
        }

        ~string()
        {
            delete[] this->m_text;
        }

        bool operator== (const char* text) const
        {
            if (m_len != strlen(text))
            {
                return false;
            }
            for (uint i = 0; i < m_len; ++i)
            {
                if (m_text[i] != text[i])
                {
                    return false;
                }
            }
            return true;
        }

        bool operator== (const string str) const
        {
            if (this->m_len != str.m_len)
            {
                return false;
            }
            for (uint i = 0; i < m_len; ++i)
            {
                if (m_text[i] != str.m_text[i])
                    return false;
            }
            return true;
        }

        void push_back(const char& sym)
        {
            char* text = m_text;
            ++m_len;
            m_text = new char[m_len + 1];
            for (uint i = 0; i < m_len - 1; ++i)
            {
                m_text[i] = text[i];
            }
            m_text[m_len - 1] = sym;
        }

        int find(const char& sym, const uint& start = 0)
        {
            for (uint i = start; i < m_len; ++i)
            {
                if (m_text[i] == sym) return i;
            }
            return npos;
        }

        int find(const string& str, const uint& start = 0)
        {
            int found{ 0 };
            for (uint i = start; i < m_len; ++i)
            {
                if (m_text[i] == str.m_text[0])
                {
                    found = 1;
                    for (uint j = i + 1; j < m_len; ++j)
                    {
                        if (m_text[j] == str.m_text[found])
                        {
                            ++found;
                            if (found == str.m_len)
                                return i;
                        }
                    }
                }
            }
            return npos;
        }

        uint size()
        {
            return m_len;
        }

        char* getText()
        {
            return m_text;
        }

        char& front()
        {
            return m_text[0];
        }

        void erase(const uint& start, uint er_size)
        {
            if (start > m_len)
                throw std::exception();
            if (start + er_size > m_len)
                er_size = m_len - start;
            char* buff = new char[m_len];
            for (uint i = 0; i < m_len; ++i)
            {
                buff[i] = this->m_text[i];
            }
            delete[] m_text;
            m_len -= er_size;
            m_text = new char[m_len + 1];
            for (uint i = 0; i < start; ++i)
            {
                m_text[i] = buff[i];
            }
            for (uint i = start + er_size; i < m_len + er_size; ++i)
            {
                m_text[i - er_size] = buff[i];
            }
            delete[] buff;
        }
    };
}