#ifndef FORMES_HPP
#define FORMES_HPP

#include <iostream>
#include <cstdlib>

class Forme
{
    protected:
        bool status;
    public:
        Forme(void);
        virtual void afficher(void) = 0;
        void rotation(void);
};

class Carre : public Forme
{
    public:
        void afficher(void);
};

class Triangle : public Forme
{
    public:
        void afficher(void);
};

class Cercle : public Forme
{
    public:
        void afficher(void);
};

#endif