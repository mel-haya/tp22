#include "dateh.hpp"

int main()
{
    DateH a(2021, 05, 29, 15, 6 ,8);
    DateH b(2021, 8, 2, 15, 6 ,8);
    if(b > a)
        b.afficher();
    return 0;
}