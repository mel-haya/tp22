#include "sort.hpp"
#include "point.hpp"

// int main()
// {
//     int arr[10] = {19, 9, 5, 18, 42, 29, 76, 11 ,3 , 17};
//     std::cout << "-before sort\n"; 
//     for(int i = 0; i < 9; i++)
//         std::cout << arr[i] << " - ";
//     std::cout << arr[9] << std::endl;
//     std::cout << "-after sort\n"; 
//     sort(arr, 10);
//     for(int i = 0; i < 9; i++)
//         std::cout << arr[i] << " - ";
//     std::cout << arr[9] << std::endl;
// }

int main()
{
    Point<float> arr[5] = {Point<float> (5.6,3.4), Point<float> (9.1,8.3), Point<float> (5.6,8.58), Point<float> (29.163,13.62), Point<float> (2.46,12.265)};
    std::cout << "-before sort\n"; 
    for(int i = 0; i < 4; i++)
        std::cout << arr[i] << " - ";
    std::cout << arr[4] << std::endl;
    std::cout << "-after sort\n"; 
    sort(arr, 5);
    for(int i = 0; i < 4; i++)
        std::cout << arr[i] << " - ";
    std::cout << arr[4] << std::endl;
}