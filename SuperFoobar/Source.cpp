#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(450, 900), "SFML");

	sf::Event event;

		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
				{
					window.close();
				}
			}
		}
	
	return 0;
}