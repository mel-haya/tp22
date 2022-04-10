#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
template<class T, unsigned int S>
class Point
{
    private:
        T coords[S];
    public:
        Point(T *src)
        {
            for(int i = 0; i < S; i++)
                coords[i] = src[i];
        }

        Point operator+(Point rhs)
        {
            Point ret = Point(this->coords);
            for(int i = 0; i < S ; i++)
            {
                ret.coords[i] += rhs.coords[i];
            }
            return ret;
        }

        T operator*(Point rhs)
        {
            T ret = 0;
            for(int i = 0; i < S ; i++)
            {
                ret += this->coords[i] * rhs.coords[i];
            }
            return ret;
        }

        T operator[] (int i) const
        {
            return coords[i];
        }
};

template<class T , unsigned int S1, unsigned int S2>
Point<T, S1 + S2> concat(Point<T,S1> &lhs, Point<T,S2> &rhs)
{
    T* coords = new T[S1 + S2];

    for(int i = 0; i < S1; i++)
        coords[i] = lhs[i];
    for(int i = 0; i < S2; i++)
        coords[S1 + i] = rhs[i];
    Point<T, S1 + S2> ret = Point<T, S1 + S2>(coords);
    delete [] coords;
    return ret;
}

#endif