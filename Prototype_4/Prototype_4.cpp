#include <iostream>
#include <stack>
#include <cassert>
#include "utility.h"

std::string convert(std::stack<int> input_numbers)
{
    std::string result{};

    numConverter converter(input_numbers);

    while (!converter.isFinished())
        result += converter.convertNum();                  // Вызов функции

    return result;
}
//_______________________________________________________________________________________________________________________________________________________________________
int main()
{
    setlocale(LC_ALL, "Rus");

    int starting_input{};

    std::cout << "Введите конвертируемое число: \n";
    std::cin >> starting_input;                               // Чтение строки
    std::cout << "Результат:\n";

    assert(std::cin.fail() == false);                         // На случай некоректного ввода

    std::stack<int> input_numbers{ convertIntToStack(starting_input) };

    std::cout << convert(input_numbers);
}