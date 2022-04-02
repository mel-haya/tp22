#include "tableau_borne.hpp"

Tableau_borne ::Tableau_borne (int l, int a, int b):Tableau(l) 
{
    min = std::min(a, b);

    max = std::max(a, b);
    length = l;
    for(int i = 0; i < length ; i++)
    {
        Tableau::operator[](i) = min;
    }
}

Tableau_borne::~Tableau_borne (){}

int Tableau_borne::operator[](int index)
{
    return Tableau::operator[](index);
}

bool Tableau_borne::operator()(int index, int val)
{
    if(index > length || val < min || val > max)
        return false;
    Tableau::operator[](index) = val;
    return true;
}
