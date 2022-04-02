#ifndef FILE_HPP
#define FILE_HPP

#include "personne.hpp"

class File
{
    private:
        Personne *arr;
        int start;
        int end;
        int size;
    public:
        File();
        ~File();
        File(const File &c);
        File &operator=(const File& c);
        File &operator[](int index);
        File &operator<<(Personne &p);
        File &operator>>(Personne &p);
        int length();
};

#endif