#include "Menu.h"
// Need fixes

Menu::Menu(std::list<std::function<void()>> _list) {
	_numOfGames = 1;
	for (auto t : _list) {
		_menu[_numOfGames] = t;
		_numOfGames++;
	}
}


void Menu::showMenu(void) {
	_menu[3]();
}