#pragma once

#include "Item.h"
#include "Inventory.h"
#include "GearSet.h"
#include "CardDeck.h"

class Player {
public:
	int gold;
	int level, experience;
	int health;
	float criticalPercentage;

	Inventory inventory; // Player's Inventory
	GearSet gear; // Player's gear
	CardDeck deck; // Player's deck
	Player();

	void CalculateHealth(); // Health will be recalculated everytime the player levels up

	void Attack(); 
	void Defend();
	void Die();
	void Heal();

	void ShowStats() const;

	~Player();
};

