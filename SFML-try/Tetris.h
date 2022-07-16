#include "SFML_LIBS.h"
#include <time.h>
#include <algorithm>
#include <iostream>
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
}a[4], b[4];

bool check()
{
	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M ) return false;
		else if (field[a[i].y][a[i].x]) return false;
	}
	return true;
}
bool lost() {
	for (int i = 0; i < N; i++) {
		if (field[0][i]) return true;
	}
	return false;
}



int Tetris()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");
	sf::Texture texture,texture_background,texture_frame,texture_lose;
	texture.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\tiles.png");
	texture_background.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\background.png");
	texture_frame.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\frame.png");
	texture_lose.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\images-tetris\\gameover.png");
	sf::Sprite sprite(texture), sprite_background(texture_background), sprite_frame(texture_frame),sprite_lose(texture_lose);
	sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));
	int dx = 0;
	bool rotate = false;
	int colorNum = 1;
	bool beginGame = true;
	int n = rand() % 7;
	float timer = 0, delay = 0.3;
	sf::Clock _clock;
	while(window.isOpen())
	{
		float time = _clock.getElapsedTime().asSeconds();
		_clock.restart();
		timer += time;
		sf::Event _ev;
		while (window.pollEvent(_ev))
		{
			if (_ev.type == sf::Event::Closed)
				window.close();

			if (_ev.type == sf::Event::KeyPressed)
			{
				if (_ev.key.code == sf::Keyboard::Up) rotate = true;
				else if (_ev.key.code == sf::Keyboard::Left) dx = -1;
				else if (_ev.key.code == sf::Keyboard::Right) dx = 1;
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) delay = 0.05;
		/* need fixes for random start */
		/*
		for (int i = 0; i < 4; i++) {
			if (a[i].y == 0) {
				int r = rand() % 17;
				auto func = [r](const auto& a) {
					return (a.x + r) > N;
				};
				while (std::find_if(a, a + 4, func) != (a + 4)) {
					r = rand() % 17;
				}
				for (int i = 0; i < 4; i++) {
					b[i] = a[i];
					a[i].x += r;
				}
			}
		}
		*/
	
		for (int i = 0; i < 4; i++)
			{
				b[i] = a[i];
				a[i].x += dx;
			}
		if (lost()) {
			// need to be refactored
			sprite_lose.setScale(0.2, 0.2);
			window.draw(sprite_lose);
			while (window.pollEvent(_ev)) {
				if (_ev.type == sf::Event::KeyPressed) {
					return 0;
				}
				window.display();
			}
			std::cout << "You lose!";
			return 0;
		}
			if (!check())
			{
				for (int i = 0; i < 4; i++)
					a[i] = b[i];
			}

			if (rotate)
			{
				Point p = a[1];
				for (int i = 0; i < 4; i++)
				{
					int x = a[i].y - p.y;
					int y = a[i].x - p.x;
					a[i].x = p.x - x;
					a[i].y = p.y + y;
				}
				if (!check()) {
					for (int i = 0; i < 4; i++)
					{
						a[i] = b[i];
					}
				}
			}
			if (timer > delay)
			{
				for (int i = 0; i < 4; i++)
				{
					b[i] = a[i];
					a[i].y += 1;
				}
				if (!check())
				{
					for (int i = 0; i < 4; i++) {
						field[b[i].y][b[i].x] = colorNum;
					}
					colorNum = 1 + rand() % 7;
					int n = rand() % 7;
					for (int i = 0; i < 4; i++)
					{
						a[i].x = figures[n][i] % 2;
						a[i].y = figures[n][i] / 2;
					}
				}
				timer = 0;
		
			}

		int k = M - 1;
		for (int i = M - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < N) k--;
		}

		if (beginGame)
		{
			beginGame = false;
			n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}

		dx = 0;
		rotate = false;
		delay = 0.3;
		window.clear(sf::Color::White);
		window.draw(sprite_background);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 0) continue;
				sprite.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
				sprite.setPosition(j * 18, i * 18);
				sprite.move(28, 31);
				window.draw(sprite);
			}
		}
		bool isSet = false;
		for (int i = 0; i < 4; i++)
		{
			if (a[i].y == 0 && !isSet) {
				int r = rand() % N;
				isSet = true;
				for (int i = 0; i < 4; i++) {
					a[i].x = (a[i].x + (r)) % N;
				}
				break;

			}
		}
		for (int i = 0; i < 4; i++)
		{
			sprite.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));

			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			sprite.move(28, 31);
			window.draw(sprite);
		}

		window.draw(sprite_frame);
		window.display();
		for (int i = 0; i < 4; i++) {
			if (a[i].y == 0) isSet = false;
		}
	}

	return 0;
}