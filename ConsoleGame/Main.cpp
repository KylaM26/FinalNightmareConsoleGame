#include <iostream>

#include "Game.h"

int main() {

	try {
		Game* game = new Game();

		while (!game->GetQuitStatus()) {
			game->Play();
		}

		delete game;
		game = nullptr;

	} catch (std::bad_alloc) {
		std::cout << "Could not allocate required amount of memory for game." << std::endl;
	}

	return 0;
	system("pause");
}