#ifndef ABR_HPP
#define ABR_HPP

#include <iostream>

template<class T>
struct ABRnode
{
    typedef T valueType;
    valueType value;
    ABRnode *left;
    ABRnode *right;
    ABRnode(valueType value):value(value)
    {
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<class T>
void deleteTree(ABRnode<T> *root)
{
    if(!root)
        return;
    if(root->left)
        deleteTree(root->left);
    if(root->right)
        deleteTree(root->right);
    delete root;
}

template<class T>
ABRnode<T> *addnodes(ABRnode<T>* root)
{
    if (root == nullptr) 
        return nullptr;
    ABRnode<T>* c = new ABRnode<T>(root->value);
    c->left = addnodes(root->left);
    c->right = addnodes(root->right);
    return c;
}


template<class T>
class ArbreBinaireRecherche
{
    private:
        ABRnode<T> *root;
    public:
        ArbreBinaireRecherche()
        {
            root = nullptr;
        }
        ~ArbreBinaireRecherche()
        {
            deleteTree(root);
        }
        ArbreBinaireRecherche(ArbreBinaireRecherche &c)
        {
            *this = c;
        }
        ABRnode<T> *getRoot()
        {
            return root;
        }
        ArbreBinaireRecherche &operator=(ArbreBinaireRecherche &c)
        {
            if(this != &c)
                root = addnodes(c.root);
            return *this;
        }
        bool operator[](T val)
        {
            ABRnode<T> *tmp = root;
            while(tmp)
            {
                if(val == tmp->value)
                    return true;
                if(val < tmp->value)
                    tmp = tmp->left;
                else if(val > tmp->value)
                    tmp = tmp->right;
            }
            return false;
        }
        ArbreBinaireRecherche &operator<<(T val)
        {
            ABRnode<T> *tmp = root;
            if(!root)
            {
                root = new ABRnode<T>(val);
                return *this;
            }
            while(tmp)
            {
                if(val == tmp->value)
                    return *this;
                if(val < tmp->value)
                {
                    if(tmp->left)
                        tmp = tmp->left;
                    else
                    {
                        tmp->left = new ABRnode<T>(val);
                        return *this;
                    }
                }
                else if(val > tmp->value)
                {
                    if(tmp->right)
                        tmp = tmp->right;
                    else
                    {
                        tmp->right = new ABRnode<T>(val);
                        return *this;
                    }
                }
            }
            return *this;
        }
        ArbreBinaireRecherche &operator>>(T val)
        {
            ABRnode<T> *tmp = root;
            ABRnode<T> *tmp2;
            ABRnode<T> *parent = root;
            if(!this->operator[](val))
            {
                return *this;
            }
            if(root->value == val && !root->left && !root->right)
            {
                delete root;
                root = nullptr;
                return *this;
            }
            while(tmp)
            {
                if(tmp->value == val)
                {   
                    if(tmp->left)
                    {
                        parent = tmp;
                        tmp2 = tmp->left;
                        if(!tmp2->right)
                        {
                            tmp->value = tmp2->value;
                            tmp->left = tmp2->left;
                            delete tmp2;
                            return *this;
                        }
                        while (tmp2->right)
                        {
                            parent = tmp2;
                            if(tmp2->right)
                                tmp2 = tmp2->right;
                        }
                        tmp->value = tmp2->value;
                        if(tmp2->left)
                        {
                            tmp = tmp2->left;
                            tmp2->value = tmp->value;
                            tmp2->right = tmp->right;
                            tmp2->left = tmp->left;
                            delete tmp;
                            return *this;
                        }
                        parent->right = nullptr;
                        delete tmp2;
                        return *this;
                    }
                    if(tmp->right)
                    {
                        parent = tmp;
                        tmp2 = tmp->right;
                        if(!tmp2->left)
                        {
                            tmp->value = tmp2->value;
                            tmp->right = tmp2->right;
                            delete tmp2;
                            return *this;
                        }
                        while (tmp2->left)
                        {
                            parent = tmp2;
                            if(tmp2->left)
                                tmp2 = tmp2->left;
                        }
                        tmp->value = tmp2->value;
                        if(tmp2->right)
                        {
                            tmp = tmp2->right;
                            tmp2->value = tmp->value;
                            tmp2->left = tmp->left;
                            tmp2->right = tmp->right;
                            delete tmp;
                            return *this;
                        }
                        parent->left = nullptr;
                        delete tmp2;
                        return *this;
                    }
                    else
                    {
                        if(parent->right == tmp)
                            parent->right = nullptr;
                        else if (parent->left == tmp)
                            parent->left = nullptr;
                        delete tmp;
                        return *this;
                    }
                }
                else if(tmp->value > val)
                {
                    parent = tmp;
                    tmp = tmp->left;
                }
                else if(tmp->value < val)
                {
                    parent = tmp;
                    tmp = tmp->right;
                }
            }
            return *this;
        }
    
};

#endif



