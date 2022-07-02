#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(320, 480), "The Game!");
	sf::Texture texture;
	texture.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\tiles.png");
	sf::Sprite sprite(texture);
	while (window.isOpen())
	{
		sf::Event _ev;
		while (window.pollEvent(_ev))
		{
			if (_ev.type == sf::Event::Closed) window.close();
		}
		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}

	return 0;
}