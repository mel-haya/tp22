#include "matrice.hpp"

int Matrice::count = 0;

int main()
{
    Matrice *a = new Matrice(2,3);
    Matrice *b = new Matrice(2,2);
    Matrice *c = new Matrice();

    a->set(0,0,1);
    a->set(1,0,2);
    a->set(0,1,0);
    a->set(1,1,4);
    a->set(0,2,3);
    a->set(1,2,-1);

    b->set(0,0,2);
    b->set(1,0,0);
    b->set(0,1,1);
    b->set(1,1,-3);

    a->multiplication(b,c);

    a->affiche();
    std::cout << " X " << std::endl;
    b->affiche();
    std::cout << " = " << std::endl;
    c->affiche();
    delete a;
    delete b;
    delete c;
}