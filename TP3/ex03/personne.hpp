#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
#include <iostream>

struct date 
{
    int jour;
    int mois;
    int annee;

    std::string to_string() const
    {
        return std::to_string(jour) + '/' + std::to_string(mois) + '/' + std::to_string(annee);
    }
};

class Personne
{
    private:
        std::string nom;
        date date_embauche;
    public:
        Personne();
        Personne(std::string n, int d, int m, int y);
        void annencer();
        void define_personne();
        std::string to_string() const;
};

#endif