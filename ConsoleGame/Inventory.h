#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include <fstream>
//#include "Player.h"

class Inventory {
private:
	std::vector<Item> items;
public:
	Inventory();

	void AddItem(const Item& item);
	void DeleteItem(std::vector<Item>& playerGear);


	void ListItems(int choice) const;
	void ListCaps() const;
	void ListCharms() const;
	void ListRobes() const;
	void ListShoes() const;

	const int GetOption() const;
	void FillInventory(const char* path, int itemsCount);

	const Item& GetItem(const char* name, ITEM_TYPE type) const;
	std::vector<Item>& GetInventory();
	const int GetInventorySize() const;

	~Inventory();
};

