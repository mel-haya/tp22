#ifndef Liste_HPP
#define Liste_HPP

#include "liste_case.hpp"
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