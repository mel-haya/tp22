#include "ensemble.hpp"

Ensemble::Ensemble()
{
}

Ensemble::~Ensemble()
{
}

void Ensemble::ajouter(int val)
{
    if(val < 0 || c.contains(val))
        return;
    c.add(val);
}

void Ensemble::supprimer(int val)
{
    if(val < 0)
        return;
    c.remove(val);
}

Ensemble &Ensemble::operator+(Ensemble l)
{
    int s = l.c.size();
    for(int i = 0; i < s; i++)
    {
        c.add(l.c.gets(i));
    }
    return *this;
}

Ensemble &Ensemble::operator-(Ensemble l)
{
    int s = l.c.size();
    for(int i = 0; i < s; i++)
    {
        c.remove(l.c.gets(i));
    }
    return *this;
}

void Ensemble::print()
{
    c.print();
}
