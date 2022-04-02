#include "liste.hpp"
#include <iostream>

Liste_case::Liste_case(int val, Liste_case *next):value(val){
    this->next = next;
}

Liste::Liste(){
    root = NULL;
}

Liste::Liste(int *arr, int length)
{
    root = NULL;
    for(int i = 0; i < length; i++)
        add(arr[i]);
}

void Liste::add(int val)
{
    if(val < 0)
        return;
    if(!root)
        root = new Liste_case(val, 0);
    else
    {
        Liste_case *tmp = root;
        while(tmp)
        {
            if(!tmp->next)
            {
                tmp->next = new Liste_case(val, 0);
                return;
            }
            tmp = tmp->next;
        }
    }
}
int Liste::size()
{
    int s = 0;
    Liste_case* tmp = root;
    while (tmp)
    {
        s++;
        tmp = tmp->next;
    }
    return (s);     
}
bool Liste::contains(int val)
{
    Liste_case* tmp = root;
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

int Liste::gets(int index)
{
    Liste_case *tmp = root;

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

void Liste::remove(int value)
{
    Liste_case *tmp = root;
    Liste_case *tmp2;
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

void Liste::print()
{
    Liste_case *tmp = root;

    while (tmp->next)
    {
        std::cout << tmp->value << " - ";
        tmp = tmp->next;
    }
    std::cout << tmp->value << std::endl;
}

Liste::~Liste()
{
    while(root)
        remove(root->value);
}

Liste::Liste(const Liste &c)
{
    *this = c;
}

Liste & Liste::operator = (const Liste &c)
{
    if(this != &c)
    {
        root = NULL;
        Liste_case *tmp = c.root;
        while(tmp)
        {
            add(tmp->value);
            tmp = tmp->next;
        }
    }
    return *this;
}
