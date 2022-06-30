#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>

/*
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "StrangeSmile");
	sf::CircleShape shape(100.f);
	float size = 100;
	int action = 0;
	shape.setFillColor(sf::Color::Green);
	shape.setPosition({ 100,100 });
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			std::chrono::time_point<std::chrono::system_clock> m_start_time = std::chrono::system_clock::now();
			std::chrono::time_point<std::chrono::system_clock> m_end_time = std::chrono::system_clock::now();
			while (std::chrono::duration_cast<std::chrono::milliseconds>(m_end_time-m_start_time).count()<10000)
			{
				if (size == 0) {
					action = 1;
				}
				switch (action)
				{
				case 0:
					size--;
					break;
				case 1:
					size++;
				}
				if (size == 100) {
					action = 0;
				}
				shape.setRadius(size);
				m_end_time = std::chrono::system_clock::now();
				window.clear();
				window.draw(shape);
				window.display();
			}
			window.close();
			std::cout << "FINISHED";
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}
*/