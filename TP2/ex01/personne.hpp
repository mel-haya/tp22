#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
#include <iostream>

class Personne
{
    private:
        std::string nom;
    public:
        Personne();
        Personne(std::string n);
        void annencer();
};

#endif