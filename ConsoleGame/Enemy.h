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
	CardDeck deck;
	bool isBoss;

public:
	Enemy();
	int health;
	void UseCard(Player& player);
	void DropLoot(Player& player);
	void Die(Player& player);
	void GetEnemyStatus() const;
	int GetHealth() const;
	~Enemy();
};

