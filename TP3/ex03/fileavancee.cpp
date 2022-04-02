#include "fileavancee.hpp"

Tableau &FileAvancee::operator()(int l)
{
    int to_alloc = std::min(l, File::length()); 
    Tableau *ret = new Tableau(to_alloc);
    Personne a;

    if(to_alloc <= 0)
        return *ret;
    for(int i = 0; i < to_alloc; i++)
    {
        *this>>a;
        ret->operator[](i) = a;
    }
    return *ret;
}