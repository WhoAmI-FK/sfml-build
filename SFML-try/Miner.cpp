#include <SFML/Graphics.hpp>
#include <time.h>

typedef sf::Texture sfTexture;
typedef sf::Sprite sfSprite;
typedef sf::Event sfEvent;
typedef sf::Color sfColor;
int main()
{
	sf::RenderWindow app(sf::VideoMode(400, 400), "Minesweeper!");
	int w = 32;
	int gridLogic[12][12];
	int gridView[12][12];

	sfTexture t;
	t.loadFromFile("images-minesweeper/tiles.jpg");
	sfSprite s(t);

	for(int i = 1;i<=10;i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
		}

	while (app.isOpen())
	{
		sfEvent e;
		while (app.pollEvent(e))
		{
			if (e.type == sfEvent::Closed)
				app.close();
		}
	
		app.clear(sfColor::White);
		for(int i = 1;i<=10;i++)
			for (int j = 1; j <= 10; j++)
			{
				s.setTextureRect(sf::IntRect(gridView[i][j] * w, 0, w, w));
				s.setPosition(i * w, j * w);
				app.draw(s);
			}
		app.display();
	}


	return 0;
}