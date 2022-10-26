#include "Vector.h"
#include <iostream>

int main()
{
    Point a(1, 0);
    Point b(0, 2);
    Point c(4, 0);
    Point d(0, 5);
    Vector vector1(a, b);
    Vector vector2(c, d);
    std::cout << vector1 * vector2;
    std::cout << (vector1 == vector1);
    std::cout << vector1 << "\n";
    std::cin >> vector1;
    std::cout << vector1;
}