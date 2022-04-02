#include "ArbreBinaireRecherche.hpp"
#include <iostream>

ABRnode::ABRnode(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

ArbreBinaireRecherche::ArbreBinaireRecherche()
{
    root = nullptr;
}

void deleteTree(ABRnode *root)
{
    if(!root)
        return;
    if(root->left)
        deleteTree(root->left);
    if(root->right)
        deleteTree(root->right);
    delete root;
}

ABRnode* addnodes(ABRnode* root)
{
    if (root == nullptr) 
        return nullptr;
    ABRnode* c = new ABRnode(root->value);
    c->left = addnodes(root->left);
    c->right = addnodes(root->right);
    return c;
}

ArbreBinaireRecherche::~ArbreBinaireRecherche()
{
    deleteTree(root);
}
ArbreBinaireRecherche::ArbreBinaireRecherche(ArbreBinaireRecherche &c)
{
    *this = c;
}
ArbreBinaireRecherche &ArbreBinaireRecherche::operator=(ArbreBinaireRecherche &c)
{
    if(this != &c)
        root = addnodes(c.root);
    return *this;
}

bool ArbreBinaireRecherche::operator[](int val)
{
    ABRnode *tmp = root;
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

ArbreBinaireRecherche &ArbreBinaireRecherche::operator<<(int val)
{
    ABRnode *tmp = root;
    if(!root)
    {
        root = new ABRnode(val);
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
                tmp->left = new ABRnode(val);
                return *this;
            }
        }
        else if(val > tmp->value)
        {
            if(tmp->right)
                tmp = tmp->right;
            else
            {
                tmp->right = new ABRnode(val);
                return *this;
            }
        }
    }
    return *this;
}



ArbreBinaireRecherche &ArbreBinaireRecherche::operator>>(int val)
{
    ABRnode *tmp = root;
    ABRnode *tmp2;
    ABRnode *parent = root;
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
            // A = node we want to delete
            // B = biggest successor on the left side
            //if there is a right node we look for B to replace A
            if(tmp->left)
            {
                parent = tmp;
                tmp2 = tmp->left;
                //if A direct left node doesn t have a right node we replace
                // the node we want to delete with the left node directly
                if(!tmp2->right)
                {
                    tmp->value = tmp2->value;
                    tmp->left = tmp2->left;
                    delete tmp2;
                    return *this;
                }
                //loop to find B
                while (tmp2->right)
                {
                    parent = tmp2;
                    if(tmp2->right)
                        tmp2 = tmp2->right;
                }
                // replace A with B 
                tmp->value = tmp2->value;
                //if B have a left node we replace him with it
                if(tmp2->left)
                {
                    tmp = tmp2->left;
                    tmp2->value = tmp->value;
                    tmp2->right = tmp->right;
                    tmp2->left = tmp->left;
                    delete tmp;
                    return *this;
                }
                //else we delete B
                parent->right = nullptr;
                delete tmp2;
                return *this;
            }
            if(tmp->right)
            {
                // same algo for the left side but in reverse
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
            // if A is a leaf with delete him directly
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
        else if(tmp->value > val) //increment to the left
        {
            parent = tmp;
            tmp = tmp->left;
        }
        else if(tmp->value < val) //increment to the right
        {
            parent = tmp;
            tmp = tmp->right;
        }
    }
    return *this;
}
