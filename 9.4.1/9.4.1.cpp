#include <iostream>

struct advertising
{
    int show_count;
    double percent_clicked, avg_gain;
};

int main()
{
    setlocale(LC_ALL, "Rus");

    advertising ad{};

    std::cout << "Сколько объявлений вы показали читателям: ";
    std::cin >> ad.show_count;

    std::cout << "На какой процент объявлений нажимали пользователи: ";
    std::cin >> ad.percent_clicked;

    std::cout << "Сколько вы в среднем зарабатывали на каждом клике по объявлению: ";
    std::cin >> ad.avg_gain;

    std::cout << "Заработанно за день: " << ad.avg_gain * ad.percent_clicked * ad.show_count;
}