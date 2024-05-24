#pragma once
class String
{
    private:
	    char* str;
	    int len;
    public:
        String(); // default
        String(size_t n, char c); //Repeat_character
        String(const char* s); //from character_range unbound
        String(const char* s, size_t n); //from character_range bound
        String(const String& st, size_t pos); //from substring unbound
        String(const String& st, size_t pos, size_t n); //from substring bound
        template <class InputIterator>  String(InputIterator first, InputIterator last)
        {

            len = last - first;
            str = new char[len + 1];
            for (auto it = first; it != last; it++)
            {
                str[it - first] = *it;
            }
            str[len] = '\0';
        }//iterator_range
        String(const String& st); // copy
        String(String&&); //move
        
        String(std::initializer_list<char> il);//initializer list
        ~String();

        int length() const { return len; }
        int size() const { return len; }
        char* c_str() const { return str; }
        void push_back(char a);
        size_t find(const String& str, const size_t index = 0) const;
        size_t find(const char* str, const size_t index = 0) const;
        size_t find(const char* str, const size_t index, const size_t n) const;
        size_t find(const char c, const size_t index = 0) const;
        bool String::empty() const;
        char& at(size_t index) const;

        String& operator=(const String&);
        String& operator=(const char*);

        char& operator[](int i);
        const char& operator[](int i) const;

        friend bool operator==(const String& st, const String& st2);
        friend std::ostream& operator<<(std::ostream& os, const String& st2);
};

