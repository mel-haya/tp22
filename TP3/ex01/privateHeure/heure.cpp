#include "heure.hpp"

Heure::Heure(int h, int m, int s)
{
    if (h >= 0 && h < 24)
        this->heure = h;
    else
        this->heure = 0;
    if (m >= 0 && m < 60)
        this->minute = m;
    else
        this->minute = 0;
    if (s >= 0 && s < 60)
        this->sec = s;
    else
        this->sec = 0;
}

void Heure::afficher()
{
    if(heure < 10)
        std::cout << "0";
    std::cout << heure << " : ";
    if(minute < 10)
        std::cout << "0";
    std::cout<< minute << std::endl;
}
bool Heure::operator>(Heure &rhs)
{
    int first = (this->heure * 3600) + (this->minute * 60) + this->sec;
    int second =  (rhs.heure * 3600) + (rhs.minute * 60) + rhs.sec;
    return (first > second);
}

// int main()
// {
//     Heure a(17,22,5), b(15,32,44);

//     a.afficher();
//     b.afficher();

//     if(a > b)
//         a.afficher();
//     else
//         b.afficher();
// }