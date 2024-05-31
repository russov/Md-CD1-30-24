#pragma once

template <typename T>
class Array
{
private:
    T** array;
    int size;
public:
    Array(int s)
    {
        size = s;
        array = new T * [size];
        for (int i = 0; i < size; i++)
        {
            array[i] = nullptr;
        }
    }
    T*& operator[](int index);
    ~Array()
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] != nullptr)
            {
                delete array[i];
            }
        }
        delete[] array;
    }
};

