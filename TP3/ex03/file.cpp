#include "file.hpp"

Personne::Personne()
{
    nom = "anon";
}

Personne::Personne(std::string n)
{
    nom = n;
}

void Personne::annencer()
{
    std::cout << "my name is " << nom << std::endl;
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

int File::length()
{
    int count = 1;
    if(start == -1)
        return 0;
    for(int i = start; i != end ; i = (i + 1) % size)
        count++;
    return count;
}