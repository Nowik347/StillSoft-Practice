#include <iostream>

const int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

int main()
{
    setlocale(LC_ALL, "Rus");

    int number, index;

tryagain:

    system("cls");

    std::cout << "Введите число от 1 до 9: ";
    std::cin >> number;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto tryagain;
    }
    else if (number > 9)
    {
        goto tryagain;
    }

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        std::cout << array[i] << " ";

        if (array[i] == number)
            index = i;
    }

    std::cout << "\nИндекс числа: " << index;
}