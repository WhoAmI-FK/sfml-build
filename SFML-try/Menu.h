#pragma once
#include <map>
#include <functional>
class Menu
{
public:
	typedef size_t key;
	typedef std::function<void(void)> game;
	Menu(...);
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	Menu(Menu&&) = delete;
	Menu& operator=(Menu&&) = delete;
private:
	std::map<key, game> _menu;


};

