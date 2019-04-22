#include "ShopManager.h"


ShopManager::ShopManager() {
	shop = Shop();
}
void ShopManager::OpenShop(Player& player) {
	bool doesWantToShop = true;
	do {

		shop.ChooseClothingCategory();
		shop.BuyItem(player);

		std::cout << "Would you like to continue shopping: (Y/N): ";
		std::string choice;
		std::getline(std::cin, choice);

		if (choice == "Y" || choice == "y")
			doesWantToShop = true;
		else
			doesWantToShop = false;

		system("cls");

	} while (doesWantToShop);
}



ShopManager::~ShopManager() {
}
