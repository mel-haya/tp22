#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>


template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
int max(T* arr, int size)
{
    int ret = 0;
    for(int i = 1; i < size ; i++)
    {
        if(arr[i] > arr[ret])
            ret = i;
    }
    return ret;
}


template <class T>
void sort(T *arr, int size)
{
    int limit = size;
    while(limit)
    {
        swap(arr[limit - 1], arr[max(arr, limit)]);
        limit--;
    }
}

#endif