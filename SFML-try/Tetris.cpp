#include <SFML/Graphics.hpp>

const int M = 20;
const int N = 10;

int field[M][N] = { 0 };

int figures[7][4] =
{
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7,
	2,3,5,7,
	3,5,7,6,
	2,3,4,5,
};

struct Point
{
	int x, y;
}a[4],b[4];


int main()
{
	sf::RenderWindow window(sf::VideoMode(320, 480), "The Game!");
	sf::Texture texture;
	texture.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\tiles.png");
	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));
	int dx = 0;
	bool rotate = 0;
	float timer = 0, delay = 0.3;
	sf::Clock _clock;
	while(window.isOpen())
	{
		sf::Event _ev;
		while (window.pollEvent(_ev))
		{
			if (_ev.type == sf::Event::Closed) window.close();
		}
		int n = 3;
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}

		window.clear(sf::Color::White);
		for (int i = 0; i < 4; i++)
		{
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			window.draw(sprite);
		}
		window.display();
	}

	return 0;
}