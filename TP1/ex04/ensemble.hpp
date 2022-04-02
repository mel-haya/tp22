#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include "liste.hpp"
#include <iostream>

class Ensemble
{
private:
    Liste c;
public:
    Ensemble();
    ~Ensemble();
    void ajouter(int val);
    void supprimer(int val);
    Ensemble &operator+(Ensemble l);
    Ensemble &operator-(Ensemble l);
    void print();
};
#endif