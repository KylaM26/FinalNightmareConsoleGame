#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Player.h"

class Battle {
private:
	int roundCounter;
	std::vector<Enemy> enemies;
	Player* player;
public:
	Battle();
	Battle(Player& player);

	void StartBattle();
	void GetBattleOption();
	void StartCombat();
	bool IsBattleOver() const; 
	void DetermineWinner();
	
	~Battle();
};

