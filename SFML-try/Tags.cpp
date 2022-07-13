#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TypeDefs.h"


int main()
{
	sfRenderWindow window(sfVideoMode(256, 256), "Tags!");
	
	while (window.isOpen())
	{
		sfEvent ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sfEvent::Closed) {
				window.close();
			}
		}
		window.clear(sfColor::White);
		window.display();
	}

	return 0;
}