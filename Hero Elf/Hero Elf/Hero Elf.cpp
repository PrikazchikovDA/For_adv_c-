#include <iostream>
#include "hero_elf.h"

int main()
{
    // #1 Мини-игра

    std::string name;
    std::cout << "Hello, traveller!\n Type your name: ";
    std::cin >> name;
    std::cout << "Choose your hero : \n";
    std::cout << "   Heroes | Hikka | Witch | Ninja | Titan \n";
    std::cout << "   Health |  50   |  50   |  50   | 1000 \n";
    std::cout << " Strength |   5   |   5   |  50   |  100 \n";
    std::cout << " Magicity |   5   |  50   |   5   |   0 \n";
    std::cout << "Intellect |  50   |   5   |   5   |   0 \n";
    std::cout << "   Number |   1   |   2   |   3   |   4 \n";

    int number_of_hero;
    std::cout << "Choose number of your hero: ";
    std::cin >> number_of_hero;

    while (number_of_hero < 1 or number_of_hero > 4) {
        std::cout << "Please, type correct number!\nBTW, it's in the last row of the table...\n";
        std::cout << "Choose number of your hero: ";
        std::cin >> number_of_hero;
    }

    hero_elf hero;
    if (number_of_hero == 1) {
        hero.set_param(name, 50, 5, 5, 50);
    } else if (number_of_hero == 2) {
        hero.set_param(name, 50, 5, 50, 5);
    } else if (number_of_hero == 3) {
        hero.set_param(name, 50, 50, 5, 5);
    } else {
        hero.set_param(name, 1000, 100, 1, 1);
    }

    int number_of_opponent;
    std::cout << "Now choose your opponent (numbers are the same): ";
    std::cin >> number_of_opponent;

    while (number_of_hero < 1 or number_of_hero > 4) {
        std::cout << "Please, type correct number!\nBTW, it's in the last row of the table...\n";
        std::cout << "Choose number of your opponent: ";
        std::cin >> number_of_opponent;
    }

    hero_elf opponent;
    if (number_of_opponent == 1) {
        opponent.set_param("Hikka", 50, 5, 5, 50);
    }
    else if (number_of_opponent == 2) {
        opponent.set_param("Witch", 50, 5, 50, 5);
    }
    else if (number_of_opponent == 3) {
        opponent.set_param("Ninja", 50, 50, 5, 5);
    }
    else {
        opponent.set_param("Titan", 1000, 100, 1, 1);
    }

    hero.get_info(&opponent);

    while (hero.get_health() > 0 and opponent.get_health() > 0)
    {
        int choise;
        std::cout << "Do you want to:\n";
        std::cout << "    fight an opponent  - 1\n";
        std::cout << "      cure yourself    - 2\n";
        std::cout << " improve your strength - 3\n";
        std::cout << " learn some new spells - 4\n";
        std::cout << "Your choise: ";
        std::cin >> choise;
        while (choise < 1 or choise > 4) {
            std::cout << "The number is between 1 and 4...\n";
            std::cout << "Your choise: ";
            std::cin >> choise;
        }

        if (choise == 1) {
            opponent.strike(&hero);
        }
        else if (choise == 2) {
            hero.cure();
        }
        else if (choise == 3) {
            hero.train();
        }
        else {
            hero.learn();
        }

        int choise_of_opponent = std::rand() % 4 + 1;
        if (choise == 1) {
            std::cout << "Your opponent choosed to combat\n";
            hero.strike(&opponent);
        }
        else if (choise == 2) {
            std::cout << "Your opponent choosed to cure\n";
            opponent.cure();
        }
        else if (choise == 3) {
            std::cout << "Your opponent choosed to train\n";
            opponent.train();
        }
        else {
            std::cout << "Your opponent choosed to learn some spells\n";
            opponent.learn();
        }

        hero.get_info(&opponent);
    }

    if (hero.get_health() > 0) {
        std::cout << "Hero " << name << " wins!!!\n";
    }
    else {
        std::cout << "Hero " << name << " dead...\n";
    }
}