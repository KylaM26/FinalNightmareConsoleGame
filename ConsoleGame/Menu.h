#pragma once

#include <iostream>
#include "Utiltities.h"

class Menu {
private:
	void PrintMenu() const;
public:
	Menu();
	
	const int GetMenuChoice();

	~Menu();
};

