#include "ensemble.hpp"

ensemble::ensemble()
{
}

ensemble::~ensemble()
{
}

void ensemble::ajouter(int val)
{
    if(val < 0 || c.contains(val))
        return;
    c.add(val);
}

void ensemble::supprimer(int val)
{
    if(val < 0)
        return;
    c.remove(val);
}

ensemble &ensemble::operator+(ensemble l)
{
    int s = l.c.size();
    for(int i = 0; i < s; i++)
    {
        c.add(l.c.gets(i));
    }
    return *this;
}

ensemble &ensemble::operator-(ensemble l)
{
    int s = l.c.size();
    for(int i = 0; i < s; i++)
    {
        c.remove(l.c.gets(i));
    }
    return *this;
}

void ensemble::print()
{
    c.print();
}

int main()
{
    ensemble a;
    ensemble b;
    ensemble c;

    a.ajouter(5);
    a.ajouter(52);
    a.ajouter(51);
    a.ajouter(544);
    a.ajouter(85);

    b.ajouter(25);
    b.ajouter(56);
    b.ajouter(18);

    c.ajouter(51);
    c.ajouter(544);

    a.print();
    b.print();

    a = a + b;

    a.print();

    a.supprimer(25);

    a.print();

    a = a - c;

    a.print();

    return 0;
}