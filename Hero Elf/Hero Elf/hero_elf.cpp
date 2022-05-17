#include "hero_elf.h"
#include <iostream>

hero_elf::hero_elf() {}

void hero_elf::set_param(std::string name, int health, int strength, int magicity, int intellect) {
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->magicity = magicity;
	this->intellect = intellect;
}

int hero_elf::get_health() {
	return this->health;
}

void hero_elf::get_info(hero_elf* opponent) {
	std::cout << "Your hero: \n";
	std::cout << " health | strength | magicity | intellect\n";
	std::cout << " " << this->health << " | " << this->strength << " | " << this->magicity << " | " << this->intellect << std::endl;
	std::cout << "Your opponent (" << opponent->name << "): \n";
	std::cout << " health | strength | magicity | intellect\n";
	std::cout << " " << opponent->health << " | " << opponent->strength 
		<< " | " << opponent->magicity << " | " << opponent->intellect << std::endl;

}

void hero_elf::strike(hero_elf* other_hero) {
	int tmp = std::rand() % this->strength + 1;
	other_hero->health -= tmp;
}

void hero_elf::cure() {
	int tmp = std::rand() % this->magicity + 1;
	this->health += tmp;
}

void hero_elf::train() {
	int tmp = std::rand() % this->health + 1;
	this->strength += tmp;
}

void hero_elf::learn() {
	int tmp = std::rand() % this->intellect + 1;
	this->magicity += tmp;
}
