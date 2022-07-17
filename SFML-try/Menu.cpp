#include "Menu.h"
// Need fixes

Menu::Menu(std::size_t num,...)
{
	va_list vl;
	va_start(vl, num);
	for (int i = 0; i < num; i++)
	{
		std::function<void()> _store = va_arg(vl, std::function<void()>);
	}
	va_end(vl);
}


void Menu::showMenu(void) {
	_menu[1]();
}