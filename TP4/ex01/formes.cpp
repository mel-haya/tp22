#include "formes.hpp"

Forme::Forme(void)
{
    status = false;
}

void Forme::rotation(void)
{
    status = !status;
}

void Carre::afficher()
{
    if(!status)
    {
        std::cout << std::endl;
        std::cout << "*****" << std::endl;
        std::cout << "*   *" << std::endl;
        std::cout << "*   *" << std::endl;
        std::cout << "*****" << std::endl;
    }
    else
    {
        std::cout << "  *" << std::endl;
        std::cout << " * *" << std::endl;
        std::cout << "*   *" << std::endl;
        std::cout << " * *" << std::endl;
        std::cout << "  *" << std::endl;
    }
}

void Cercle::afficher()
{
    std::cout << "  **" << std::endl;
    std::cout << " *  *" << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << " *  *" << std::endl;
    std::cout << "  **" << std::endl;
}

void Triangle::afficher()
{
    if(!status)
    {
        std::cout << "   *" << std::endl;
        std::cout << "  * *" << std::endl;
        std::cout << " *   *" << std::endl;
        std::cout << "*******" << std::endl;
    }
    else
    {
        std::cout << "*******" << std::endl;
        std::cout << " *   *" << std::endl;
        std::cout << "  * *" << std::endl;
        std::cout << "   *" << std::endl;
    }
}