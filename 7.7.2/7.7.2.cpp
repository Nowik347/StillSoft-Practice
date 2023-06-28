#include <iostream>

int main()
{
    for (int i{ 0 }; i < 26; i++)
    {
        std::cout << char(97 + i) << " - " << 97 + i << "\n";
    }
}