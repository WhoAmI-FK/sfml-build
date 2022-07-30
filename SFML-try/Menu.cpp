#include "Menu.h"
#define music_path "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\music-menu\\ogg\\menu_music.ogg"
#define logo_path "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-menu\\minigames.png"
#define tags_logo "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-menu\\15_logo.png"
#define minesweeper_logo "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-menu\\minesweeper-logo.png"
#define tetris_logo "C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-menu\\tetris-logo.png"
// Need fixes

using namespace __mini_games;

MenuUIEl::MenuUIEl(const char* _texturePath){
	_texture.loadFromFile(_texturePath);
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
}

MenuLogo::MenuLogo(const char* _texturePath)
	:MenuUIEl(_texturePath)
{

}

GameTab::GameTab(const char* _texturePath) 
	: MenuUIEl(_texturePath)
{
	
}
void Menu::initGameTabs(std::vector<std::unique_ptr<GameTab>>& v) {
	std::unique_ptr<GameTab> tetris(new GameTab(tetris_logo));
	std::unique_ptr<GameTab> tags(new GameTab(tags_logo));
	std::unique_ptr<GameTab> minesweeper(new GameTab(minesweeper_logo));
	v.push_back(std::move(tetris));
	v.push_back(std::move(tags));
	v.push_back(std::move(minesweeper));
}

sfSprite MenuUIEl::getSprite() const {
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
	:_logo(logo_path),_selected(0)
{
	if (!_music.openFromFile(music_path)) return;

	_numOfGames = 1;
	for (auto t : _list) {
		_menu[_numOfGames] = t;
		_numOfGames++;
	}
	initGameTabs(_gamesUI);
}
			
void MenuUIEl::setNormal()
{
	_sprite.setColor(sfColor(255, 255, 255, 255));
}
void MenuUIEl::setShadow() {
	_sprite.setColor(sfColor(255, 255, 255, 128));
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
			if (_menuEvent.type == sfEvent::KeyPressed) {
				if (_menuEvent.key.code == sfKeyboard::Escape) {
					window.close();
				}
				if (_menuEvent.key.code == sfKeyboard::Left)
				{
					_selected = (_selected + 1) % 3;
					for (auto& uiEl : _gamesUI) {
						uiEl->setNormal();
					}
					_gamesUI[_selected]->setShadow();
				}
				if (_menuEvent.key.code == sfKeyboard::Right)
				{
					_selected =  _selected==0 ? 2 : _selected-1;
					for (auto& uiEl : _gamesUI) {
						uiEl->setNormal();
					}
					_gamesUI[_selected]->setShadow();
				}
			}
		}
		window.clear(sfColor::White);
		_logo.setScale(1.5, 1.5);
		// Centering Logo
		_logo.setPosition((window.getSize().x - _logo.getSprite().getTexture()->getSize().x)/3, 0);
		window.draw(_logo.getSprite());
		_gamesUI[0]->setScale(0.5,0.5);
		_gamesUI[0]->setPosition(100, window.getSize().y-(_gamesUI[0]->getSprite().getTexture()->getSize().y));
		_gamesUI[2]->setScale(0.3, 0.3);
		_gamesUI[2]->setPosition(_gamesUI[0]->getSprite().getPosition().x+600, window.getSize().y - _gamesUI[2]->getSprite().getTexture()->getSize().y/2 - 100);
		_gamesUI[1]->setScale(0.15, 0.15);
		_gamesUI[1]->setPosition(_gamesUI[0]->getSprite().getPosition().x + 1100, window.getSize().y - 550);
		window.draw(_gamesUI[0]->getSprite());
		window.draw(_gamesUI[2]->getSprite());
		window.draw(_gamesUI[1]->getSprite());
		window.display();
	}
}