#include "CardDeck.h"

CardDeck::CardDeck() {
	numberOfCards = 0;
}

CardDeck::CardDeck(int numberOfCards, const char* path) {
	this->numberOfCards = numberOfCards;
	ReadCardData(path);
}

void CardDeck::ReadCardData(const char* path) {
	std::ifstream file(path);

	if (file.is_open()) {
		for (int index = 0; index < numberOfCards; index++) {
			Card newCard = Card();
			deck.push_back(newCard);
			while (file >> deck.at(index).id >> deck.at(index).name >> deck.at(index).attackPoints >> deck.at(index).healPoints >> deck.at(index).defensePoints) {
	//			std::cout << deck.at(index).id << ", " << deck.at(index).name << std::endl;
			}
		}
	} else {
		std::cout << "Could not open file to read card data." << std::endl;
		return;
	}

	file.close();
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

CardDeck::~CardDeck() {
}
