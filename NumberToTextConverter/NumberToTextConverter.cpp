#include <iostream>
#include <conio.h>
#include <chrono>

#define getInt(arr, index) arr[index] - '0'                          // Находим целочисленное значение символа из массива символов
#define getFullInt(arr) arr[0] - '0' + arr[1] - '0' + arr[2] - '0'   // Находим целочисленное значение всего массива символов

const char *g_mainstrings[4][10]                                     // Глобальные словари
{                                                                    // Основной словарь
    { "", " один", " два", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" },
    { "", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " пятнадцать", " шестнадцать", " семнадцать", " восемнадцать", " девятнадцать" },
    { "", " десять", " двадцать", " тридцать", " сорок", " пятьдесят", " шестьдесят", " семьдесят", " восемьдесят", " девяносто" },
    { "", " сто", " двести", " триста", " четыреста", " пятьсот", " шестьсот", " семьсот", " восемьсот", " девятьсот" } 
},
   *g_utilitystrings[3][3]                                           // Вспомогательный словарь
{ 
    {" рубль", " рубля", " рублей"}, 
    {" тысяча", " тысячи", " тысяч"}, 
    {" миллион", " миллиона", " миллионов"} 
};
//_______________________________________________________________________________________________________________________________________________________________________
std::string thousandsExceptionCheck(short right_char, short& rank_count)  // Функция проверки частного случая тысячи
{
    switch (right_char)                                              // Проверка первого числа массива
    {
    case 1:
        if (rank_count == 1)
        {
            return " одна";
        }
    case 2:
        if (rank_count == 1)
        {
            return " две";
        }
    default:
        return g_mainstrings[0][right_char];
    }
}
//_______________________________________________________________________________________________________________________________________________________________________
std::string getRank(short right_char, short middle_char, short& rank_count) // Функция нахождения классов чисел
{
    switch (right_char)                                              // Проверка первого числа массива  // Упс...
    {                                                                                                   // Дальше всё switch...
    case 1:                                                                                             //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠴⠒⠒⠲⠤⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        if (middle_char != 1)                                                                           //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠀⠀⠀⠀⠠⢚⣂⡀⠈⠲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀
        {                                                                                               //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡎⡴⠆⠀⠀⠀⠀⠀⢎⠐⢟⡇⠀⠈⢣⣠⠞⠉⠉⠑⢄⠀⠀⣰⠋⡯⠗⣚⣉⣓⡄
            return g_utilitystrings[rank_count][0];                                                     //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢠⢞⠉⡆⠀⠀⠀⠀⠀⠓⠋⠀⠀⠀⠀⢿⠀⠀⠀⠀⠈⢧⠀⢹⣠⠕⠘⢧⠀⠀⠀
        }                                                                                               //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠘⠮⠔⠁⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠸⡀⠀⠀⠀⠀⠈⣇⠀⢳⠀⠀⠘⡆⠀⠀
    case 2:                                                                                             //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠉⠓⠦⣧⠀⠀⠀⠀⢦⠤⠤⠖⠋⠇⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠸⡄⠈⡇⠀⠀⢹⡀⠀
    case 3:                                                                                             //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠙⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠈⣆⠀⠀⠀⢱⠀⡇⠀⠀⠀⡇⠀
    case 4:                                                                                             //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠁⠀⠀⠸⡄⠀⠀⠀⠳⠃⠀⠀⠀⡇⠀
        if (middle_char != 1)                                                                           //⠀⠀⠀⠀⠀⢠⢏⠉⢳⡀⠀⠀⢹⠀⠀⠀⠀⢠⠀⠀⠀⠑⠤⣄⣀⡀⠀⠀⠀⠀⠀⣀⡤⠚⠀⠀⠀⠀⠀⢸⢢⡀⠀⠀⠀⠀⠀⢰⠁⠀
        {                                                                                               //⠀⠀⣀⣤⡞⠓⠉⠁⠀⢳⠀⠀⢸⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⢸⠀⠙⠦⣤⣀⣀⡤⠃⠀⠀
            return g_utilitystrings[rank_count][1];                                                     //⠀⣰⠗⠒⣚⠀⢀⡤⠚⠉⢳⠀⠈⡇⠀⠀⠀⢸⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        }                                                                                               //⠸⠵⡾⠋⠉⠉⡏⠀⠀⠀⠈⠣⣀⣳⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    default:                                                                                            //⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        return g_utilitystrings[rank_count][2];                                                         //⠀⠀⠀⠀⠀⠀⠀⠳⡄⠀⠀⠀⠀⠀⠀⠀⡰⠁⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    }                                                                                                   //⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠲⠤⠤⠤⠴⠚⠁⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
}                                                                                                       //⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//_______________________________________________________________________________________________________________________________________________________________________
void writeToOutput(char this_rank_chars[], short& rank_count, std::string& result_string)       // Основная функция конвертации
{
    switch (rank_count)                                                                         // Сколько циклов прошло?
    {
    case 1:                                                                                     // Тысячи
        if (getFullInt(this_rank_chars) != 0)                                                   // Добавляются только если они есть
        {
            result_string = getRank(getInt(this_rank_chars, 2), getInt(this_rank_chars, 1), rank_count) + result_string;
        }
        break;
    case 2:                                                                                     // Миллионы                         //⠟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠛⢻⣿
        result_string = getRank(getInt(this_rank_chars, 2), getInt(this_rank_chars, 1), rank_count) + result_string;                //⡆⠊⠈⣿⢿⡟⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣎⠈⠻
        break;                                                                                                                      //⣷⣠⠁⢀⠰⠀⣰⣿⣿⣿⣿⣿⣿⠟⠋⠛⠛⠿⠿⢿⣿⣿⣿⣧⠀⢹⣿⡑⠐⢰
    default:                                                                                                                        //⣿⣿⠀⠁⠀⠀⣿⣿⣿⣿⠟⡩⠐⠀⠀⠀⠀⢐⠠⠈⠊⣿⣿⣿⡇⠘⠁⢀⠆⢀
        break;                                                                                                                      //⣿⣿⣆⠀⠀⢤⣿⣿⡿⠃⠈⠀⣠⣶⣿⣿⣷⣦⡀⠀⠀⠈⢿⣿⣇⡆⠀⠀⣠⣾
    }                                                                                                                               //⣿⣿⣿⣧⣦⣿⣿⣿⡏⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠐⣿⣿⣷⣦⣷⣿⣿
                                                                                                                                    //⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⣿⣿⣿⣿⣿⣿⣿
    if (getInt(this_rank_chars, 1) > 0)                                                         // Проверка десятков                //⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⣾⣿⣿⠋⠁⠀⠉⠻⣿⣿⣧⠀⠠⣿⣿⣿⣿⣿⣿⣿
    {                                                                                                                               //⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣿⡿⠁⠀⠀⠀⠀⠀⠘⢿⣿⠀⣺⣿⣿⣿⣿⣿⣿⣿
        if (getInt(this_rank_chars, 1) == 1)                                                    // Проверка на числа от 11 до 19    //⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣠⣂⠀⠀⠀⠀⠀⠀⠀⢀⣁⢠⣿⣿⣿⣿⣿⣿⣿⣿
        {                                                                                                                           //⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣄⣤⣤⣔⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
            switch (getInt(this_rank_chars, 2))                                                                                     //     Нееет, только не if
            {
            case 0:                                                                             // Если нет единиц
                result_string = g_mainstrings[2][getInt(this_rank_chars, 1)] + result_string;
                break;
            default:                                                                            // Если они есть
                result_string = g_mainstrings[1][getInt(this_rank_chars, 2)] + result_string;
                break;
            }
        }
        else
        {
            result_string = thousandsExceptionCheck(getInt(this_rank_chars, 2), rank_count) + result_string;

            result_string = g_mainstrings[2][getInt(this_rank_chars, 1)] + result_string;
        }
    }
    else                                                                                        // Если десятков нет, записываем только единицы
    {
        result_string = thousandsExceptionCheck(getInt(this_rank_chars, 2), rank_count) + result_string;
    }

    if (getInt(this_rank_chars, 0) > 0)                                                        // Проверка на сотни
    {
        result_string = g_mainstrings[3][getInt(this_rank_chars, 0)] + result_string;
    }
}
//_______________________________________________________________________________________________________________________________________________________________________
void numToTextConvert(char input_numbers[], bool add_rubles)                    // Функция разбивки
{
    auto start = std::chrono::high_resolution_clock::now();
    char current_rank_chars[3]{ 0,0,0 };
    short rank_digits_count{ 0 }, rank_count{ 0 };                              // Счётчики и разбивающий массив

    std::string result_string;                                                  // Строка вывода

    for (short i = sizeof(input_numbers) + 3; i >= 0; i--)                      // Читаем символы введённого массива
    {
        if (isdigit(input_numbers[i]))                                          // Символ число?
        {
            if (add_rubles)                                                     // Добавляем рубли              //⠉⠉⠉⣿⡿⠿⠛⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣻⣩⣉⠉⠉
            {                                                                                                   //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣀⣀⣀⣀⣀⡀⠄⠄⠉⠉⠄⠄⠄
                if (input_numbers[i - 1] == '1')                                                                //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⠄⠄⠄⠄
                    result_string = g_utilitystrings[0][2];                                                     //⠄⠄⠄⠄⠄⠄⠄⠄⠄⢤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠄⠄⠄
                else                                                                                            //⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠄⠉⠉⠉⣋⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⢷⡀⠄⠄
                    switch (input_numbers[i])                                                                   //⣿⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⣾⣿⣷⣄⣀⣀⣀⣠⣄⣢⣤⣤⣾⣿⡀⠄
                    {                                                                                           //⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣹⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⢟⢁⣠
                    case '1':                                                                                   //⣿⣿⣄⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠉⣉⣉⣰⣿⣿⣿⣿⣷⣥⡀⠉⢁⡥⠈
                        result_string = g_utilitystrings[0][0];                                                 //⣿⣿⣿⢹⣇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠒⠛⠛⠋⠉⠉⠛⢻⣿⣿⣷⢀⡭⣤⠄
                        break;                                                                                  //⣿⣿⣿⡼⣿⠷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣠⣿⣟⢷⢾⣊⠄⠄
                    case '2':                                                                                   //⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⣈⣉⣭⣽⡿⠟⢉⢴⣿⡇⣺⣿⣷
                    case '3':                                                                                   //⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠁⠐⢊⣡⣴⣾⣥⣿⣿⣿
                    case '4':                                                                                   //      Жёская нарезка кода
                        result_string = g_utilitystrings[0][1];
                        break;
                    default:
                        result_string = g_utilitystrings[0][2];
                        break;
                    }
                
                add_rubles = false;
            }

            current_rank_chars[2 - rank_digits_count] = input_numbers[i];       // Добавляем его в разбивной массив
            rank_digits_count++;

            if (rank_digits_count == 3 || i == 0)                               // Если массив заполнен или числа закончились
            {
                writeToOutput(current_rank_chars, rank_count, result_string);   // Проверка текущего разряда

                rank_count++;
                rank_digits_count = 0;                                          // Увеличиваем счётчик, обнуляем массив
                std::fill_n(current_rank_chars, 3, NULL);
            }
        }
    }

    //return result_string;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << result_string << ' ' << duration.count();                      // Выводим получившиюся строку

    std::fill_n(input_numbers, 12, NULL);                                       // Обнуляем ввод
}
//_______________________________________________________________________________________________________________________________________________________________________
int main()
{
    setlocale(LC_ALL, "Rus");

    bool add_rubles;                                          // Переменная валюты

tryagain:
    std::cout << "Добавлять рубли к конечной строке на этот сеанс? (y/n)\n";

    switch (_getch())                                         // Проверка выбора
    {
    case 'y':
    case 'Y':
        add_rubles = true;
        break;
    case 'n':
    case 'N':
        add_rubles = false;
        break;
    default:
        system("cls");
        goto tryagain;
    }

    while (true)                                                                                                        //———————————Вечный цикл? ———————————
    {                                                                                                                   //    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
        char input_numbers[12];                               // Массив ввода                                           //    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
                                                                                                                        //    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
        std::cout << "Введите конвертируемое число: \n";                                                                //    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁
        std::cin.getline(input_numbers, 12);                  // Чтение строки из 12 символов (на случай разделителей)  //    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀
        std::cout << "Результат:\n";                                                                                    //    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂
                                                                                                                        //    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀
        numToTextConvert(input_numbers, add_rubles);          // Вызов функции                                          //    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀
                                                                                                                        //    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        std::cout << "\nДля повторного набора нажмите <r> , для выхода нажмите любую другую клавишу.";                  //    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        if (_getch() != 'r')                                  // Выход из цикла                                         //    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
            exit(0);                                                                                                    //    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀
                                                                                                                        //    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        system("cls");                                        // Чистка экрана                                          //  —————————————————————————————
    }
}