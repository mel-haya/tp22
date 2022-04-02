#include "tableau.hpp"

Tableau::Tableau(int i)
{
    length = i;
    arr = new Personne[length];
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
        arr = rhs.arr;
    }
    return *this;
}

Personne &Tableau::operator[](int index)
{
    if(index < 0 || index > length)
        index = 0;
    return arr[index];
}
