#include "file.hpp"

int main()
{
    Personne a("Pierre"),b("Paul"),c("Jack");
    Personne d,e;

    File f;
    f << a << b << c;
    f >> d >> e;
    d.annencer();
    e.annencer();
}