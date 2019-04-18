#pragma once
#include <iostream>
#include "Inventory.h"
#include "Player.h"

class Shop {
private:
	Inventory shop;
public:
	Shop();
	void ChooseClothingCategory();
	void DisplayClothes(int choice) const;
	void BuyItem(Player& player);
	~Shop();
};

