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
	GearSet(Inventory& inventory);

	void ShowGearSet() const;
	void SetCap(const Item& item);
	void SetCharm(const Item& item);
	void SetRobe(const Item& item);
	void SetShoes(const Item& item);
	void ChangeGear(Inventory& inventory);

	Item GetCap() const;
	Item GetCharm() const;
	Item GetRobe() const;
	Item GetShoes() const;

	std::vector<Item>& GetGear();

	~GearSet();
};

