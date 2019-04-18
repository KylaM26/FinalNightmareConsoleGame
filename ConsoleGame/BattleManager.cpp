#include "BattleManager.h"

BattleManager::BattleManager() {

}

BattleManager::BattleManager(Player& player) {

	battle = Battle(player);

	do {
		battle.StartBattle();

		system("cls");
		std::cout << "Battle Ended" << std::endl;
		std::cout << "Would you like to battle again(Y/N)?" << std::endl;

		std::cin.ignore(256, '\n');
		std::string choice;
		std::getline(std::cin, choice);

		if (choice == "y" || choice == "Y")
			doesWantToBattle = true;
		else
			doesWantToBattle = false;

	} while (doesWantToBattle);

}


BattleManager::~BattleManager() {
}
