#include <iostream>

int doubleNumber(int num)
{
    return num * 2;
}

int main()
{
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Double " << num << " is " << doubleNumber(num);
}