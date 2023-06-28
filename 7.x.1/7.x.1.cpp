#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    // Проверяем, не ушли ли мы под землю
    // Если это так, устанавливаем высоту на уровне земли
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight)
{
    int time{0};
    double heightNow = initialHeight;

    do
    {
        time++;
        std::cout << "At " << time << " seconds, the ball is at height: " << heightNow << "\n";
        heightNow = calculateHeight(initialHeight, time);
    } while (heightNow != 0.0);

    std::cout << "At " << time + 1 << " seconds, the ball is at height: " << heightNow << "\n";
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    return 0;
}