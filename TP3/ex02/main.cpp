#include "tableau_borne.hpp"

int main()
{
    Tableau_borne t(10,2,10);
    int i;
    t(5,5);
    t(0,3);
    t(25,16);
    for(i = 0; i < 9 ; i++)
        std::cout << t[i] << " - ";
    std::cout << t[i] << std::endl;
    return 0;
}