#ifndef TABLEAU_HPP
#define TABLEAU_HPP

#include <iostream>
#include <string>
#include "personne.hpp"

class Tableau
{
    private:
        Personne *arr;
        int length;
    public:
        Tableau(int i);
        ~Tableau();
        Tableau(const Tableau &c);
        Tableau &operator=(const Tableau &rhs);
        Personne &operator[](int index);
        int size();   
};
#endif