#pragma once
#include <map>
#include <functional>	
//#include <thread>
#include <list>
#include "SFML_LIBS.h"
#include "TypeDefs.h"
#define GAMES 2

namespace __mini_games 
{

	class MenuUIEl 
	{
	protected:
		MenuUIEl(const char*);
		sfSprite _sprite;
		sfTexture _texture;
	public:
		MenuUIEl() = delete;
		void setScale(const float& factorX, const float& factorY);
		void setPosition(const float& x, const float& y);
	};

	class MenuLogo: public MenuUIEl 
	{
	public:
		MenuLogo(const char*);
		MenuLogo(const MenuLogo&) = delete;
		MenuLogo& operator=(const MenuLogo&) = delete;
		MenuLogo(MenuLogo&&) = delete;
		MenuLogo& operator=(MenuLogo&&) = delete;	
		sfSprite getSprite() const;
		void setTexture();
		
	};

	class GameTab : public MenuUIEl 
	{

	};

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
		sfEvent _menuEvent;
		sfMusic _music;
		MenuLogo _logo;
	};
}