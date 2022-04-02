#ifndef TABLEAU_BORNE_HPP
#define TABLEAU_BORNE_HPP

#include "tableau.hpp"
#include <algorithm>
#include <iostream>

class Tableau_borne : private Tableau
{
    private:
        int min;
        int max;
        int length;
    public:
        Tableau_borne (int length, int min, int max);
        ~Tableau_borne ();
        int operator[](int index);
        bool operator()(int index, int val);
};

#endif