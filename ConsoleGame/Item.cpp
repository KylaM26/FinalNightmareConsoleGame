#include "Item.h"

Item::Item() {
	this->name = "UNKNOWN";
	this->price = 0;
	this->healthBonus = 0, this->attackBonus = 0;
	this->healBonus = 0, this->criticalBonus = 0;
	this->type = NONE;
}

Item::Item(const char* itemName, int health, int attack, float heal, float critical,int price, int itemType) {
	this->name = itemName;
	this->price = price;
	this->healthBonus = health;
	this->attackBonus = attack;
	this->healBonus = heal;
	this->criticalBonus = critical;
	this->type = itemType;
}

void Item::DisplayStats() const {
	std::cout << "\n Name: " << this->name << " | Health bonus: " << this->healthBonus
		<< "\n Attack bonus: " << this->attackBonus << " | Heal bonus: " << this->healBonus << " | Critical bonus: " << this->criticalBonus << std::endl << std::endl;
}

const int Item::GetHealthBonus() const {
	return this->healthBonus;
}

const int Item::GetAttackBonus() const {
	return this->attackBonus;
}

const float Item::GetHealBonus() const {
	return this->healBonus;
}

const float Item::GetCriticalBonus() const {
	return this->criticalBonus;
}

const int Item::GetItemType() const {
	return this->type;
}

const char* Item::GetItemName() const {
	return this->name.c_str();
}

Item::~Item() {
}
