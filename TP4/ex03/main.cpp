#include "point.hpp"
#include <iostream>

template<class T, unsigned int S>
void print_point(Point<T, S> p)
{
    std::cout << " {";
    for(int i = 0; i < S - 1; i++)
        std::cout << p[i] << ", ";
    std::cout << p[S - 1] << "}" << std::endl;
}

int main()
{
    int arr1[] = {5,3,2};
    int arr2[] = {8,9,5};


    Point<int,3> a = Point<int,3>(arr1);
    Point<int,3> b = Point<int,3>(arr2);
    Point<int,6> c = concat(a, b);
    Point<int,3> d = a + b;
    int e = a * b;
    std::cout << "A = ";
    print_point(a);
    std::cout << "B = ";
    print_point(b);
    std::cout << "a + b = ";
    print_point(d);
    std::cout << "a * b = " << e << std::endl;
    std::cout << "concat (a, b) = ";
    print_point(c);
}