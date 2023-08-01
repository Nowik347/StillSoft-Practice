#include <iostream>

namespace animals
{
    enum { chicken, dog, cat, elephant, duck, snake };
}

int leg_count[6]{ 2, 4, 4, 4, 2, 0 };

int main()
{
    std::cout << leg_count[animals::elephant];
}