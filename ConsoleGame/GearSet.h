#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Inventory.h"
#include "Item.h"

class GearSet {
private:
	std::vector<Item> set;
public:
	GearSet();
	GearSet(Inventory& inventory); // Takes in a inventory(player's specifically)

	void ShowGearSet() const; // Shows item that player is wearing.
	void SetCap(const Item& item); // Sets cap
	void SetCharm(const Item& item); // Sets charm
	void SetRobe(const Item& item); // Sets robe
	void SetShoes(const Item& item); // Sets shoes
	void ChangeGear(Inventory& inventory); // Change gear

	Item GetCap() const;
	Item GetCharm() const;
	Item GetRobe() const;
	Item GetShoes() const;

	std::vector<Item>& GetGear(); 

	~GearSet();
};

