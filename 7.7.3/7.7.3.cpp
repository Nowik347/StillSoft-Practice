#include <iostream>

// Цикл от 1 до 5
int main()
{
    int outer{ 5 };

    while (outer >= 1)
    {
        // цикл от 1 до outer
        int inner{ outer };

        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        // выводим символ новой строки в конце каждой строки
        std::cout << '\n';
        --outer;
    }

    return 0;
}