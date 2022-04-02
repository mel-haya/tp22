#include "liste.hpp"

int main()
{
    int a[] = {5, 8 };

    Liste m(a, 2);
    Liste l(m);
    
    l.print();
    l.add(86);
    l.print();
    l.remove(8);

    if(l.contains(86))
        l.print();
    std::cout << "size = " << l.size()<< std::endl;
    
}