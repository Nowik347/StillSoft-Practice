#include <iostream>
#include <ctype.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

void numToTextConvert(char numbers[], bool trigger)
{
    // Разбивающий массив
    char trichar[3] = { 0,0,0 };
    // Счётчики
    int count = 0, cycles = 0;

    // Словари
    string stringnums[] = { " ", " один", " два", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" },
        stringnumsteens[] = { " ", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " пятнадцать", " шестнадцать", " семнадцать", " восемнадцать", " девятнадцать" },
        stringnumsdec[] = { " ", " десять", " двадцать", " тридцать", " сорок", " пятьдесят", " шестьдесят", " семьдесят", " восемьдесят", " девятносто" },
        stringnumshund[] = { " ", " сто", " двести", " триста", " четыресто", " пятьсот", " шестьсот", " семьсот", " восемьсот", " девятьсот" };

    // Строка вывода
    string resultstring;

    // Читаем символы введённого массива
    for (int i = sizeof(numbers) + 3; i >= 0; i--)
    {
        // Символ число?
        if (isdigit(numbers[i]))
        {
            // Добавляем его в разбивной массив
            trichar[2 - count] = numbers[i];
            count++;

            // Если массив заполнен или числа закончились
            if (count == 3 || i == 0)
            {
                // Сколько циклов прошло?
                switch (cycles)
                {
                // Тысячи
                case 1:
                    // Добавляются только если они есть
                    if ((trichar[0] != '0' && trichar[2] != '0') || (trichar[1] != '0') || (trichar[0] != '0') || (trichar[2] != '0'))
                    {
                        // Правила русского языка

                        // Если первое число 1, а второе 0
                        if ((trichar[2] == '1' && trichar[1] == '\0') || (trichar[2] == '1' && trichar[1] != '1'))
                        {
                            resultstring = " тысяча" + resultstring;
                        }
                        // Если первое число от 2 до 4
                        else if (trichar[2] > '1' && trichar[2] < '5' && trichar[1] < '1')
                        {
                            resultstring = " тысячи" + resultstring;
                        }
                        else
                        {
                            resultstring = " тысяч" + resultstring;
                        }
                    }
                    break;
                // Миллионы
                case 2:
                    // Тоже самое что и выше
                    if ((trichar[2] == '1' && trichar[1] == '\0') || (trichar[2] == '1' && trichar[1] != '1'))
                    {
                        resultstring = " миллион" + resultstring;
                    }
                    else if (trichar[2] > '1' && trichar[2] < '5' && trichar[1] < '1')
                    {
                        resultstring = " миллиона" + resultstring;
                    }
                    else
                    {
                        resultstring = " миллионов" + resultstring;
                    }
                    break;
                default:
                    break;
                }

                // Временные переменные (символы хранятся как числа ASCII таблицы так что можно просто вычесть символ нуля(0) и получить нужный int)
                int char1 = trichar[0] - '0', char2 = trichar[1] - '0', char3 = trichar[2] - '0';

                /*———————————No switches? ———————————
                    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
                    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
                    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
                    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
                    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
                    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                —————————————————————————————*/

                // Проверка десятков
                if (char2 != 0 && char2 > 0)
                {
                    // Проверка на числа от 11 до 19
                    if (char2 == 1 && char3 > 0)
                    {
                        resultstring = stringnumsteens[char3] + resultstring;
                    }
                    else
                    {
                        // Снова правила русского языка
                        if (trichar[2] == '1' && cycles == 1)
                        {
                            resultstring = " одна" + resultstring;
                        }
                        else if (trichar[2] == '2' && cycles == 1)
                        {
                            resultstring = " две" + resultstring;
                        }
                        else
                        {
                            resultstring = stringnums[char3] + resultstring;
                        }

                        resultstring = stringnumsdec[char2] + resultstring;
                    }
                }
                // Если десятков нет, записываем только единицы
                else
                {
                    // Снова правила русского языка
                    if (trichar[2] == '1' && cycles == 1)
                    {
                        resultstring = " одна" + resultstring;
                    }
                    else if (trichar[2] == '2' && cycles == 1)
                    {
                        resultstring = " две" + resultstring;
                    }
                    else
                    {
                        resultstring = stringnums[char3] + resultstring;
                    }
                }

                // Проверка на сотни
                if (char1 != 0 && char1 > 0)
                {
                    resultstring = stringnumshund[char1] + resultstring;
                }

                // Увеличиваем счётчик, обнуляем массив
                cycles++;
                count = 0;
                trichar[0] = 0; trichar[1] = 0; trichar[2] = 0;
            }
        }
    }

    // Выводим получившиюся строку
    if (trigger)
    {
        cout << resultstring << " рублей";
    }
    else
    {
        cout << resultstring;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    bool trigger;

    cout << "Добавлять рубли к конечной строке на этот сеанс? (y/n)\n";

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
    //———————————Вечный цикл? ———————————
    //    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
    //    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
    //    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
    //    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
    //    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    //    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    //    —————————————————————————————
    while (true)
    {
        // Массив ввода
        char numbers[12];

        cout << "Введите конвертируемое число: \n";

        // Чтение строки из 12 символов (на случай разделителей)
        cin.getline(numbers, 12);

        cout << "Результат:\n";

        // Вызов функции
        numToTextConvert(numbers, trigger);

        cout << "\nДля повторного набора нажмите <r> , для выхода нажмите любую другую клавишу.";

        // Выход из цикла
        if (_getch() != 'r')
        {
            exit(0);
        }

        // Чистка экрана
        system("cls");
    }
}