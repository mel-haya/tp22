#include "fileavancee.hpp"

int main()
{
    Personne a("Pierre",22,5,2012),b("Paul",17,2,2015),c("Jack",26,8,2013),d("Martin",18,4,2020);
    Personne e("Bernard",21,11,2017),f("Thomas",17,5,2016),g("Robert",26,4,2013),h("David",21,5,2018);

    FileAvancee file;
    file << a << b << c << d << e << f << g << h;
    Tableau &t = file(30);
    for(int i = 0; i < t.size(); i++)
        t[i].annencer();
    delete &t;
}