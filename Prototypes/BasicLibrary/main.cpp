#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

#include "functions.h"

int main() {
    int a = -8, b = 2;
    std::cout << std::max(a, b) << std::endl; // 2
    std::cout << itandroids::max(a, b) << std::endl; // 64

    std::swap(a, b);
    std::cout << a << " " << b << std::endl; // 2 -8
    itandroids::swap(a, b);
    std::cout << a << " " << b << std::endl; // 2 -8

    float c = 2, d = 4;
    std::cout << std::pow(c,d) << std::endl; // 16
    std::cout << c << " " << d << std::endl; // 2 4
    itandroids::pow(&c, &d);
    std::cout << c << " " << d << std::endl; // 16 4

    char arr[] = {'v', 's', 's'};
    printArray(arr); // v s s
    itandroids::printArray(arr); // s s v

    return 0;
}
