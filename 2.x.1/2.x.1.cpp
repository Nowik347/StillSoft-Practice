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

int main()
{
    int first_int{ readNumber() }, second_int{ readNumber() };

    writeAnswer(first_int + second_int);
}