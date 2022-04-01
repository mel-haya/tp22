#include "liste.hpp"
#include <iostream>

liste_case::liste_case(int val, liste_case *next):value(val){
    this->next = next;
}

liste::liste(){
    root = NULL;
}

liste::liste(int *arr, int length)
{
    root = NULL;
    for(int i = 0; i < length; i++)
        add(arr[i]);
}

void liste::add(int val)
{
    if(val < 0)
        return;
    if(!root)
        root = new liste_case(val, 0);
    else
    {
        liste_case *tmp = root;
        while(tmp)
        {
            if(!tmp->next)
            {
                tmp->next = new liste_case(val, 0);
                return;
            }
            tmp = tmp->next;
        }
    }
}
int liste::size()
{
    int s = 0;
    liste_case* tmp = root;
    while (tmp)
    {
        s++;
        tmp = tmp->next;
    }
    return (s);     
}
bool liste::contains(int val)
{
    liste_case* tmp = root;
    if(!root)
        return false;
    while (tmp)
    {
        if(tmp->value == val)
            return true;
        tmp = tmp->next;
    }
    return (false);
}

int liste::gets(int index)
{
    liste_case *tmp = root;

    if(index < 0 || !root)
        return -1;
    for(int i = 0; tmp ; i++)
    {
        if (i == index)
            return tmp->value;
        tmp = tmp->next;
    }
    return -1;
}

void liste::remove(int value)
{
    liste_case *tmp = root;
    liste_case *tmp2;
    if(!root)
        return;
    if(tmp->value == value)
    {
        tmp2 = root->next;
        delete root;
        root = tmp2;
        return;
    }
    while(tmp->next)
    {
        if(tmp->next->value == value)
        {
            tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
            return;
        }
        tmp = tmp->next;
    }
}

void liste::print()
{
    liste_case *tmp = root;

    while (tmp->next)
    {
        std::cout << tmp->value << " - ";
        tmp = tmp->next;
    }
    std::cout << tmp->value << std::endl;
}

liste::~liste()
{
    while(root)
        remove(root->value);
}

liste::liste(const liste &c)
{
    *this = c;
}

liste & liste::operator = (const liste &c)
{
    if(this != &c)
    {
        root = NULL;
        liste_case *tmp = c.root;
        while(tmp)
        {
            add(tmp->value);
            tmp = tmp->next;
        }
    }
    return *this;
}
