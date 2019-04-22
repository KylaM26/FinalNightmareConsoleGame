#include "Shop.h"



Shop::Shop() {
	shop = Inventory();
	shop.FillInventory("ItemData/ShopItems.txt", 2); // Finishing filling shop with stuff
}

void Shop::ChooseClothingCategory() {
	std::cout << "Choose clothing category" << std::endl << std::endl;

	std::cout << " 1.) Caps\n 2.) Charms\n 3.) Robes\n 4.) Shoes\n\n";
	
	int choice = 0;
	std::cin >> choice;
	DisplayClothes(choice);
}


void Shop::DisplayClothes(int choice) const {
	switch (choice) {
	case 1:
		shop.ListCaps();
		break;
	case 2:
		shop.ListCharms();
		break;
	case 3:
		shop.ListRobes();
		break;
	case 4:
		shop.ListShoes();
		break;
	default:
		std::cout << "Invalid option entered." << std::endl;
		break;
	}
}

void Shop::BuyItem(Player& player) {
	bool isShopping = true;

	do {
		std::cout << "Enter the name of item you would like to purchase(Enter Done to quit): ";
		std::string itemName;

		std::cin.ignore(256, '\n');
		std::getline(std::cin, itemName);

		Item item = Item();
		for (int index = 0; index < shop.GetInventorySize(); index++) {
			if (itemName == shop.GetInventory().at(index).name) {
				item = shop.GetInventory().at(index);
				if (player.gold >= item.price) {
					player.gold -= item.price;
					player.inventory.AddItem(item);
					std::cout << "You successfully purchased " << itemName << std::endl;
				}
			}
		}

		if (itemName != item.name)
			std::cout << "Could not find item." << std::endl;

		std::string choice;
		std::getline(std::cin, choice);

		if (choice == "Done" || choice == "done")
			isShopping = false;
		else
			isShopping = true;

	} while (isShopping);
}

Shop::~Shop() {
}
