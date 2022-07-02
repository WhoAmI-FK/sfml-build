#include <SFML/Graphics.hpp>

int spriting()
{
	sf::RenderWindow window(sf::VideoMode(1920, 900), "Sprites");
	
	while (window.isOpen()) {
		sf::Event _ev;
		while (window.pollEvent(_ev))
		{
			if (_ev.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		sf::Texture texture;
		texture.loadFromFile("C:\\Users\\User\\source\\repos\\sfml-try\\SFML-try\\sprite.png");
		texture.setSmooth(true);
		texture.setRepeated(true);
		//sf::Sprite _spr(texture);
		sf::Sprite sprite1(texture);
		sf::Sprite sprite2(texture);
		sf::Sprite sprite3(texture);
		sf::Sprite sprite4(texture);
		sf::Sprite sprite5(texture);
		sf::Sprite sprite6(texture);
		sf::Sprite sprite7(texture);
		using sf::Color;
		sprite2.move(105, 0);
		// ”станавливаем ему цвет - зеленый
		sprite2.setColor(Color::Green);

		// —двигаем третий спрайт вправо на 210 пикселей
		sprite3.move(210, 0);
		// ”станавливаем ему цвет - красный
		sprite3.setColor(Color::Red);

		// —двигаем четвертый спрайт вправо на 315 пикселей
		sprite4.move(315, 0);
		// ”станавливаем ему цвет - желтый
		sprite4.setColor(Color::Yellow);

		// —двигаем п€тый спрайт вправо на 420 пикселей
		sprite5.move(420, 0);
		// ”станавливаем ему цвет Ц белый + прозрачность 128
		sprite5.setColor(Color(255, 255, 255, 128));

		// —двигаем шестой спрайт вправо на 525 пикселей
		sprite6.move(525, 0);
		// ”станавливаем ему цвет Ц белый + прозрачность 64
		sprite6.setColor(Color(255, 255, 255, 64));

		// —двигаем седьмой спрайт вправо на 630 пикселей
		sprite7.move(630, 0);
		// ”станавливаем ему цвет Ц белый + прозрачность 32
		sprite7.setColor(Color(255, 255, 255, 32));

		// ќтрисовка всех спрайтов	
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);

		// ќтрисовка окна
		window.display();

		window.display();
	}


	return 0;
}
