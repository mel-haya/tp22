#include "ensemble.hpp"

int main()
{
    Ensemble a;
    Ensemble b;
    Ensemble c;

    std::cout<< "init ensemble A" << std::endl;
    a.ajouter(5);
    a.ajouter(52);
    a.ajouter(51);
    a.ajouter(544);
    a.ajouter(85);

    std::cout<< "init ensemble B" << std::endl;
    b.ajouter(25);
    b.ajouter(56);
    b.ajouter(18);

    std::cout<< "init ensemble C" << std::endl;
    c.ajouter(51);
    c.ajouter(544);

    std::cout<< "ensemble A" << std::endl;
    a.print();
    std::cout<< "ensemble B" << std::endl;
    b.print();
    std::cout<< "ensemble C" << std::endl;
    c.print();

    a = a + b;
    std::cout<< "A = A + B" << std::endl;
    a.print();

    std::cout<< "A delete 25" << std::endl;
    a.supprimer(25);

    a.print();

    std::cout<< "A = A - C" << std::endl;
    a = a - c;

    a.print();

    return 0;
}