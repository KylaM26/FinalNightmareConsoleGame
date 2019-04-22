#pragma once
#include <iostream>
#include "Inventory.h"
#include "Player.h"

class Shop {
private:
	Inventory shop; // The shop is an inventory 
public:
	Shop();
	void ChooseClothingCategory(); // Chooses the category to shop by
	void DisplayClothes(int choice) const; // Display clothes by category
	void BuyItem(Player& player); // Adds item to player inventory after purchase
	~Shop();
};

