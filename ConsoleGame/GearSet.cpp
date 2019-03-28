#include "GearSet.h"

GearSet::GearSet() {

}

GearSet::GearSet(Inventory& inventory) {
	set = std::vector<Item>(4);

	const Item noobCap = Item("Noob Cap", 5, 2, .5, 0.0, CAP);
	const Item noobCharm = Item("Noob Charm", 5, 2, .5, 0.0, CHARM);
	const Item noobRobe = Item("Noob Robe", 5, 2, .5, 0.0, ROBE);
	const Item noobShoes = Item("Noob Shoes", 5, 2, .5, 0.0, SHOES);

	inventory.AddItem(noobCap);
	inventory.AddItem(noobCharm);
	inventory.AddItem(noobRobe);
	inventory.AddItem(noobShoes);

	SetCap(inventory.GetItem("Noob Cap", CAP));
	SetCharm(inventory.GetItem("Noob Charm", CHARM));
	SetRobe(inventory.GetItem("Noob Robe", ROBE));
	SetShoes(inventory.GetItem("Noob Shoes", SHOES));
}

void GearSet::ShowGearSet() const {
	std::cout << "----- You are wearing ---- " << std::endl;
	set.at(0).DisplayStats();
	set.at(1).DisplayStats();
	set.at(2).DisplayStats();
	set.at(3).DisplayStats();
}

void GearSet::SetCap(const Item& item) {
	if (item.GetItemType() == CAP)
		set.at(0) = item;
}
void GearSet::SetCharm(const Item& item) {
	if (item.GetItemType() == CHARM)
		set.at(1) = item;
}
void GearSet::SetRobe(const Item& item) {
	if (item.GetItemType() == ROBE)
		set.at(2) = item;
}
void GearSet::SetShoes(const Item& item) {
	if (item.GetItemType() == SHOES)
		set.at(3) = item;
}

void GearSet::ChangeGear(Inventory& inventory) {
	bool isChanging = true;
	std::cin.ignore(80, '\n');
	while (isChanging) {
		std::string itemName;
		std::cout << "Enter item name(Enter 'Done' to quit): ";
		std::getline(std::cin, itemName);

		if (itemName == "Done")
			isChanging = false;

		for (int index = 0; index < inventory.GetInventorySize(); index++) {
			if (inventory.GetInventory().at(index).GetItemName() == itemName) {
				Item i = inventory.GetInventory().at(index);
				switch (i.GetItemType()) {
				case CAP:
					SetCap(i);
					break;
				case CHARM:
					SetCharm(i);
					break;
				case ROBE:
					SetRobe(i);
					break;
				case SHOES:
					SetShoes(i);
					break;
				default:
					return;
				}

				std::cout << itemName << " was successfully equiped!\n";
			}
		}
	}

	system("cls");
}

Item GearSet::GetCap() const {
	return this->set.at(0);
}

Item GearSet::GetCharm() const {
	return this->set.at(1);
}

Item GearSet::GetRobe() const {
	return this->set.at(2);
}

Item GearSet::GetShoes() const {
	return this->set.at(3);
}

std::vector<Item>& GearSet::GetGear()  {
	return set;
}

GearSet::~GearSet() {
}
