#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string input{};
    bool found{ false };

    std::cout << "Enter a name: ";
    std::getline(std::cin, input);

    for (auto name : names)
    {
        if (name == input)
            found = true;
    }

    if (found)
    {
        std::cout << input << " was found.";
    }
    else
    {
        std::cout << input << " was not found.";
    }
}