#ifndef ABR_HPP
#define ABR_HPP

struct ABRnode
{
    int value;
    ABRnode *left;
    ABRnode *right;
    ABRnode(int value);
};

class ArbreBinaireRecherche
{
    private:
        ABRnode *root;
    public:
        ArbreBinaireRecherche();
        ~ArbreBinaireRecherche();
        ArbreBinaireRecherche(ArbreBinaireRecherche &c);
        ArbreBinaireRecherche &operator=(ArbreBinaireRecherche &c);
        bool operator[](int val);
        ArbreBinaireRecherche &operator<<(int val);
        ArbreBinaireRecherche &operator>>(int val);
};

#endif



