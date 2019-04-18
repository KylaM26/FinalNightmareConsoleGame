#include "Shop.h"



Shop::Shop() {
	shop = Inventory();
	shop.FillInventory("ShoppingItems.txt", 5); // Finishing filling shop with stuff
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
		std::cout << "Enter the name of item you would like to purchase: ";
		std::string itemName;

		std::getline(std::cin, itemName);

		for (int index = 0; index < shop.GetInventorySize(); index++) {
			if (itemName == shop.GetInventory().at(index).name) {
				if (player.gold >= shop.GetInventory().at(index).price) {
					player.gold -= shop.GetInventory().at(index).price;
					player.inventory.AddItem(shop.GetInventory().at(index));
					std::cout << "You successfully purchased " << itemName << std::endl;
					std::cout << "Would you like to continue shopping(Y/N): ";

					std::string choice;
					std::getline(std::cin, choice);

					if (choice == "Y" || choice == "y")
						continue;
					else
						isShopping = false;				
				}
			}
		}

	} while (isShopping);
}

Shop::~Shop() {
}
