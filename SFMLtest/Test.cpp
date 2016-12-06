#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
/*
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1024, 592), "SFML Works", sf::Style::Default, settings);

	sf::RectangleShape Rect(sf::Vector2f(1024.0f, 70.0f));
	Rect.setFillColor(sf::Color::Yellow);
	Rect.setPosition(0.0f, 522.0f);
	sf::RectangleShape Rect2(sf::Vector2f(1024.0f, 70.0f));
	Rect2.setFillColor(sf::Color::Yellow);
	Rect2.setPosition(1024.0f, 522.0f);
	sf::RectangleShape Rect3(sf::Vector2f(1024.0f, 70.0f));
	Rect3.setFillColor(sf::Color::Yellow);
	Rect3.setPosition(2048.0f, 522.0f);
	sf::RectangleShape Rect4(sf::Vector2f(1024.0f, 70.0f));
	Rect4.setFillColor(sf::Color::Yellow);
	Rect4.setPosition(3072.0f, 522.0f);
	sf::Clock clock;


	sf::CircleShape ball(30);
	ball.setFillColor(sf::Color::Black);
	ball.setPosition(512.0f, 296.0f);

	std::list<sf::RectangleShape> list{ Rect,Rect2,Rect3,Rect4 };

	sf::Texture texture;
	texture.setRepeated(true);
	texture.loadFromFile("Images/Background.png");
	

	sf::Sprite sprite(texture);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 4096, 592));

	sf::Event event;

	float y_speed{ 0.0f };
	float x_speed{ 0.0f };
	float gravity{ 0.05f };

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					if (ball.getPosition().x <= 100.0f)
					{
						x_speed = 0.0f;
					}
					else
					{
						x_speed = -1.0f;
					}
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					x_speed = 1.0f;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					for (auto it = list.begin(); it != list.end(); ++it)
					{
						if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f))
						{
							if (ball.getPosition().y + 60.0f == it->getPosition().y)
							{
								y_speed = -2.0f;
								gravity = 0.01f;
							}
							else

								if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f) && y_speed >= 0.0f)
								{
									gravity = 0.05f;
								}
						}
					}
				}
			

			}

			if (event.type == sf::Event::KeyReleased)
			{
			if (event.key.code == sf::Keyboard::Up)
				{
					for (auto it = list.begin(); it != list.end(); ++it)
					{
						if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f))
						{
							while (ball.getPosition().y + 60.0f < it->getPosition().y)
							{
								gravity = 0.05f;
								break;
							}
						}
					}
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					x_speed = 0.0f;
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					x_speed = 0.0f;
				}
			}
		}

		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f) && y_speed > 0.0f)
			{
				while (ball.getPosition().y + 60.0f < it->getPosition().y)
				{
					ball.setPosition(ball.getPosition() + sf::Vector2f(x_speed, y_speed));
					break;
				}
				if (ball.getPosition().y + 60.0f >= it->getPosition().y)
				{
					ball.setPosition(sf::Vector2f(ball.getPosition().x + x_speed, it->getPosition().y - 60.0f));
				}
			}
			else
				if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f) && y_speed <= 0.0f)
				{
					ball.setPosition(ball.getPosition() + sf::Vector2f(x_speed, y_speed));
				}
		}

		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (ball.getPosition().x >= it->getPosition().x && ball.getPosition().x < (it->getPosition().x + 1024.0f))
			{
				while (ball.getPosition().y + 60.0f < it->getPosition().y && y_speed < 2.0f)
				{
					y_speed += gravity;
					break;
				}
			}
		}

		int camera_x = static_cast<int>(ball.getPosition().x);
		int camera_y = static_cast<int>(296.0f);
		int ball_y = static_cast<int>(ball.getPosition().y);

		sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
			std::cout << "Error" << std::endl;
		}

		sf::Text text;
		text.setFont(font);
		text.setString("X: " + std::to_string(camera_x) + " Y: " + std::to_string(ball_y));
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setPosition(camera_x, 100);
		//text.setColor(sf::Color::Red);

		if (ball.getPosition().x > 512.0f)
		{ 
			sf::View view(sf::FloatRect(camera_x - 512, 0, 1024, 592));
			window.setView(view);
		}
		else
		{
			sf::View view(sf::FloatRect(0, 0, 1024, 592));
			window.setView(view);
		}

		std::cout << "Elapsed time in microsecond: "
			<< clock.getElapsedTime().asMicroseconds() << std::endl;

		window.clear();
		window.draw(sprite);
		window.draw(text);

		for (auto it = list.begin(); it != list.end(); ++it)
		{
			window.draw(*it);
		}
		window.draw(ball);
		window.display();

	}


}*/