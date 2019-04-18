#include "Enemy.h"

Enemy::Enemy() {
	srand(time(0));

	if (rand() % 100 > 80) {
		health = (rand() % (20 + 10) * 2);
		isBoss = true; // Bosses will have twice amount of health
	} else {
		isBoss = false;
		health = (rand() % 20 + 10);
	}
	this->deck = CardDeck(5, "CardData/EnemyCardData.txt");
//	std::cout << "Deck size: " << deck.GetDeck().size() << std::endl;
	//system("pause");
}

void Enemy::UseCard(Player& player) {
	srand(time(0));
	int random = rand() % 5;

	health += deck.GetCard(random).healPoints;
	player.health -= deck.GetCard(random).attackPoints;
	std::cout << "Your enemy used: " << deck.ChooseCard(random).name << std::endl;

}

void Enemy::DropLoot(Player& player) {
	srand(time(0));
	player.gold += rand() % player.level + 1;

	int randomChance1 = rand() % 100;

	if (randomChance1 > 0 && randomChance1 < 100) {
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

		int randomIndex = rand() % items.size();
		Item droppedItem = items.at(randomIndex);

		std::cout << "You recieved " << droppedItem.name << std::endl;
		player.inventory.AddItem(droppedItem);
	} else {
		std::cout << "You recieved 50 pieces of gold." << std::endl;
		player.gold += 50;
	}

	player.experience += 10;
}

void Enemy::Die(Player& player) {
	DropLoot(player);
}

int Enemy::GetHealth() const{
	return health;
}
void Enemy::GetEnemyStatus() const {
	std::cout << std::endl;
	if (isBoss)
		std::cout << "Boss enemy was spawned!" << std::endl;
	else
		std::cout << "An enemy was spawned." << std::endl;
}

Enemy::~Enemy() {
}
