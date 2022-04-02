#ifndef TABLEAU_HPP
#define TABLEAU_HPP

#include <iostream>
#include <string>

class Tableau
{
    private:
        int *arr;
        int length;
    public:
        Tableau(int i);
        ~Tableau();
        Tableau(const Tableau &c);
        Tableau &operator=(const Tableau &rhs);
        int &operator[](int index);     
};
#endif