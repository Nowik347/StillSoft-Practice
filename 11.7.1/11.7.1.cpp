#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

ArithmeticFunction getArithmeticFunction(char choice)
{
    switch (choice)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &division;
    default:
        return &division;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int input_a, input_b;
    char choice;

tryAgain:

    system("cls");

    std::cout << "Введите первое число: ";
    std::cin >> input_a;

    std::cout << "Введите второе число: ";
    std::cin >> input_b;

    std::cout << "Выберите операцию '+', '-', '*', '/'): ";
    std::cin >> choice;

    if (choice < 43 || choice > 47)
        goto tryAgain;

    ArithmeticFunction func_ptr{ getArithmeticFunction(choice) };

    std::cout << input_a << ' ' << choice << ' ' << input_b << " = " << func_ptr(input_a, input_b) << '\n';
}