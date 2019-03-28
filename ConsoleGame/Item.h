#pragma once
#include <iostream>
#include <string>

enum ITEM_TYPE {
	CAP = 0,
	CHARM = 1,
	ROBE = 2,
	SHOES = 3,
	NONE = 4
};

class Item {
public:
	std::string name;
	int healthBonus, attackBonus;
	float healBonus, criticalBonus;
	int type;

	Item();

	Item(const char* itemName, int health, int attack, float heal, float critical, int itemType);

	void DisplayStats() const;

	const int GetHealthBonus() const;
	const int GetAttackBonus() const;
	const float GetHealBonus() const;
	const float GetCriticalBonus() const;

	const char* GetItemName() const;
	const int GetItemType() const;

	~Item();
};

