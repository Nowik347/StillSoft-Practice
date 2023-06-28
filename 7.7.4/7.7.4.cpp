#include <iostream>
 
// Цикл от 1 до 5
int main()
{
    int outer{ 1 };

    while (outer <= 5)
    {
        // цикл от 1 до outer
        int inner{ 5 };

        while (inner >= 1)
        {
            if (inner <= outer)
                std::cout << inner << ' ';
            else
                std::cout << "  ";
            --inner;
        }
 
        // выводим символ новой строки в конце каждой строки
        std::cout << '\n';
        ++outer;
    }
 
    return 0;
}