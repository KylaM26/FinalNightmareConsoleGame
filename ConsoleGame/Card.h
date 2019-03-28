#pragma once

#include <iostream>
#include <string>

class Card {
public:
	std::string name;
	int id;
	int attackPoints;
	int healPoints;
	int defensePoints;

	Card();
	Card(std::string name, int id, int aP, int hP, int dP);
	~Card();
};

