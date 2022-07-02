#include <SFML/Graphics.hpp>

int fig()
{
	sf::RenderWindow window(sf::VideoMode(500, 200), "GMF");
	while (window.isOpen())
	{
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				window.close();
		}
		typedef sf::Color sfC;
		window.clear(sfC(250, 220, 100, 0));
		sf::CircleShape circle(50.f);
		circle.setFillColor(sfC(230, 0, 230));
		circle.setOutlineThickness(15.f);
		circle.setOutlineColor(sfC(80, 220, 50));
		circle.move(15, 15);
		window.draw(circle);

		sf::CircleShape triangle(65.f, 3);
		triangle.setPosition(125, 0);
		triangle.setFillColor(sfC::Blue);
		window.draw(triangle);

		sf::CircleShape square(60.f, 4);
		square.setPosition(250, 0);
		square.setFillColor(sfC::Red);
		window.draw(square);

		sf::CircleShape octagon(60.f, 8);
		octagon.setPosition(380, 0);
		octagon.setFillColor(sfC::Cyan);
		window.draw(octagon);
		window.display();
	}
	return 0;
}