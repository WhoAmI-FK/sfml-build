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
		// ������������� ��� ���� - �������
		sprite2.setColor(Color::Green);

		// �������� ������ ������ ������ �� 210 ��������
		sprite3.move(210, 0);
		// ������������� ��� ���� - �������
		sprite3.setColor(Color::Red);

		// �������� ��������� ������ ������ �� 315 ��������
		sprite4.move(315, 0);
		// ������������� ��� ���� - ������
		sprite4.setColor(Color::Yellow);

		// �������� ����� ������ ������ �� 420 ��������
		sprite5.move(420, 0);
		// ������������� ��� ���� � ����� + ������������ 128
		sprite5.setColor(Color(255, 255, 255, 128));

		// �������� ������ ������ ������ �� 525 ��������
		sprite6.move(525, 0);
		// ������������� ��� ���� � ����� + ������������ 64
		sprite6.setColor(Color(255, 255, 255, 64));

		// �������� ������� ������ ������ �� 630 ��������
		sprite7.move(630, 0);
		// ������������� ��� ���� � ����� + ������������ 32
		sprite7.setColor(Color(255, 255, 255, 32));

		// ��������� ���� ��������	
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);

		// ��������� ����
		window.display();

		window.display();
	}


	return 0;
}
