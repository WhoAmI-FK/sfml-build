#include "Menu.h"
#include "Minesweeper.h"
#include "Tags.h"
#include "Tetris.h"
#include <iostream>
#include <typeinfo>
//#include "Tetris.h"
#define TESTING
int main()
{

#ifdef TESTING
	using namespace __mini_games;
	Menu m({ std::function<void()>(Tags),std::function<void()>(Minesweeper),std::function<void()>(Tetris)});
	m.showMenu();
#endif 

//	std::cout << typeid(Tags).name() << std::endl;
	return 0;
}