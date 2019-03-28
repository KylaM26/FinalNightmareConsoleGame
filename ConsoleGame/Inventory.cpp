#include "Inventory.h"

Inventory::Inventory() {
	this->items = std::vector<Item>(0);	
}

void Inventory::AddItem(const Item& item) {
	items.push_back(item);
}

void Inventory::DeleteItem(std::vector<Item>& playerGear) {
	std::cin.ignore(80, '\n');
	bool isDeletingItems = true;

	while (isDeletingItems) {
		std::string itemName = "";
		std::cout << "Enter name of item(Enter 'Done' to quit): ";

		std::getline(std::cin, itemName);

		if (itemName == "Done")
			isDeletingItems = false;

		int itemNum = 0;

		for (int index = 0; index < items.size(); index++) {
			if (items.at(index).GetItemName() == itemName) {
				itemNum = index;
			}
		}

		if (itemNum < playerGear.size()) {
			if (playerGear.at(itemNum).name == itemName) {
				std::cout << "Cannot delete item that you are wearing." << std::endl;
				system("pause");
			} else {

			}
		}

		if (items.at(itemNum).name == itemName) {
			items.erase(items.begin() + itemNum);
			std::cout << "Successfully deleted " << itemName << std::endl;
		}

 	}

	system("cls");
}

void Inventory::ListItems(int choice) const {
	system("cls");
	switch (choice) {
	case 0:
		ListCaps();
		break;
	case 1:
		ListCharms();
		break;
	case 2:
		ListRobes();
		break;
	case 3:
		ListShoes();
		break;
	default:
		return;
	}
	
	system("pause");
	system("cls");

}

void Inventory::ListCaps() const {
	std::cout << "------ CAPS -------\n";
	for (auto& item : items) {
		if (item.GetItemType() == CAP)
			item.DisplayStats();
	}
}

void Inventory::ListCharms() const {
	std::cout << "------ CHARMS -------\n";
	for (auto& item : items) {
		if (item.GetItemType() == CHARM)
			item.DisplayStats();
	}

}

void Inventory::ListRobes() const {
	std::cout << "------ ROBES -------\n";
	for (auto& item : items) {
		if (item.GetItemType() == ROBE)
			item.DisplayStats();
	}
}

void Inventory::ListShoes() const {
	std::cout << "------ SHOES -------\n";
	for (auto& item : items) {
		if (item.GetItemType() == SHOES)
			item.DisplayStats();
	}

}


const int Inventory::GetOption() const {
		int option = 0;

		std::cout << "-------- Options --------\n ";
		std::cout << "0 = List Caps | 1 = List Charms| 2 = List Robes | 3 = List Shoes \n 4 = Equip Item | 5 = Delete Item | 6 = Main Menu\n\n";
		std::cout << "Choice: ";
		
		std::cin >> option;
		switch (option) {
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		case 6: 
			return 6;
		default:
			return 6;
	}
	return 0;
}

const Item& Inventory::GetItem(const char* name, ITEM_TYPE type) const {
	Item theItem = Item();
	bool isLookingAtInventory = true;
	int index = 0;

	while (isLookingAtInventory) {
		if (items.at(index).name != name && items.at(index).type != type)
			index++;
		else
			isLookingAtInventory = false;

		if (index == items.size()) {
			isLookingAtInventory = false;
			return Item("NA", 0, 0, 0, 0, NONE);
		}
	}

	return items.at(index);

}

std::vector<Item>&Inventory::GetInventory() {
	return this->items;
}

const int Inventory::GetInventorySize() const {
	return this->items.size();
}

Inventory::~Inventory() {

}
