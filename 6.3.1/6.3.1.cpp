#include <iostream>

int main()
{
    int smaller, larger; // Создание переменной Меньшее и Большее

    std::cout << "Enter an integer: "; 
    std::cin >> smaller;

    std::cout << "Enter a larger integer: "; 
    std::cin >> larger;

    if (larger < smaller)
    {
        std::cout << "Swapping the values";

        int temp; // Создание временной переменной

        temp = larger;
        larger = smaller;
        smaller = temp;
    } // Временная переменная уничтожается

    std::cout << "\nThe smaller value is " << smaller
        << "\nThe larger value is " << larger;
} // Меньшее и Большее уничтожаются