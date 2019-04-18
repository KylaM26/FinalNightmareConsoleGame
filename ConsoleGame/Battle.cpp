#include "Battle.h"

Battle::Battle() {

}

Battle::Battle(Player& player) {

//	const int randomEnemyCount = rand() % 3 + 1;
	//std::cout << "Enemies count: " << randomEnemyCount << std::endl;
	this->player = &player;
	roundCounter = 0;
}

void Battle::StartBattle() {
	enemies = std::vector<Enemy>(1);

	system("cls");
	std::cout << "The battle has begun!" << std::endl;

	for (int i = 0; i < enemies.size(); i++)
		enemies.at(i).GetEnemyStatus(); // Display whether enemy is a boss or not.

	do {
		roundCounter++;
		std::cout << "------------ ROUND " << roundCounter << " " << "------------" << std::endl;
		std::cout << "Your health: " << player->health << std::endl;
		std::cout << "Enemies health: ";
		for (int index = 0; index < enemies.size(); index++) {
			std::cout << enemies.at(index).GetHealth() << " --- ";
		}
		std::cout << std::endl;

		StartCombat();
		
		system("cls");

	} while (IsBattleOver());

	std::cout << "Battle over" << std::endl;
	DetermineWinner();
	player->LevelUp();
	player->CalculateHealth();
}

bool Battle::IsBattleOver() const {

	if (enemies.at(0).health <= 0)
		return false;
	else if (player->health < 0)
		return false;

	return true;
}


void Battle::GetBattleOption()  {
	std::cout << "What would you like to do? " << std::endl << std::endl;;

	std::cout << "1.) Attack/Defend/Heal" << std::endl;
	std::cout << "2.) Pass" << std::endl;
	std::cout << "3.) Run!" << std::endl;

	int choice = 0;

	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "You decied to attack your enemies!" << std::endl;
		break;
	case 2:
		std::cout << "You choose to pass this round" << std::endl;
		break;
	case 3:
		std::cout << "You escaped from the battle!" << std::endl;
		break;
	default: 
		std::cout << "Invalid choice, you passed!" << std::endl;
		break;
	}
}

void Battle::StartCombat() {
	const Card playerCard = player->Attack();

	player->health += playerCard.healPoints;
	for (int index = 0; index < enemies.size(); index++) {
		enemies.at(index).health -= playerCard.attackPoints;
	}


	std::cout << "You used " << playerCard.name << " on your enemies." << std::endl << std::endl;
	std::cout << "Card attackPoints: " << playerCard.attackPoints << std::endl;
	std::cout << "Card healPoints: " << playerCard.healPoints << std::endl;
	system("pause");
	system("cls");

	std::vector<Card> enemyCards = std::vector<Card>(enemies.size());

	for (int index = 0; index < enemies.size(); index++) {
		enemies.at(index).UseCard(*player);
	}

	system("pause");

}

void Battle:: DetermineWinner() {
	if (player->health > 0) {
		std::cout << "You won the battle!" << std::endl;
		for (int index = 0; index < enemies.size(); index++) {
			enemies.at(index).DropLoot(*player);
		}
	}
	else
		std::cout << "You lost the battle." << std::endl;

	system("pause");
}

Battle::~Battle() {
	
}
