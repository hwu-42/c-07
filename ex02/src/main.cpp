#include <iostream>
#include <string>
#include "../include/Array.hpp"

typedef struct {
    int x;
    int y;
} Point;

class Pc {
public:
    Pc() : _ram(0), _cpu(0), brand("nobrand") {}
    Pc(int ram, int cpu, std::string b ) : _ram(ram), _cpu(cpu), brand(b ) {}
    int ram() const { return _ram; }
    int cpu() const { return _cpu; }
    std::string getbrand() const { return brand; }
    
private:
    int _ram;
    int _cpu;
    std::string brand;
};

int main() {

    Pc pc1(4, 2, "dell");

    Pc pc2;
    pc2 = pc1;
    std::cout << "pc2: ram: " << pc2.ram() << ", cpu: " << pc2.cpu() << pc2.getbrand() << std::endl;
    // Default constructor
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;

    // Constructor with size
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;

    // Access and modify elements
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = i * 10;
    }

    std::cout << "arr2 contents: ";
    for (int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // Copy constructor
    Array<int> arr3(arr2);
    std::cout << "arr3 (copy of arr2) contents: ";
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    // Modify original, check copy remains unchanged
    arr2[0] = 999;
    std::cout << "arr2[0]: " << arr2[0] << ", arr3[0]: " << arr3[0] << std::endl;

    // Assignment operator
    Array<int> arr4 = arr2;
    std::cout << "arr4 (assigned from arr2) contents: ";
    for (int i = 0; i < arr4.size(); i++) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    // Out-of-bounds access
    try {
        std::cout << "Accessing out-of-bounds index: " << arr2[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Array<Point> arr5(3);
    arr5[0].x = 1;
    arr5[0].y = 2;
    arr5[1].x = 3;
    arr5[1].y = 4;
    arr5[2].x = 5;
    arr5[2].y = 6;

    std::cout << "arr5 contents: ";
    for (int i = 0; i < arr5.size(); i++) {
        std::cout << "(" << arr5[i].x << ", " << arr5[i].y << ") ";
    }
    std::cout << std::endl;

    Array<Point> arr6(arr5.size());
    arr6 = arr5;
    std::cout << "arr5 contents: ";
    for (int i = 0; i < arr5.size(); i++) {
        std::cout << "(" << arr5[i].x << ", " << arr5[i].y << ") ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "test for no assign copy class type" << std::endl;

    Array<Pc> arr7(2);
    arr7[0] = Pc(8, 4, "dell");
    arr7[1] = Pc(6, 2, "hp");

    std::cout << "arr7 contents: ";
    for (int i = 0; i < arr7.size(); i++) {
        std::cout << "ram: " << arr7[i].ram() << ", cpu: " << arr7[i].cpu() << std::endl;
    }

    Array<Pc> arr8(arr7.size());
    arr8 = arr7;
    std::cout << "arr8 contents: ";
    for (int i = 0; i < arr8.size(); i++) {
        std::cout << "ram: " << arr8[i].ram() << ", cpu: " << arr8[i].cpu() << std::endl;
    }

    return 0;
}
