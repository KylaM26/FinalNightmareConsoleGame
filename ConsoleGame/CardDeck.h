#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Card.h"

class CardDeck {
private:
	std::vector<Card> deck;
	int numberOfCards;

	void ReadCardData(const char* path);
public:
	CardDeck();
	CardDeck(int numberOfCards, const char* path);

	void DisplayCards();
	const Card ChooseCard(const int index) const;

	std::vector<Card> GetDeck() const;
	const Card& GetCard(int cardIndex) const;
	void AddCard(const Card& card);
	~CardDeck();
};

