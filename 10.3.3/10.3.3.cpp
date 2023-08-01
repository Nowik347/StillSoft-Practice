#include <iostream>
#include <iterator> // для std::size

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };

    int maxScore{ 0 }, maxIndex{ 0 }; // Для начала предположим, что наш наибольший результат равен 0

    // теперь ищем максимальный результат во всем массиве
    for (int student{ 0 }; student < std::size(scores); ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << maxScore << " at index " << maxIndex << '\n';

    return 0;
}