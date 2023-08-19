#include <iostream>
#include <cassert>
#include <stack>
#include "utility.h"

std::string convert(int starting_input)
{
    std::stack<int>input_numbers = convertIntToStack(starting_input);   // Превращаем целое в стек

    std::string result_string{};                            // Строка вывода

    numConverter con(input_numbers);                        // Создаем класс и привязываем стек

    while (!con.finished())                                 // Конвертируем пока не кончатся числа
    {
        result_string += con.outputString();
    }

    return result_string;
}
//_______________________________________________________________________________________________________________________________________________________________________
int main()
{
    setlocale(LC_ALL, "Rus");

    int starting_input;

    std::cout << "Введите конвертируемое число: \n";
    std::cin >> starting_input;

    assert(std::cin.fail() == false);                       // На случай некоректного ввода

    std::cout << "Результат:\n";

    std::cout << convert(starting_input);
}