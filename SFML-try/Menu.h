#pragma once
#include <map>
#include <functional>	
#include <thread>
#include <stdarg.h>
#define GAMES 2


class Menu
{
public:
	typedef size_t key;
	typedef std::function<void()> game;
	Menu(std::size_t num,...);
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	Menu(Menu&&) = delete;
	Menu& operator=(Menu&&) = delete;
	void showMenu(void);
private:
	std::map<key, game> _menu;
	std::size_t _numOfGames;
};

