#ifndef FILEAVANCEE_HPP
#define FILEAVANCEE_HPP

#include "file.hpp"
#include "tableau.hpp"
#include <algorithm>

class FileAvancee : public File
{
    public:
        Tableau &operator()(int length);
};

#endif