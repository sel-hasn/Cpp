#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* arr;
    int arr_size;
public:
    Array():arr(NULL), arr_size(0)
    {}
    Array(unsigned int n)
    {
        arr = new T[n];
        arr_size = n;
    }
    Array(const Array &other)
    {
        arr_size = other.arr_size;
        arr = new T[other.arr_size];
        for (int i = 0; i < other.arr_size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    ~Array()
    {
        delete[] arr;
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] arr;
            arr_size = other.arr_size;
            arr = new T[other.arr_size];
            for (int i = 0; i < other.arr_size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    T &operator[](int i)
    {
        if (i < 0 || i >= arr_size)
            throw (std::runtime_error("index is out of bounds"));
        return arr[i];
    }
    int size() const
    {
        return arr_size;
    }
};

#endif