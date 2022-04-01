#include "matrice.hpp"

Matrice::Matrice()
{
    table = new int[1];
    width = 1;
    height = 1;
    count++;
}

Matrice::Matrice(int w, int h)
{
    table = new int[w * h];
    width = w;
    height = h;
    count++;
}
Matrice::~Matrice()
{
    delete [] table;
}

int Matrice::get(int x, int y)
{
    if(x > width || x < 0 || y > height || y < 0)
    {
        std::cerr << "get : index out of range" << std::endl;
        return 0;
    }
    return table[y * width + x];
}

void Matrice::set(int x, int y, int val)
{
    if(x > width || x < 0 || y > height || y < 0)
    {
        std::cerr << "set : index out of range" << std::endl;
        return;
    }
    table[(y * width) + x] = val;
}

int Matrice::matriceCount()
{
    return count;
}

bool Matrice::multiplication(Matrice* b, Matrice* c)
{
    if(this->width != b->height)
    {
        std::cerr<< "invalid multiplication"<< std::endl;
        return false;
    }
    delete [] c->table;
    c->table = new int[this->height * b->width];
    c->height = this->height;
    c->width = b->width;
    for(int i = 0; i < c->height; i++)
        for(int j = 0; j < c->width; j++)
            c->set(j,i,0);

    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < b->width; j++)
        {
            for(int k = 0; k < b->height ; k++)
                c->table[i * c->width + j] += get(k,i) * b->get(j,k);
        }
    }
    return true;
}

void Matrice::affiche()
{
    for(int i = 0; i < height ; i++)
    {
        std::cout<<"| ";
        for(int j = 0; j < width ; j++)
        {
            std::cout << std::setw(3) << get(j, i) << " ";
        }
        std::cout<<" |" << std::endl;
    }
}