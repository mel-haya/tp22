#ifndef DATEH_HPP
#define DATEH_HPP

#include "heure.hpp"

class DateH:public Heure
{
    private:
        int annee;
        int mois;
        int jour;
    public:
        DateH(int a,int m,int j, int h, int mm, int s);
        void afficher();
        bool operator>(DateH &rhs);

};
#endif