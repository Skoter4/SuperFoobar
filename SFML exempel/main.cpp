#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1024, 592), "SFML Works", sf::Style::Default, settings);

	sf::RectangleShape Rect(sf::Vector2f(256.0f, 70.0f));
	Rect.setFillColor(sf::Color::Yellow);
	Rect.setPosition(0.0f, 522.0f);
	sf::RectangleShape Rect2(sf::Vector2f(256.0f, 70.0f));
	Rect2.setFillColor(sf::Color::Yellow);
	Rect2.setPosition(256.0f, 522.0f);
	sf::RectangleShape Rect3(sf::Vector2f(256.0f, 70.0f));
	Rect3.setFillColor(sf::Color::Yellow);
	Rect3.setPosition(512.0f, 522.0f);
	sf::RectangleShape Rect4(sf::Vector2f(256.0f, 70.0f));
	Rect4.setFillColor(sf::Color::Yellow);
	Rect4.setPosition(768.0f, 522.0f);
	sf::RectangleShape Rect5(sf::Vector2f(256.0f, 70.0f));
	Rect5.setFillColor(sf::Color::Yellow);
	Rect5.setPosition(512.0f, 350.0f);
	sf::Clock clock;


	sf::CircleShape ball(30);
	ball.setFillColor(sf::Color::Black);
	ball.setPosition(512.0f, 296.0f);

	std::list<sf::RectangleShape> list{Rect,Rect2,Rect3,Rect4, Rect5};

	sf::Texture texture;
	texture.loadFromFile("images/background.png");

	sf::Sprite sprite(texture);

	sf::Event event;

	float gravity{ 2.0f };

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				ball.setPosition(ball.getPosition() + sf::Vector2f(5.0f, 0.0f));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				ball.setPosition(ball.getPosition() + sf::Vector2f(-5.0f, 0.0f));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (gravity > 0)
				{
					gravity = -gravity;
				}	
			}
			else
			{
				gravity = 2.0f;
			}
		}

		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (gravity > 0.0f)
			{
				if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x <= it->getPosition().x + 256.0f)
				{
					ball.setPosition(ball.getPosition().x, ball.getPosition().y + gravity);
					if (ball.getPosition().y + 60 > it->getPosition().y)
					{
						ball.setPosition(ball.getPosition().x, it->getPosition().y - 60.0f);
					}
				}
			}
			else
			{
				if (ball.getPosition().y > 120)
				{
					if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x <= it->getPosition().x + 256.0f)
					{
						ball.setPosition(ball.getPosition().x, ball.getPosition().y + gravity);
					}
				}
				else
				{
					gravity = -gravity;
				}

			}
		}
	
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x <= it->getPosition().x + 256.0f)
			{
				if (ball.getPosition().y + 60 == it->getPosition().y)
				{
					while (ball.getPosition().y + 60 < it->getPosition().y)
					{
						ball.setPosition(ball.getPosition().x, ball.getPosition().y + gravity);

						if (ball.getPosition().y + 60 > it->getPosition().y)
						{
							ball.setPosition(ball.getPosition().x, it->getPosition().y - 60.0f);
						}
						break;
					}
				}
			}
		}

		std::cout << "Elapsed time in microsecond: "
			<< clock.getElapsedTime().asMicroseconds() << std::endl;

		window.clear();
		window.draw(sprite);
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			window.draw(*it);
		}
		window.draw(ball);
		window.display();

	}

	
}