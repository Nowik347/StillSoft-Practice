#include <iostream>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    for (int i{ 0 }; i < std::size(array) - 1; i++)
    {
        for (int j{ 0 }; j < std::size(array) - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }

    for (int j{ 0 }; j < std::size(array); j++)
    {
        std::cout << array[j] << " ";
    }
}