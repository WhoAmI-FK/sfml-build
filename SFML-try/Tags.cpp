#include "Tags.h"

void Tags()
{
	sfRenderWindow window(sfVideoMode(256, 256), "Tags!");
	sfTexture texture;
	sfSound sPlayer;

	std::pair<sfSBuffer, std::shared_ptr<sfSound>> move;
	move.first.loadFromFile("sounds-tags\\ogg\\move.ogg");
	move.second = std::make_shared<sfSound>(sPlayer);
	window.setFramerateLimit(60);
	texture.loadFromFile("images-tags/15.png");

	int blockWidth = 64;

	int grid[6][6] = { 0 };

	sfSprite sprite[17];
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(sfIntRect(i * blockWidth, j * blockWidth, blockWidth, blockWidth));
			grid[i + 1][j + 1] = n;
		}
	}

	while (window.isOpen())
	{
		sfEvent ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sfEvent::Closed) {
				window.close();
			}

			if (ev.type == sfEvent::MouseButtonPressed)
			{
				if (ev.key.code == sfMouse::Left)
				{
					move.second.get()->setBuffer(move.first);
					move.second.get()->play();
					sfVector2i position = sfMouse::getPosition(window);
					int x = position.x / blockWidth + 1;
					int y = position.y / blockWidth + 1;

					int dx = 0;
					int dy = 0;

					if (grid[x + 1][y] == 16) {
						dx = 1;
						dy = 0;
					}
					if (grid[x][y + 1] == 16) {
						dx = 0;
						dy = 1;
					}
					if (grid[x][y - 1] == 16)
					{
						dx = 0;
						dy = -1;
					}
					if (grid[x - 1][y] == 16)
					{
						dx = -1;
						dy = 0;
					}
					int temp = grid[x][y];
					grid[x][y] = 16;
					grid[x + dx][y + dy] = temp;
					sprite[16].move(-dx * blockWidth, -dy * blockWidth);
					float speed = 6;

					for (int i = 0; i < blockWidth; i += speed)
					{
						sprite[temp].move(speed * dx, speed * dy);
						window.draw(sprite[16]);
						window.draw(sprite[temp]);
						window.display();
					}
				}
			}
		}
		window.clear(sfColor::White);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				int n = grid[i + 1][j + 1];
				sprite[n].setPosition(i * blockWidth, j * blockWidth);
				window.draw(sprite[n]);
			}
		}
		window.display();

	}

}