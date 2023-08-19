#include <iostream>
#include <vector>
#include <cassert>
#include "utility.h"

//_______________________________________________________________________________________________________________________________________________________________________
int main()
{
    setlocale(LC_ALL, "Rus");

    int starting_input{};

    std::cout << "Введите конвертируемое число: \n";
    std::cin >> starting_input;                               // Чтение строки
    std::cout << "Результат:\n";

    assert(std::cin.fail() == false);                         // На случай некоректного ввода

    std::vector<int> input_numbers = convertIntToVector(starting_input);

    if (!input_numbers.empty())
    {
        numConverter converter(input_numbers);
        std::cout << converter.convertNum();                  // Вызов функции
    }
}