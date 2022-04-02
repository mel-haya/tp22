#include "dateh.hpp"
#include<string>

DateH::DateH(int a,int m,int j, int h, int mm, int s): Heure(h,mm,s)
{
    if(a > 0 && a < 10000)
        this->annee = a;
    else 
        this->annee = 0;
    if(m >= 0 && m < 12)
        this->mois = m;
    else
        this->mois = 0;
    int maxDays = 31;
    if(this->mois == 1)
    {
        maxDays = 28;
        if(this->annee % 4 == 0)
            maxDays++;
    }
    else if(this->mois == 1 || this->mois == 5 || this->mois == 8 || this->mois == 10)
        maxDays = 30;
    if(j > 0 && j <= maxDays)
        this->jour = j;
    else
        this->jour = 1;   
}
void DateH::afficher()
{
    std::string mo[] = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "october", "novembre", "decembre"};
    if(jour < 10)
        std::cout << "0";
    std::cout << jour << " " << mo[mois] << " " << annee << " ";
    Heure::afficher();
}

bool DateH::operator>(DateH &rhs)
{
    int joursmois[] = {0,31,59,90,120,151,181,212,243,273,304,334};
    int first = (annee * 365) + joursmois[mois] + jour + (annee / 4);
    int second = (rhs.annee * 365) + joursmois[rhs.mois] + rhs.jour + (rhs.annee / 4);

    if(first == second)
        return Heure::operator>(rhs);
    return first > second;
}
