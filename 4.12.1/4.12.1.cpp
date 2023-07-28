#include <string>
#include <iostream>

int main()
{
    std::string name;
    int age;

    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    double age_per_letter = age / name.length();

    std::cout << "You've lived " << age_per_letter << " years for each letter in your name.";
}