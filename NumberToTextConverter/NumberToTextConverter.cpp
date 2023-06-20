﻿#include <iostream>
#include <ctype.h>
#include <Windows.h>
#include <conio.h>

const std::string g_strings[5][10]{                             // Глобальный словарь
    { "", " один", " два", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" },
    { "", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " пятнадцать", " шестнадцать", " семнадцать", " восемнадцать", " девятнадцать" },
    { "", " десять", " двадцать", " тридцать", " сорок", " пятьдесят", " шестьдесят", " семьдесят", " восемьдесят", " девяносто" },
    { "", " сто", " двести", " триста", " четыреста", " пятьсот", " шестьсот", " семьсот", " восемьсот", " девятьсот" },
    { " рубль", " рубля", " рублей", " тысяча", " тысячи", " тысяч", " миллион", " миллиона", " миллионов", ""} };

std::string writeToOutput(char trichar[], int cycles)           // Вспомогательная функция конвертации
{
    int char1{ trichar[0] - '0' },                              // Временные переменные 
        char2{ trichar[1] - '0' },                              // (символы хранятся как числа ASCII таблицы так что можно просто вычесть символ нуля(0) 
        char3{ trichar[2] - '0' };                              // и получить нужный int)

    std::string resultstring;

    switch (cycles)                                             // Сколько циклов прошло?
    {
    case 1:                                                     // Тысячи
        if (char1 + char2 + char3 != 0)                         // Добавляются только если они есть
        {
            switch (char3)                                      // Правила русского языка
            {
            case 1:
                if (char2 != 1)
                {
                    resultstring = g_strings[4][3];
                    break;
                }
            case 2:
            case 3:
            case 4:
                if (char2 != 1)
                {
                    resultstring = g_strings[4][4];
                    break;
                }
            default:
                resultstring = g_strings[4][5];
                break;
            }
        }
        break;
    case 2:                                                     // Миллионы                    
        switch (char3)                                          // Тоже самое что и выше
        {
        case 1:
            if (char2 != 1)
            {
                resultstring = g_strings[4][6];
                break;
            }
        case 2:
        case 3:
        case 4:
            if (char2 != 1)
            {
                resultstring = g_strings[4][7];
                break;
            }
        default:
            resultstring = g_strings[4][8];
            break;
        }
        break;
    default:
        break;
    }

    if (char2 > 0)                                              // Проверка десятков
    {
        if (char2 == 1)                                         // Проверка на числа от 11 до 19
        {
            switch (char3)
            {
            case 0:                                             // Если нет единиц
                resultstring = g_strings[2][char2] + resultstring;
                break;
            default:                                            // Если они есть
                resultstring = g_strings[1][char3] + resultstring;
                break;
            }
        }
        else
        {
            switch (char3)                                          // Снова правила русского языка
            {
            case 1:
                if (cycles == 1)
                {
                    resultstring = " одна" + resultstring;
                    break;
                }
            case 2:
                if (cycles == 1)
                {
                    resultstring = " две" + resultstring;
                    break;
                }
            default:
                resultstring = g_strings[0][char3] + resultstring;
                break;
            }

            resultstring = g_strings[2][char2] + resultstring;
        }
    }
    else                                                        // Если десятков нет, записываем только единицы
    {
        switch (char3)                                          // И снова правила русского языка
        {
        case 1:
            if (cycles == 1)
            {
                resultstring = " одна" + resultstring;
                break;
            }
        case 2:
            if (cycles == 1)
            {
                resultstring = " две" + resultstring;
                break;
            }
        default:
            resultstring = g_strings[0][char3] + resultstring;
            break;
        }
    }

    if (char1 > 0)                                               // Проверка на сотни
    {
        resultstring = g_strings[3][char1] + resultstring;
    }

    return resultstring;
}

void numToTextConvert(char numbers[], bool trigger)                             // Основная функция конвертации
{
    char trichar[3] { 0,0,0 };                                                  // Разбивающий массив
    int count{ 0 }, cycles{ 0 };                                                // Счётчики

    std::string resultstring;                                                   // Строка вывода

    for (int i = sizeof(numbers) + 3; i >= 0; i--)                              // Читаем символы введённого массива
    {
        if (isdigit(numbers[i]))                                                // Символ число?
        {
            if (trigger)                                                                                //⠉⠉⠉⣿⡿⠿⠛⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣻⣩⣉⠉⠉
            {                                                                                           //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣀⣀⣀⣀⣀⡀⠄⠄⠉⠉⠄⠄⠄
                switch (numbers[i])                                                                     //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⠄⠄⠄⠄
                {                                                                                       //⠄⠄⠄⠄⠄⠄⠄⠄⠄⢤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠄⠄⠄
                case 1:                                                                                 //⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠄⠉⠉⠉⣋⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⢷⡀⠄⠄
                    resultstring = g_strings[4][0];                                                     //⣿⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⣾⣿⣷⣄⣀⣀⣀⣠⣄⣢⣤⣤⣾⣿⡀⠄
                    break;                                                                              //⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣹⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⢟⢁⣠
                case 2:                                                                                 //⣿⣿⣄⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠉⣉⣉⣰⣿⣿⣿⣿⣷⣥⡀⠉⢁⡥⠈
                case 3:                                                                                 //⣿⣿⣿⢹⣇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠒⠛⠛⠋⠉⠉⠛⢻⣿⣿⣷⢀⡭⣤⠄
                case 4:                                                                                 //⣿⣿⣿⡼⣿⠷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣠⣿⣟⢷⢾⣊⠄⠄
                    resultstring = g_strings[4][1];                                                     //⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⣈⣉⣭⣽⡿⠟⢉⢴⣿⡇⣺⣿⣷
                    break;                                                                              //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠁⠐⢊⣡⣴⣾⣥⣿⣿⣿
                default:                                                                                //      Жёская нарезка кода
                    resultstring = g_strings[4][2];
                    break;
                }

                trigger = false;
            }

            trichar[2 - count] = numbers[i];                                    // Добавляем его в разбивной массив
            count++;

            if (count == 3 || i == 0)                                           // Если массив заполнен или числа закончились
            {
                resultstring = writeToOutput(trichar, cycles) + resultstring;   // Функция анализа текущего разряда

                cycles++;
                count = 0;                                                      // Увеличиваем счётчик, обнуляем массив
                trichar[0] = 0; 
                trichar[1] = 0; 
                trichar[2] = 0;
            }
        }
    }

    std::cout << resultstring;                                                  // Выводим получившиюся строку

    std::fill_n(numbers, 12, NULL);                                             // Обнуляем ввод
}

int main()
{
    setlocale(LC_ALL, "Rus");

    bool trigger;

    std::cout << "Добавлять рубли к конечной строке на этот сеанс? (y/n)\n";

tryagain:

    switch (_getch())
    {
    case 'y':
    case 'Y':
        trigger = true;
        break;
    case 'n':
    case 'N':
        trigger = false;
        break;
    default:
        goto tryagain;
        break;
    }

    while (true)                                                                                                    //———————————Вечный цикл? ———————————
    {                                                                                                               //    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
        char numbers[12];                               // Массив ввода                                             //    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
                                                                                                                    //    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
        std::cout << "Введите конвертируемое число: \n";                                                            //    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁
        std::cin.getline(numbers, 12);                  // Чтение строки из 12 символов (на случай разделителей)    //    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀
        std::cout << "Результат:\n";                                                                                //    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂
                                                                                                                    //    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀
        numToTextConvert(numbers, trigger);             // Вызов функции                                            //    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀
                                                                                                                    //    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        std::cout << "\nДля повторного набора нажмите <r> , для выхода нажмите любую другую клавишу.";              //    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        if (_getch() != 'r')                            // Выход из цикла                                           //    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
            exit(0);                                                                                                //    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀
                                                                                                                    //    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        system("cls");                                  // Чистка экрана                                            //  —————————————————————————————
    }
}