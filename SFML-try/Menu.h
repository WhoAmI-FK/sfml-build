#pragma once
#include <map>
#include <functional>	
#include <thread>
#include <list>
#define GAMES 2


class Menu
{
public:

	/*
	*
	* typedefs
	*
	*/
	typedef size_t key;
	typedef std::function<void()> game;


	Menu(std::list<std::function<void()>>);
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	Menu(Menu&&) = delete;
	Menu& operator=(Menu&&) = delete;
	void showMenu(void);
private:
	std::map<key, game> _menu;
	std::size_t _numOfGames;
};

