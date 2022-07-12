#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <utility>
#include <ctime>


/* Required fixes
*  1. add new features
*  2. Code Refactor
*/

typedef sf::SoundBuffer sfSBuffer;
typedef sf::Sound sfSound;
typedef sf::Texture sfTexture;
typedef sf::Sprite sfSprite;
typedef sf::Event sfEvent;
typedef sf::Color sfColor;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	sf::RenderWindow app(sf::VideoMode(400, 400), "Minesweeper!");
	int w = 32;
	int gridLogic[12][12];
	int gridView[12][12];
	bool selected = false;
	bool end_game = false;
	sfSound sPlayer;
	// soundefx
	std::pair <sfSBuffer, std::shared_ptr<sfSound>> gameBegin;
	std::pair <sfSBuffer, std::shared_ptr<sfSound>> fieldClicked;
	std::pair <sfSBuffer, std::shared_ptr<sfSound>> bombExplosion;
	bombExplosion.first.loadFromFile("sounds-minesweeper\\ogg\\explosion.ogg");
	bombExplosion.second = std::make_shared<sfSound>(sPlayer);
	fieldClicked.first.loadFromFile("sounds-minesweeper\\ogg\\fieldclicked.ogg");
	fieldClicked.second = std::make_shared<sfSound>(sPlayer);
	gameBegin.first.loadFromFile("sounds-minesweeper\\ogg\\game-start.ogg");
	gameBegin.second = std::make_shared<sfSound>(sPlayer);
	gameBegin.second.get()->setBuffer(gameBegin.first);
	gameBegin.second.get()->play();
	// soundefx
	int mines_found = 0;
	int mines = 0;

	sfTexture t;
	t.loadFromFile("images-minesweeper/tiles.jpg");
	sfSprite s(t);


	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
			if (rand() % 5 == 0) gridLogic[i][j] = 9;
			else gridLogic[i][j] = 0;
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;
			if (gridLogic[i][j] == 9) continue;
			if (gridLogic[i + 1][j] == 9) n++;
			if (gridLogic[i][j + 1] == 9)n++;
			if (gridLogic[i-1][j] == 9) n++;
			if (gridLogic[i][j - 1] == 9)n++;
			if (gridLogic[i + 1][j + 1] == 9) n++;
			if (gridLogic[i - 1][j - 1] == 9) n++;
			if (gridLogic[i - 1][j + 1] == 9) n++;
			if (gridLogic[i + 1][j - 1] == 9) n++;
			gridLogic[i][j] = n;
		}
	}

	while (app.isOpen())
	{
		sf::Vector2i pos = sf::Mouse::getPosition(app);
		int x = pos.x / w;
		int y = pos.y / w;
		if (x < 0) x = 0;

		if (y < 0) y = 0;
		sfEvent e;
		while (app.pollEvent(e))
		{
			if (e.type == sfEvent::Closed)
				app.close();

			if (e.type == sfEvent::MouseButtonPressed)
			{
				fieldClicked.second.get()->setBuffer(fieldClicked.first);
				fieldClicked.second.get()->play();
				if (e.key.code == sf::Mouse::Left) {
					gridView[x][y] = gridLogic[x][y];
					selected = true;
				}
				else if (e.key.code == sf::Mouse::Right) gridView[x][y] = 11;
			}
		}
		if (selected == true)
		{
			if (e.key.code == sf::Mouse::Left && gridLogic[x][y] == 9)
			{
				bombExplosion.second.get()->setBuffer(bombExplosion.first);
				bombExplosion.second.get()->play();
			}
		}

		app.clear(sfColor::White);
		for(int i = 1;i<=10;i++)
			for (int j = 1; j <= 10; j++)
			{
				if(gridView[x][y]==9) gridView[i][j] = gridLogic[i][j];
				s.setTextureRect(sf::IntRect(gridView[i][j] * w, 0, w, w));
				s.setPosition(i * w, j * w);
				app.draw(s);
			}

		selected = false;
		app.display();
	}


	return 0;
}