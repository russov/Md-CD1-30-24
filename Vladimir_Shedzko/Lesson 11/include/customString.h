#include <iostream>
#include <iostream>

class CustomString {

public:

    struct Iterator 
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = char;
        using pointer           = char*;  
        using reference         = char&;

        Iterator(pointer ptr) : m_ptr(ptr) {}
        Iterator(const Iterator& rawIterator) = default;
        ~Iterator() = default;

        Iterator& operator=(const Iterator& rawIterator) = default;
        Iterator& operator=(pointer ptr) { m_ptr = ptr; return *this; }

        explicit operator bool() const {
            return m_ptr != nullptr;
        }

        reference operator*() const { return *m_ptr; }
        pointer operator->() const { return m_ptr; }

        // Prefix increment
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator& operator--() { m_ptr--; return *this; }

        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

        // Addition and subtraction of difference_type
        Iterator operator+(const difference_type& movement) const {
            return Iterator(m_ptr + movement);
        }

        Iterator operator-(const difference_type& movement) const {
            return Iterator(m_ptr - movement);
        }

        // Compound assignment
        Iterator& operator+=(const difference_type& movement) {
            m_ptr += movement;
            return *this;
        }

        Iterator& operator-=(const difference_type& movement) {
            m_ptr -= movement;
            return *this;
        }

        difference_type operator-(const Iterator& other) const {
            return m_ptr - other.m_ptr;
        }
        // Iterator&                   operator=(const std::iterator) {return (*this);}

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }

    protected:
        pointer m_ptr;
    };
    
    CustomString();

    /// @brief C-string constructor
    /// @param inp input const char sequence
    /// @param start starting pos to copy from
    /// @param range range to copy for
    CustomString(const char inp[], const size_t &range = -1);

    /// @brief list constructor
    /// @param inp input const char sequence
    /// @param start starting pos to copy from
    /// @param range range to copy for
    CustomString(const std::initializer_list<char>& inp, const size_t &range = -1);

    /// @brief copy constructor
    /// @param inp input string
    /// @param start starting pos to copy from
    CustomString(const CustomString &inp, const size_t &start = 0, const size_t &range = -1);

    /// @brief char constructor
    /// @param charsize character size
    /// @param chr char to make copy of
    CustomString(const size_t &charsize, const char &chr);

    /// @brief char constructor
    /// @param charsize character size
    /// @param code char code to make copy of
    CustomString(CustomString::Iterator startpos, CustomString::Iterator endpos);

    /// @brief move constructor
    /// @param other - other CustomString instance
    CustomString(CustomString&& other) noexcept :
    data(std::exchange(other.data, nullptr)),       // explicit move of a member of class type
    data_size(std::exchange(other.data_size, 0)) // explicit move of a member of non-class type
    {}

    virtual ~CustomString();

    CustomString::Iterator begin();

    CustomString::Iterator end();

    size_t size() const noexcept;

    bool empty() const;

    CustomString& operator =(CustomString other);

    char& operator[](size_t _index) const;
    const char& operator[](long _index) const;

    bool operator ==(const CustomString &other) const;
    bool operator ==(const char other[]) const;

    bool operator !=(const CustomString &other);

    /// @brief add a char to the end of string
    /// @param chr a char to add
    void push_back(const char &chr) noexcept;

    /// @brief add a char to the end of string
    /// @param chr a char to add
    void pop_back() noexcept;

    /// @brief find a char position
    /// @param chr a char to find
    /// @return position of char or npos if char was not found
    size_t find(const char &chr, const size_t &startpos = 0) const noexcept;

    /// @brief find a char position
    /// @param chr a char code to find
    /// @return position of char or npos if char was not found
    size_t find(const unsigned int &code, const size_t &startpos = 0) const noexcept;

    /// @brief find a C-string position
    /// @param chr a char code to find
    /// @return position of char or npos if char was not found
    size_t find(const char inp[], const size_t &startpos = 0) noexcept;

    /// @brief resize a string with chars
    /// @param newsize new strin size
    /// @param fillchar char to fill
    void resize(const size_t &newsize, char fillchar = (char)0);

    /// @brief swap a string with another
    /// @param right a string to swap
    void swap(CustomString &other);

    static const size_t npos = -1;

private:

    void reserve(size_t new_capacity);

    char* data;
    size_t data_size;
    size_t capacity;
};