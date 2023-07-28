#include <iostream>

struct fraction
{
    int upper, lower;
};

fraction multiply(fraction x, fraction y)
{
    fraction result{};
    result.upper = x.upper * y.upper;
    result.lower = x.lower * y.lower;

    return result;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    fraction first, second, result;

    std::cout << "Введите числитель первой дроби: ";
    std::cin >> first.upper;

    std::cout << "Введите знаменатель первой дроби: ";
    std::cin >> first.lower;

    std::cout << "Введите числитель второй дроби: ";
    std::cin >> second.upper;

    std::cout << "Введите знаменатель второй дроби: ";
    std::cin >> second.lower;

    result = multiply(first, second);

    std::cout << "Результирующая дробь: " << result.upper << '\n'
        << "                      " << "--" << '\n'
        << "                      " << result.lower;
}