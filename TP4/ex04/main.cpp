#include "ArbreBinaireRecherche.hpp"
#include <iostream>
#include "person.hpp"

template<class T>
void   print_inorder(ABRnode<T> *root)
{
    if (root)
    {
        print_inorder(root->left);
        std::cout << root->value <<std::endl;
        print_inorder(root->right);
    }
}

int main()
{
    ArbreBinaireRecherche<Person> a;
    std::cout << "<<<<<<<<<PERSON>>>>>>>>>" << std::endl;
    a << Person("Gabriel" , 23) << Person("Louis" , 21) << Person("Camille", 19) << Person("Marie" , 25) << Person("Jean" , 43) << Person("Alice", 32);
    print_inorder(a.getRoot());

    std::cout << "<<<<<<<<<INT>>>>>>>>>" << std::endl;
    ArbreBinaireRecherche<int> b;

    b << 19 << 16 << 33 << 75 << 93 << 8;
    print_inorder(b.getRoot());
}

