#include <iostream>
#include <array>

enum items { health_potion, torch, arrrow };

std::array<int, 3> inventory{ 2, 5, 10 };

int countTotalItems(const std::array<int, 3>& inventory)
{
    return inventory[health_potion] + inventory[torch] + inventory[arrrow];
}

int main()
{
    std::cout << "Total items: " << countTotalItems(inventory)
        << "\nTorches: " << inventory[torch];
}