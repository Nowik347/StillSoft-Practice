#include <iostream>

int readNumber();

void writeAnswer(int num);

int main()
{
    int first_int{ readNumber() }, second_int{ readNumber() };

    writeAnswer(first_int + second_int);
}