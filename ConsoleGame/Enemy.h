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
	void UseCard(Player& player); // Uses attack on player
	void DropLoot(Player& player); // Drops an item and adds it to the player inventory.
	void Die(Player& player); // This function calls droploot function.
	void GetEnemyStatus() const; // Display health
	int GetHealth() const;
	~Enemy();
};

