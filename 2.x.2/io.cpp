#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer: ";

    int num;
    std::cin >> num;

    return num;
}

void writeAnswer(int num)
{
    std::cout << "Result = " << num;
}