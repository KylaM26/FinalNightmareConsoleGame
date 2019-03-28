#include "Card.h"

Card::Card() {

}

Card::Card(std::string name, int id, int aP, int hP, int dP) {
	this->name = name;
	this->id = id;
	this->attackPoints = aP;
	this->healPoints = hP;
	this->defensePoints = dP;
}


Card::~Card() {
}
