#include <exception>
//#include "Array.hpp"


template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(int size) : _array(new T[size]), _size(size) {}

template<typename T>
Array<T>::~Array() {
    delete[] _array;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw OutOfLimitsException();
    }
    return _array[index];
}

template<typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
    for (int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;
        _array = new T[other._size];
        _size = other._size;
        for (int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template<typename T>
int Array<T>::size() const {
    return _size;
}
