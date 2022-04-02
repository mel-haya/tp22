#ifndef LISTE_HPP
#define LISTE_HPP

#include "liste_case.hpp"
#include <iostream>

class Liste
{
    private:
        Liste_case *root;
    public:
        Liste();
        Liste(int *arr, int length);
        Liste(const Liste &c);
        ~Liste();
        void add(int val);
        int size();
        bool contains(int val);
        int gets(int index);
        void remove(int value);
        void print();
        Liste & operator = (const Liste &c);
};


#endif