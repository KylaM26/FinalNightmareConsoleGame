#include "CardDeck.h"

CardDeck::CardDeck() {
	numberOfCards = 0;
}

CardDeck::CardDeck(int numberOfCards, const char* path) {
	this->numberOfCards = numberOfCards;
	this->deck = std::vector<Card>(numberOfCards);
	ReadCardData(path);

}

void CardDeck::ReadCardData(const char* path) {
	std::ifstream file(path);
	if (file.is_open()) {
		int index = 0;

		while (true) {
			// Figure out index issue
			file >> deck.at(index).id >> deck.at(index).name >> deck.at(index).attackPoints >> deck.at(index).healPoints >> deck.at(index).defensePoints;

			if (index == numberOfCards - 1)
				break;

			index++;
		}

		file.close();
	}

}

std::vector<Card>CardDeck::GetDeck() const {
	return deck;
}

const Card& CardDeck::GetCard(int cardIndex) const {
	if (cardIndex > numberOfCards) {
		std::cout << "Card out of  range" << std::endl;
		return Card("NA", 0, 0, 0, 0);
	}

	return deck.at(cardIndex);
}

void CardDeck::AddCard(const Card& card) {
	deck.push_back(card);
}

const Card CardDeck::ChooseCard(const int index) const {
	if (index < deck.size())
		return deck.at(index);
	
	return deck.at(0);
}

void CardDeck::DisplayCards() {
	std::cout << std::endl;
	std::cout << "------- Your cards -------" << std::endl;
	for (int index = 0; index < deck.size(); index++) {
		std::cout << index << ") "<< deck.at(index).name << std::endl;
	}
}
CardDeck::~CardDeck() {
}
