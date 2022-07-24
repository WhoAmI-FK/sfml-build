#include "Menu.h"
#define music_path "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\music-menu\\ogg\\menu_music.ogg"
#define logo_path "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-menu\\minigames.png"
// Need fixes

using namespace __mini_games;

MenuUIEl::MenuUIEl(const char* _texturePath){
	_texture.loadFromFile(_texturePath);
	_sprite.setTexture(_texture);
}

MenuLogo::MenuLogo(const char* _texturePath)
	:MenuUIEl(_texturePath)
{

}
sfSprite MenuLogo::getSprite() const {
	return _sprite;
}
void MenuUIEl::setScale(const float& factorX, const float& factorY)
{
	_sprite.setScale(factorX, factorY);
}

void MenuUIEl::setPosition(const float& x, const float& y)
{
	_sprite.setPosition(x, y);
}

Menu::Menu(std::list<std::function<void()>> _list)
	:_logo(logo_path)
{
	if (!_music.openFromFile(music_path)) return;

	_numOfGames = 1;
	for (auto t : _list) {
		_menu[_numOfGames] = t;
		_numOfGames++;
	}
}


void Menu::showMenu(void) {
	sfRenderWindow window(sf::VideoMode(),"MENU", sf::Style::Fullscreen);
	_music.setLoop(true);
	_music.play();
	_music.setVolume(70);
	while (window.isOpen())
	{
		while (window.pollEvent(_menuEvent))
		{
			if (_menuEvent.type == sfEvent::Closed)
			{
				window.close();
			}
		}
		window.clear(sfColor::White);
		_logo.setScale(1.5, 1.5);
		// Centering Logo
		_logo.setPosition((window.getSize().x - _logo.getSprite().getTexture()->getSize().x)/3, 0);
		window.draw(_logo.getSprite());
		window.display();
	}
}