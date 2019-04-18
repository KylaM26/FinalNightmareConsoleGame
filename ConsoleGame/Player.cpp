#include "Player.h"

Player::Player() {
	this->inventory = Inventory();
	this->gear = GearSet(inventory);
	this->deck = CardDeck(5, "CardData/PlayerCardData.txt");

	this->gold = 100;
	this->level = 1, this->experience = 100;
	CalculateHealth();
	this->criticalPercentage = (this->level / 2) * 100; // Not sure about this

	//std::cout << "Player deck size: " << deck.GetDeck().size() << std::endl;
}

void Player::ShowStats() const {
	std::cout << " Level: " << level << " | Gold: " << gold << " | Health: " << health << " | Experience: " << experience << std::endl << std::endl;
}

// Figure out why this does not work.
void Player::CalculateHealth() { // Call this after player wants to change clothes
	this->health = 0;
	int baseHealth = level * 50;
	this->health =  baseHealth + (gear.GetCap().GetHealthBonus() + gear.GetCharm().GetHealthBonus() + gear.GetRobe().GetHealthBonus() + gear.GetShoes().GetHealthBonus());
}

const Card Player::Attack() {

	deck.DisplayCards();

	std::cout << "Choose a card: ";
	int cardIndex = 0;
	std::cin >> cardIndex;
	const Card card = deck.ChooseCard(cardIndex);
	return card;
}

void Player::LevelUp() {
	int experienceAdder = level * 110;
	if (experience > experienceAdder) {
		level++;
		std::cout << "You gained a level up!" << std::endl;
		system("pause");
		system("cls");
	}
}

Player::~Player() {
}
