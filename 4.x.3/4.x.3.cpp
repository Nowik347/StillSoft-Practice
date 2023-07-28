#include <iostream>

double getValue()
{
    double temp;

    std::cout << "Enter a double value: ";
    std::cin >> temp;

    return temp;
}

int main()
{
    double first_num{ getValue() }, second_num{ getValue() };
    char action;

    std::cout << "Enter one of the following: +, -, *, or /: ";
    std::cin >> action;

    switch (action)
    {
    case '+':
        std::cout << first_num << " + " << second_num << " is " << first_num + second_num;
        break;
    case '-':
        std::cout << first_num << " - " << second_num << " is " << first_num - second_num;
        break;
    case '*':
        std::cout << first_num << " * " << second_num << " is " << first_num * second_num;
        break;
    case '/':
        std::cout << first_num << " / " << second_num << " is " << first_num / second_num;
        break;
    default:
        break;
    }
}