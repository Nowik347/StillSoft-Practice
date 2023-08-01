#include <iostream>

void printString(const char* str)
{
    while (*str != '\0')
    {
        std::cout << *str;
        str++;
    }
}

int main()
{
    const char* str{ "Hello, world!" };

    printString(str);
}