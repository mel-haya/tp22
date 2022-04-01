#ifndef LISTE
#define LISTE

#include "liste_case.hpp"
class liste
{
    private:
        liste_case *root;
    public:
        liste();
        liste(int *arr, int length);
        liste(const liste &c);
        ~liste();
        void add(int val);
        int size();
        bool contains(int val);
        int gets(int index);
        void remove(int value);
        void print();
        liste & operator = (const liste &c);
};


#endif