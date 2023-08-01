#include <iostream>
#include <algorithm>
#include <vector>

struct student
{
    std::string name;
    int mark {};
};

bool compareStudents(const student& a, const student& b)
{
    return (a.mark > b.mark);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int length;
    std::vector<student> students;

    std::cout << "Сколько студентов ввести: ";
    std::cin >> length;

    students.resize(length);

    for (int i{ 0 }; i < length; i++)
    {
        std::cout << "Имя студента: ";
        std::cin >> students[i].name;

        std::cout << "Оценка студента: ";
        std::cin >> students[i].mark;
    }

    std::sort(students.begin(), students.end(), compareStudents);

    for (int i{ 0 }; i < length; i++)
    {
        std::cout << "\nИмя студента: " << students[i].name;

        std::cout << "\nОценка студента: " << students[i].mark;
    }
}