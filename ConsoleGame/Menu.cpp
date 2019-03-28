#include "Menu.h"

Menu::Menu() {

}

void Menu::PrintMenu() const {
	std::cout << "------ MAIN MENU -------\n";
	std::cout << " 1) Adventure\n";
	std::cout << " 2) Inventory\n";
	std::cout << " 3) Shop\n\n";
}

const int Menu::GetMenuChoice() {
	PrintMenu();
	std::cout << "Enter your choice: ";

	int choice = 0;
	std::cin >> choice;

	system("cls");

	return choice;
}

Menu::~Menu() {

}
