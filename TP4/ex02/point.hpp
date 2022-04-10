#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

template<class T>
class Point
{
    private:
        T x;
        T y;
    public:
        Point(T a, T b):x(a), y(b) {}
        Point operator+(Point &rhs)
        {
            x += rhs.x;
            y += rhs.y;
        }
        bool operator>(Point &rhs)
        {
            if(x == rhs.x)
                return y > rhs.y;
            return x > rhs.y; 
        }
        friend std::ostream& operator<<(std::ostream& os, Point& dt)
        {
            os << "(" << dt.x << ", " << dt.y << ") ";
            return os;
        }
};
#endif