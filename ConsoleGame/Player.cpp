#include "Player.h"

Player::Player() {
	this->inventory = Inventory();
	this->gear = GearSet(inventory);
	this->deck = CardDeck(5, "CardData/PlayerCardData.txt");

	this->gold = 100;
	this->level = 1, this->experience = 100;
	CalculateHealth();
	this->criticalPercentage = (this->level / 2) * 100; // Not sure about this

}

void Player::ShowStats() const {
	std::cout << " Level: " << level << " | Gold: " << gold << " | Health: " << health << " | Experience: " << experience << std::endl << std::endl;
}

// Figure out why this does not work.
void Player::CalculateHealth() { // Call this after player wants to change clothes
	this->health =  (gear.GetCap().GetHealthBonus() + gear.GetCharm().GetHealthBonus() + gear.GetRobe().GetHealthBonus() + gear.GetShoes().GetHealthBonus()) + (this->experience / 2);
}

Player::~Player() {
}
