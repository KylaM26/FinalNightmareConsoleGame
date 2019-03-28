#include "Enemy.h"

Enemy::Enemy() {
	srand(time(0));
	health = rand() % 20 + 10;
	deck = CardDeck(5, "CardData/EnemyCardData.txt");
}

void Enemy::UseCard(Player& player) {
	srand(time(0));
	int random = rand() % 5;

	health += deck.GetCard(random).healPoints;
	player.health -= deck.GetCard(random).attackPoints;
}

void Enemy::DropLoot(Player& player) {
	srand(time(0));
	player.gold += rand() % player.level + 1;

	int randomChance = rand() % 100;


	if (randomChance > 0 && randomChance < 100) {
		std::ifstream file;
		
		const int itemCount = 2;
		std::vector<Item> items = std::vector<Item>(itemCount);
		int index = 0;

		file.open("ItemData/Items.txt");
		
		if (!file.is_open()) {
			std::cout << "Failed to open item data file." << std::endl;
			return;
		}

		while (true) {
			file >> items.at(index).name >> items.at(index).attackBonus >> items.at(index).healthBonus >> items.at(index).healBonus >> items.at(index).criticalBonus >> items.at(index).type;
	
			if (index == itemCount - 1)
				break;

			index += 1;
		}

		file.close();
	}
}

void Enemy::Die(Player& player) {
	DropLoot(player);
}

Enemy::~Enemy() {
}
