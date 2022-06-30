#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "MiniGame", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::RectangleShape _player(sf::Vector2f(100.0f, 100.0f));
	_player.setFillColor(sf::Color::Blue);
	sf::Event _event;

	while (window.isOpen())
	{
		while (window.pollEvent(_event)) {
			switch (_event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New window width: " << _event.size.width << " New window height: " << _event.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (_event.text.unicode < 128)
				{
					printf("%c", _event.text.unicode);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			//if (_player.getPosition().x >100.0f);
			_player.move(-0.4f, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			//if (_player.getPosition().x < 412.0f);
			_player.move( 0.4f, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			//if (_player.getPosition().y > 0.0f);
			_player.move(0.0f, -0.4f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			//if (_player.getPosition().y < 412.0f);
			_player.move(0.0f, +0.4f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.clear();
			window.close();
		}
		window.clear();
		window.draw(_player);
		window.display();
	}

	return 0;
}