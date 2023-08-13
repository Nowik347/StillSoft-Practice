//#include <iostream>
//#include <conio.h>
//#include <chrono>
//
//const char* g_mainstrings[4][10]                                     // Глобальные словари
//{                                                                    // Основной словарь
//    { "", " один", " два", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" },
//    { "", " десять", " двадцать", " тридцать", " сорок", " пятьдесят", " шестьдесят", " семьдесят", " восемьдесят", " девяносто" },
//    { "", " сто", " двести", " триста", " четыреста", " пятьсот", " шестьсот", " семьсот", " восемьсот", " девятьсот" },    
//    { " десять", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " пятнадцать", " шестнадцать", " семнадцать", " восемнадцать", " девятнадцать" }
//},
//* g_utilitystrings[3][3]                                             // Вспомогательный словарь
//{
//    {" рубль", " рубля", " рублей"},
//    {" тысяча", " тысячи", " тысяч"},
//    {" миллион", " миллиона", " миллионов"}
//};
//
//const int g_input_length{ 10 };
//
//void allExceptionsCheck(int* input_numbers, short &index, std::string &result_string) // Проверяем все возможные исключения
//{                                                                               // Проверяем на тысячи/миллионы
//    if (input_numbers[index] + input_numbers[index + 1] + input_numbers[index + 2] != 0 && index / 3 != 0)  // Если на ранге что-то есть и он не первый
//    {
//        if (input_numbers[index] == 0 || input_numbers[index + 1] == 1)         // На случай нулевого первого числа или 11
//            result_string = g_utilitystrings[index / 3][2] + result_string;
//        else
//            result_string = g_utilitystrings[index / 3][((input_numbers[index] + 1) / 3) - ((input_numbers[index] + 1) / 3 / 3)] + result_string; // Мне проще рассказать вам
//    }                                                                                                                                             // про это уравнение чем тут
//                                                                                                                                                  // расписывать
//    if (input_numbers[index + 1] == 1)                                          // Проверяем 11
//    {
//        result_string = g_mainstrings[3][input_numbers[index]] + result_string;
//        index++;
//    }
//    else                                                                        // Остальные числа
//        switch (input_numbers[index])                                           // Правила русского языка
//        {
//        case 1:
//            if (index / 3 == 1)                                                 // Только для тысяч
//            {
//                result_string = " одна" + result_string;
//                break;
//            }
//        case 2:
//            if (index / 3 == 1)
//            {
//                result_string = " две" + result_string;
//                break;
//            }
//        default:
//            result_string = g_mainstrings[index % 3][input_numbers[index]] + result_string;
//            break;
//        }
//}
////_______________________________________________________________________________________________________________________________________________________________________
//void reverseArray(int* array, int length)                                       // Функция переворачивания массива
//{
//    for (int i{ 0 }, j{ length - 1 }; i < j; i++, j--)
//        std::swap(array[i], array[j]);
//}
////_______________________________________________________________________________________________________________________________________________________________________
//int* convertCharArrToIntArr(char input[], int& length)                          // Превращение массива символов в указатель на целочисленный массив
//{
//    bool exit{ false };
//    length = 0;
//
//    while (!exit)                                                               // Проверяем на наличие только чисел
//    {
//        switch (isdigit(input[length]))
//        {
//        case 0:
//            if (input[length] == '\0')
//            {
//                exit = true;
//                break;
//            }
//            else
//            {
//                std::cout << "Некоректный ввод.";
//                return NULL;
//            }
//        default:
//            length++;
//            break;
//        }
//    }
//
//    int* result_array{ new int[length] };                                       // Создаем указатель
//
//    for (int i{ 0 }; i <= length; i++)                                          // Копируем массив
//        result_array[i] = input[i] - '0';
//
//    return result_array;                                                        // Возвращаем указатель
//}
////_______________________________________________________________________________________________________________________________________________________________________
//std::string numToTextConvert(int* input_numbers, bool add_rubles, int length)   // Функция разбивки
//{
//    /*auto start = std::chrono::high_resolution_clock::now();*/
//    std::string result_string;                                                  // Строка вывода
//
//    reverseArray(input_numbers, length);
//
//    if (add_rubles)                                                             // Добавляем рубли
//    {
//        if (input_numbers[1] == 1 || input_numbers[0] == 0)
//            result_string = g_utilitystrings[0][2];
//        else
//            result_string = g_utilitystrings[0][((input_numbers[0] + 1) / 3) - ((input_numbers[0] + 1) / 3 / 3)];
//
//        add_rubles = false;
//    }
//
//    for (short i{ 0 }; i < length; i++)                                         // Проверяем массив по очереди
//    {
//        if (i % 3 == 0)                                                         // Каждые 3 числа, кроме первых 3
//            allExceptionsCheck(input_numbers, i, result_string);                // Проверяем на случай каких либо исключений
//        else                                                                    // Все остальные числа
//            result_string = g_mainstrings[i % 3][input_numbers[i]] + result_string;
//    }
//
//    /*auto stop = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);*/
//
//    std::cout << result_string; /*<< ' ' << duration.count();*/                 // Выводим получившиюся строку
//
//    std::fill_n(input_numbers, length, NULL);                                   // Обнуляем ввод
//
//    return result_string;
//}
////_______________________________________________________________________________________________________________________________________________________________________
//int main()
//{
//    setlocale(LC_ALL, "Rus");
//
//    bool add_rubles;                                          // Переменная валюты
//
//tryagain:
//    std::cout << "Добавлять рубли к конечной строке на этот сеанс? (y/n)\n";
//
//    switch (_getch())                                         // Проверка выбора
//    {
//    case 'y': case 'Y':
//        add_rubles = true;
//        break;
//    case 'n': case 'N':
//        add_rubles = false;
//        break;
//    default:
//        system("cls");
//        goto tryagain;
//    }
//
//    while (true)                                                                                                        //———————————Вечный цикл? ———————————
//    {                                                                                                                   //    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
//        char starting_input[g_input_length];                  // Массив ввода                                           //    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
//                                                                                                                        //    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
//        std::cout << "Введите конвертируемое число: \n";                                                                //    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁
//        std::cin.getline(starting_input, g_input_length);     // Чтение строки                                          //    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀
//        std::cout << "Результат:\n";                                                                                    //    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂
//                                               
//        int length{ 0 }, *input_numbers{ convertCharArrToIntArr(starting_input, length) };
//        
//        if (input_numbers)
//            numToTextConvert(input_numbers, add_rubles, length);  // Вызов функции                                      //    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀
//                                                                                                                        //    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂//    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//        std::cout << "\nДля повторного набора нажмите <r> , для выхода нажмите любую другую клавишу.";                  //    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//        if (_getch() != 'r')                                  // Выход из цикла                                         //    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//            exit(0);                                                                                                    //    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀
//                                                                                                                        //    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//        system("cls");                                        // Чистка экрана                                          //  —————————————————————————————
//    }
//}