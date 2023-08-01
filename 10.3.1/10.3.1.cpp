#include <iostream>

constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

int main()
{
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
        std::cout << array[i] << " ";
}