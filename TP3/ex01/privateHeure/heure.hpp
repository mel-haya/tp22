#ifndef HEURE_HPP
#define HEURE_HPP 

#include <iostream>

class Heure
{
    private:
        int heure;
        int minute;
        int sec;
    public:
        Heure(int h, int m, int s);
        virtual void afficher();
        virtual bool operator>(Heure &rhs);
};
#endif