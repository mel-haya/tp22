#include "tableau.hpp"

Tableau::Tableau(int i)
{
    length = i;
    arr = new int[length];
}

Tableau::~Tableau()
{
    delete [] arr;
}

Tableau::Tableau(const Tableau &c)
{
    *this = c;
}
Tableau &Tableau::operator=(const Tableau &rhs)
{
    if(this != &rhs)
    {
        length = rhs.length;
        arr = new int[length];
        for(int i = 0; i < length; i++)
            arr[i] = rhs.arr[i];
    }
    return *this;
}

int &Tableau::operator[](int index)
{
    if(index < 0 || index > length)
        index = 0;
    return arr[index];
}