#ifndef LISTE_CASE
#define LISTE_CASE

#include "liste.hpp"

class liste_case
{
    private:
        int value;
        liste_case *next;
    public:
        liste_case(int val, liste_case *next);
        friend class liste;//required to access next element
};

#endif