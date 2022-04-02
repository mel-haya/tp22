#include "file.hpp"

int main()
{
    Personne a("Pierre",22,5,2012),b("Paul",17,2,2015),c("Jack",26,8,2013);
    Personne d,e;

    File f;
    f << a << b << c;
    f >> d >> e;
    d.annencer();
    e.annencer();
}