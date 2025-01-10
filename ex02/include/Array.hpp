#pragma once

template<typename T>
class Array {
public:
    Array();
    Array(int size);
    ~Array();
    T& operator[](int index);
    Array(const Array& other);
    Array& operator=(const Array& other);
    int size() const;
    class OutOfLimitsException : public std::exception {};
private:
    T* _array;
    int _size;
};

#include "Array.tpp"