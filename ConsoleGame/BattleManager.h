#pragma once
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Battle.h"
#include <string>

class BattleManager {
private:
	Battle battle;
	bool doesWantToBattle;
public:
	BattleManager();
	BattleManager(Player& player);
	~BattleManager();
};

