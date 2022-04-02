#ifndef LISTE_CASE
#define LISTE_CASE

#include "liste.hpp"

class Liste_case
{
    private:
        int value;
        Liste_case *next;
    public:
        Liste_case(int val, Liste_case *next);
        friend class Liste;//required to access next element
};

#endif