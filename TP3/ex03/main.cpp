#include "file.hpp"
#include "fileavancee.hpp"

int main()
{
    Personne a("Pierre"),b("Paul"),c("Jack"),d("Martin"),e("Bernard"),f("Thomas"),g("Robert");

    FileAvancee file;
    file << a << b << c << d << e << f << g;
    Tableau &t = file(4);
    for(int i = 0; i < 4; i++)
        t[i].annencer();
    delete &t;
}