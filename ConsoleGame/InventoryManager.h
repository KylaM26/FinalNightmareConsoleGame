#pragma once
#include "Player.h"

class InventoryManager {
private:
	bool isInInventory;
	int choice;
public:
	InventoryManager();
	void OpenInventory(Player& player);
	~InventoryManager();
};

