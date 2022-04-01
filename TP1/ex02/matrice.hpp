#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <iomanip>

class Matrice
{
    private:
        int *table;
        int width;
        int height;
        static int count;
    public:
        Matrice();
        Matrice(int w, int h);
        ~Matrice();
        int get(int x, int y);
        void set(int x, int y, int val);
        bool multiplication(Matrice* b, Matrice* c);
        int matriceCount();
        void affiche();
};

#endif