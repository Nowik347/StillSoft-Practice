#ifndef MY_UTILITY
#define MY_UTILITY

//_______________________________________________________________________________________________________________________________________________________________________
std::string reference[5][10]                                         // Глобальные словари
{                                                                    // Основной словарь
    { "", " сто", " двести", " триста", " четыреста", " пятьсот", " шестьсот", " семьсот", " восемьсот", " девятьсот" },
    { "", " один", " два", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" },
    { "", " десять", " двадцать", " тридцать", " сорок", " пятьдесят", " шестьдесят", " семьдесят", " восемьдесят", " девяносто" },
    { " десять", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " пятнадцать", " шестнадцать", " семнадцать", " восемнадцать", " девятнадцать" },
    { "", " одна", " две", " три", " четыре", " пять", " шесть", " семь", " восемь", " девять" }
}, util[2][10]                                                       // Вспомогательный словарь
{
    {" тысяч", " тысяча", " тысячи", " тысячи", " тысячи", " тысяч", " тысяч", " тысяч", " тысяч", " тысяч"},
    {" миллионов", " миллион", " миллиона", " миллиона", " миллиона", " миллионов", " миллионов", " миллионов", " миллионов", " миллионов"}
};
//_______________________________________________________________________________________________________________________________________________________________________
class numConverter                                                        // Класс переводчика
{
private:

    short pointer{ 0 }, curr_class{ 0 }, class_sum{ 0 };                  // Счётчики
    std::string numbers[3][10];                                           // Словарь чисел
    std::string class_names[10];                                          // Словарь текущего разряда
    std::stack<int> input_nums{};                                         // Стек ввода

    void loadTeens()                                                      // Функция подстановки чисел от 10 до 19
    {
        std::copy(reference[3], reference[3] + 10, numbers[2]);                 // Копируем эталон

        std::fill_n(class_names, 10, util[curr_class / 2][0]);

        pointer++;
        input_nums.pop();                                                       // Пропускаем десятки
    }

    void loadTens()                                                       // Функция подстановки чисел от 10 до 90    
    {
        std::copy(reference[2], reference[2] + 10, numbers[2]);                 // Копируем эталон

        checkClass();
    }

    void clearClass()
    {
        std::fill_n(class_names, 10, "");
    }

    void loadClass(int needed_class)
    {
        std::copy(util[needed_class], util[needed_class] + 10, class_names);
        
        if(!needed_class)
            std::copy(reference[4], reference[4] + 10, numbers[2]);
    }

    void checkClass()
    {
        if (curr_class == 0)
            clearClass();
        else
            loadClass(curr_class / 2);
    }

    std::string getClass()                                             // Функция выдачи наименования класса
    {
        return pointer == 2 ? class_names[input_nums.top()] : "";               // Возвращаем наименования класса
    }

    std::string getNumStr()
    {
        return numbers[pointer][input_nums.top()];
    }

    void exceptionsCheck()
    {
        if (pointer == 1)                                                       // Проверяем десятки
        {
            input_nums.top() == 1 ? loadTeens() : loadTens();
        }
        else
        {
            curr_class = input_nums.size() / 3;
            checkClass();
        }
    }

    void shiftPointer()                                                   // Функция увеличения счётчика
    {
        input_nums.pop();                                                       // Переход к следующему числу

        pointer == input_nums.size() % 3;                                 // Сдвиг счётчика

        if (!input_nums.empty())
        {
            pointer == 2 ? class_sum = 0 : class_sum += input_nums.top();           // На случай пустых классов
            exceptionsCheck();
        }
    }

public:

    numConverter(std::stack<int>& input)                                  // Конструктор
    {
        input_nums = input;                                                     // Копируем стек

        for (short i{ 0 }; i < 3; i++)                                          // Загружаем эталоны в словарь чисел
            std::copy(reference[i], reference[i] + 10, numbers[i]);

        if (input_nums.size() % 3 != 0)                                         // Смотрим начальный разряд
            input_nums.size() % 3 == 1 ? pointer = 2 : pointer = 1;

        curr_class = input_nums.size() / 3;
        exceptionsCheck();
    }

    std::string outputString()                                            // Функция выдачи строки текущего числа
    {
        std::string result{ getNumStr() + getClass() };

        shiftPointer();

        return result;
    }

    bool finished()
    {
        return false;
    }
};
//_______________________________________________________________________________________________________________________________________________________________________
std::stack<int> convertIntToStack(int input)
{
    assert(input > 0);

    std::stack<int> temp;

    while (input > 0)
    {
        temp.push(input % 10);
        input /= 10;
    }

    return temp;
}
#endif