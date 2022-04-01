#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include "liste.hpp"

class ensemble
{
private:
    liste c;
public:
    ensemble();
    ~ensemble();
    void ajouter(int val);
    void supprimer(int val);
    ensemble &operator+(ensemble l);
    ensemble &operator-(ensemble l);
    void print();
};
#endif