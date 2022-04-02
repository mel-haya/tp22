#include "file.hpp"

Personne::Personne()
{
    nom = "anon";
    date_embauche.jour = 20;
    date_embauche.mois = 2;
    date_embauche.annee = 2022;
}

Personne::Personne(std::string n, int d, int m, int y)
{
    nom = n;
    date_embauche.jour = d;
    date_embauche.mois = m;
    date_embauche.annee = y;
}

void Personne::define_personne()
{
    std::cout << "Nom : ";
    std::cin >> nom;
    std::cout << "Date embauche (jj mm aaaa) : ";
    std::cin >> date_embauche.jour >> date_embauche.mois >> date_embauche.annee; 
}

std::string Personne::to_string() const
{
    return nom + "\tEmbauche : " + date_embauche.to_string();
}


void Personne::annencer()
{
    std::cout << this->to_string() << std::endl;
}



File::File()
{
    arr = new Personne[10];
    size = 10;
    start = -1;
    end = -1;
}

File::~File()
{
    delete [] arr;
}

File::File(const File &c)
{
    *this = c;
}

File &File::operator=(const File& c)
{
    if(this != &c)
    {
        arr = new Personne[c.size];
        start = c.start;
        end = c.end;
        size = c.size;
        for(int i = 0; i < size ; i++)
            arr[i] = c.arr[i]; 
    }
    return *this;
}

File &File::operator<<(Personne &p)
{
    if (start == -1)
    {
        start = 0;
        end = 0;
        arr[end] = p;
        return *this;
    }
    if ((end + 1) % size == start)
    {
        Personne *tmp = new Personne[size + 10];
        int j = start;
        for(int i = 0; i < size; i++)
        {
            tmp[i] = arr[j];
            j = (j + 1) % size;
        }
        delete [] arr;
        arr = tmp;
        start = 0;
        end = size - 1;
        size += 10;
    }
    end = (end + 1) % size;
    arr[end] = p;
    return *this;
}

File &File::operator>>(Personne &p)
{
    if (start == -1)
        return *this;
    p = arr[start];
    if (start == end)
    {
        start = -1;
        end = -1;
    }
    else
        start = (start + 1) % size;
    return *this;
}