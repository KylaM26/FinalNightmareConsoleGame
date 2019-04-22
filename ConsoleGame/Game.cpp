#include "Game.h"

Game::Game() {
	// Instantiate variables
	inventoryManager = InventoryManager();
	battleManager = BattleManager();
	shopManager = ShopManager();
	//	menu = Menu();
}

void Game::Play() {
	player.ShowStats(); // Show the players status
	// enemy.Die(player);
	int choice = menu.GetMenuChoice(); // Will show menu and get an option
	switch (choice) { 
	case 1: // Player wants to adventure
		std::cout << "Began Adventure" << std::endl;
		battleManager = BattleManager(player);
		break;
	case 2: // Player wants to go into inventory mode
		inventoryManager.OpenInventory(player);
		system("pause");
		system("cls");
		break;
	case 3: // Player wants to shop
		shopManager.OpenShop(player);
		system("pause");
		system("cls");
		break;

	}

	system("cls");
}

bool Game::GetQuitStatus() const {
	return quit;
}

Game::~Game() {

}
