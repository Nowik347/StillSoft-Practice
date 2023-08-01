#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
    int length{};

    std::cout << "How many names would you like to enter? ";
    std::cin >> length;

    std::string* names{ new std::string[length] };

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i{ 0 }; i < length; i++)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin, names[i]);
    }

    std::sort(names, names + length);

    std::cout << "Here is your sorted list:\n";

    for (int i{ 0 }; i < length; i++)
    {
        std::cout << "\nName #" << i + 1 << ": " << names[i];
    }
}