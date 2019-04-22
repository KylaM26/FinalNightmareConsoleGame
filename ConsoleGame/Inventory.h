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

	void AddItem(const Item& item); // Adds an item to the inventory
	void DeleteItem(std::vector<Item>& playerGear); // Delete an item


	void ListItems(int choice) const; // List the current items.
	void ListCaps() const;
	void ListCharms() const;
	void ListRobes() const;
	void ListShoes() const;

	const int GetOption() const;
	void FillInventory(const char* path, int itemsCount); // Fills the inventory via a file stream

	const Item& GetItem(const char* name, ITEM_TYPE type) const; // Gets an item by name and type
	std::vector<Item>& GetInventory();
	const int GetInventorySize() const;

	~Inventory();
};

