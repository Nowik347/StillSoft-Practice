#include <iostream>

enum MonsterType { Slime, Ogre };

struct Monster
{
    MonsterType type;
    std::string name;
    double life;
};

void printMonster(Monster monster)
{
    std::cout << "\nThis ";

    switch (monster.type)
    {
    case Slime:
        std::cout << "Slime";
        break;
    case Ogre:
        std::cout << "Ogre";
        break;
    }

    std::cout << " is named " << monster.name
        << " and has " << monster.life << " health.";
}

int main()
{
    Monster ogre{ Ogre,"Torg",145 }, slime{ Slime,"Blurp",23 };
    printMonster(ogre);
    printMonster(slime);
}