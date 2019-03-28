#pragma once

#include <iostream>
#include <vector>

#include "InventoryManager.h"
#include "Player.h"
#include "Menu.h"
#include "Enemy.h"
class Game {
private:
	bool quit; // Controls game
	Enemy enemy;
	Menu menu; // Creates the main menu
	InventoryManager inventoryManager; //Mangages anything dealing with inventory
	Player player; // Createing a player for the game.s
public:
	Game();

	void Play();

	bool GetQuitStatus() const;

	~Game();
};

