#include <iostream>
#include <iostream>

class CustomString {
public:
    struct Iterator 
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = char;
        using pointer           = char*;  // or also value_type*
        using reference         = char&;  // or also value_type&

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        // Prefix increment
        Iterator& operator++() { m_ptr++; return *this; }  

        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };     

    private:
        pointer m_ptr;
    };

    /// @brief empty constructor
    CustomString();
    
    /// @brief C-string constructor
    /// @param inp input const char sequence
    /// @param start starting pos to copy from
    /// @param range range to copy for
    CustomString(const char inp[], const size_t &start = 0, const size_t &range = -1);

    /// @brief copy constructor
    /// @param inp input string
    /// @param start starting pos to copy from
    CustomString(const CustomString &inp, const size_t &range = -1);

    /// @brief char constructor
    /// @param charsize character size
    /// @param chr char to make copy of
    CustomString(const size_t &charsize, const char &chr);

    /// @brief char constructor
    /// @param charsize character size
    /// @param code char code to make copy of
    CustomString(const size_t &charsize, const unsigned int &code);

    ~CustomString();

    CustomString::Iterator begin();

    CustomString::Iterator end();

    public:
        long size();


    private:
        char* data;
        size_t size;

};