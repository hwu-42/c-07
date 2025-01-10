#include <iostream>
#include <string>
#include "../include/iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}
template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];
  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );
  return 0;
}

/*
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
}*/