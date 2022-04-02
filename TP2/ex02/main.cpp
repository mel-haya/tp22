#include "ArbreBinaireRecherche.hpp"
#include <iostream>

int main()
{
    ArbreBinaireRecherche a;
    ArbreBinaireRecherche b;

    a << 275 << 136 << 258 << 52 << 471 << 218 << 155 << 139 << 8 << 425 << 266;

    b = a;

    std::cout << "<<<<< before deletion >>>>>" << std::endl;

    for(int i = 0; i <= 500; i++)
    {
        if(b[i])
            std::cout << i << " is found" << std::endl;
    }

    b >> 155 >> 8 >> 425;
    
    std::cout << "<<<<< after deletion >>>>>" << std::endl;

    for(int i = 0; i <= 500; i++)
    {
        if(b[i])
            std::cout << i << " is found" << std::endl;
    }
     
}

