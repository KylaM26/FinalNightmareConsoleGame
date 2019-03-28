#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "CardDeck.h"
#include "Player.h"

class Enemy {
private:
	int health;
	CardDeck deck;
	void DropLoot(Player& player);
public:
	Enemy();

	void UseCard(Player& player);
	void Die(Player& player);

	~Enemy();
};

