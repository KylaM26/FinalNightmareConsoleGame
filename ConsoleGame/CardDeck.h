#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Card.h"

class CardDeck {
private:
	std::vector<Card> deck; // Contains an array of cards
	int numberOfCards;

	void ReadCardData(const char* path); // Reads card data from a file.
public:
	CardDeck();
	CardDeck(int numberOfCards, const char* path); // Loads cards from file upon initiation.

	void DisplayCards();
	const Card ChooseCard(const int index) const;

	std::vector<Card> GetDeck() const;
	const Card& GetCard(int cardIndex) const;
	void AddCard(const Card& card);
	~CardDeck();
};

