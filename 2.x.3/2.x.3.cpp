#include <iostream>
#include "io.h"

int main()
{
    int first_int{ readNumber() }, second_int{ readNumber() };

    writeAnswer(first_int + second_int);
}