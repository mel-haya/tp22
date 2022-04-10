#include "sort.hpp"

int main()
{
    int arr[10] = {19, 9, 5, 18, 42, 29, 76, 11 ,3 , 17};
    std::cout << "-before sort\n"; 
    for(int i = 0; i < 9; i++)
        std::cout << arr[i] << " - ";
    std::cout << arr[9] << std::endl;
    std::cout << "-after sort\n"; 
    sort(arr, 10);
    for(int i = 0; i < 9; i++)
        std::cout << arr[i] << " - ";
    std::cout << arr[9] << std::endl;
}