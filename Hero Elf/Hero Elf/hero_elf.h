#pragma once
#include <string>
#include <stdlib.h>
#include <ctime> std::srand(time(0);
class hero_elf
{
private:
	std::string name;
	int health;
	int strength;
	int magicity; // Авторский неологизм на английском. Что-то типо "колдунство"
	int intellect;
public:
	// Creating a hero
	hero_elf();

	void set_param(std::string name, int health, int strength, int magicity, int intellect);

	// Returns health of a hero
	int get_health();

	void get_info(hero_elf* opponent);

	// Show your opponent the strength of your muscles
	void strike(hero_elf* other_hero);

	// Cure yourself with a potion
	void cure();

	// Train a bit
	void train();

	// Learning new magic spells
	void learn();
};

