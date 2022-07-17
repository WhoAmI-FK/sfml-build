#include "Menu.h"
#include "Minesweeper.h"
#include "Tags.h"
#include <iostream>
#include <typeinfo>
//#include "Tetris.h"
#define TESTING
int main()
{

#ifdef TESTING
	Menu m(2,Tags,Minesweeper);
	m.showMenu();
#endif 

//	std::cout << typeid(Tags).name() << std::endl;
	return 0;
}