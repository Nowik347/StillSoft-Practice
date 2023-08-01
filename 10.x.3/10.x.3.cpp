#include <iostream>

void swap(int& x, int& y)
{
    x = (y = y + (x = x - y)) - x;
}

int main()
{
    int x{ 0 }, y{ 0 };

    std::cin >> x; std::cin >> y;

    swap(x, y);

    std::cout << x << "\n" << y;
}