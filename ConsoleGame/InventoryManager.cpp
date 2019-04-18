#include "InventoryManager.h"



InventoryManager::InventoryManager() {
	this->isInInventory = false;
	this->choice = 0;
}

void InventoryManager::OpenInventory(Player& player) {
	isInInventory = true;
	player.inventory.AddItem(Item("Test Cap", 0, 0, 0, 0,0, CAP));
	player.inventory.AddItem(Item("Test Robe", 0, 0, 0, 0,0, ROBE));

	while (isInInventory) {
		player.gear.ShowGearSet();

		choice = player.inventory.GetOption();

		switch (choice) {
		case 0:
			player.inventory.ListItems(choice);
			break;
		case 1:
			player.inventory.ListItems(choice);
			break;
		case 2:
			player.inventory.ListItems(choice);
			break;
		case 3:
			player.inventory.ListItems(choice);
			break;
		case 4:
			player.gear.ChangeGear(player.inventory);
			player.CalculateHealth();
			break;
		case 5:
			player.inventory.DeleteItem(player.gear.GetGear());
			player.CalculateHealth();
			break;
		case 6:
			isInInventory = false;
			break;
		}
	}
}


InventoryManager::~InventoryManager() {
}
