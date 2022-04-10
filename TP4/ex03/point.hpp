#ifndef POINT_HPP
#define POINT_HPP

template<class T, unsigned int S>
class Point
{
    private:
        T*  coords;
    public:
        Point(T *src)
        {
            coords = new T[S];
            for(int i = 0; i < S; i++)
                coords[i] = src[i];
        }

        Point operator+(Point rhs)
        {
            if(this->S != rhs.S)
                return *this;
            Point ret = Point(this->coords, size);
            for(int i = 0; i < this->size ; i++)
            {
                ret.coords[i] += rhs.coords[i];
            }
            return ret;
        }

        T operator*(Point rhs)
        {
            if(this->size != rhs.size)
                return 0;
            T ret = 0;
            for(int i = 0; i < this->size ; i++)
            {
                ret += this.coords[i] * rhs.coords[i];
            }
            return ret;
        }

        T operator[] (int i) const
        {
            return coords[i];
        }

        T getSize()
        {
            return this->size;
        }

};

template<class T>
Point<T> concat(Point<T> &lhs, Point<T> &rhs)
{
    T* coords = new T[lhs.getSize() + rhs.getSize()];

    for(int i = 0; i < lhs.getSize(); i++)
        coords[i] = lhs[i];
    for(int i = 0; i < rhs.getSize(); i++)
        coords[lhs.getSize() + i] = rhs[i];
    Point<T> ret = Point(coords, lhs.getSize() + rhs.getSize());
    delete [] coords;
    return ret;
}

#endif