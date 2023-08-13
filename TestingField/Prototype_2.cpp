#include <iostream>
#include <conio.h>
#include "utility.h"

#define tripletSum input_nums[i] + input_nums[i + 1] + input_nums[i + 2] // Сумма текущего разряда

std::string numToTextConvert(int* input_nums, bool add_rubles, int length); // Прототип для удобности чтения

//_______________________________________________________________________________________________________________________________________________________________________
int main()
{
    setlocale(LC_ALL, "Rus");

    const int g_input_length{ 10 };

    bool add_rubles;                                          // Переменная валюты

tryagain:
    std::cout << "Добавлять рубли к конечной строке на этот сеанс? (y/n)\n";

    switch (_getch())                                         // Проверка выбора
    {
    case 'y': case 'Y':
        add_rubles = true;
        break;
    case 'n': case 'N':
        add_rubles = false;
        break;
    default:
        system("cls");
        goto tryagain;
    }

    int length{ 0 }, *input_numbers{ 0 };

    char starting_input[g_input_length];                      // Массив ввода

    std::cout << "Введите конвертируемое число: \n";
    std::cin.getline(starting_input, g_input_length);         // Чтение строки
    std::cout << "Результат:\n";

    input_numbers = convertCharArrToIntArr(starting_input, length);

    if (input_numbers)
        std::cout << numToTextConvert(input_numbers, add_rubles, length);  // Вызов функции
}
//_______________________________________________________________________________________________________________________________________________________________________
std::string numToTextConvert(int* input_nums, bool add_rubles, int length)      // Функция разбивки
{
    std::string result_string;                                                  // Строка вывода

    reverseArray(input_nums, length);

    if (add_rubles)                                                             // Добавляем рубли
    {
        result_string = input_nums[1] == 1 ? g_dictionary[2][0][0][0] : g_dictionary[2][0][0][input_nums[0]];

        add_rubles = false;
    }

    short tens_index{ 1 };                                                      // Индекс десятков текущего разряда

    for (short i{ 0 }; i < length; i++)                                         // Проверяем массив по очереди
    {
        if (i % 3 == 0 && tripletSum != 0)                                      // Каждые три цикла
            if (i / 3 != 0)                                                     // Только в тысячах/миллионах
            {
                tens_index += 3;                                                // Смещаем указатель на десяток разряда
                result_string = g_dictionary[2][input_nums[tens_index] == 1][i / 3][input_nums[i]] + result_string; // Добавляем тысячи/миллионны
            }

        result_string = g_dictionary[input_nums[tens_index] == 1][i / 3 == 1][i % 3][input_nums[i]] + result_string; // Кидаем число и индекс на съедение словарю
    }

    std::fill_n(input_nums, length, NULL);                                      // Обнуляем ввод

    return result_string;
}