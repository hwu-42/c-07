#include <iostream>
#include <string>
#include "../include/iter.hpp"

// iter function template


// Example functions to be passed to iter
void printInt(int value) {
    std::cout << value << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

template <typename T>
void increment(T& value) {
    ++value;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;

    std::cout << "Incrementing int array: ";
    iter(intArray, intSize, increment<int>);
    iter(intArray, intSize, printInt);
    std::cout << std::endl;

    std::cout << "Original string array: ";

    std::string strArray[] = {"hello", "world", "iter", "template"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    
    iter(strArray, strSize, printString);
    std::cout << std::endl;

    return 0;
}
