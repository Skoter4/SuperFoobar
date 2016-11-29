#include "SFML/Graphics.hpp"
#include <iostream> //std::cout
#include <string> //std::to_string
#include <vector> //std::static_cast

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML");

	// Load font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error loading from file" << std::endl;
	}

	// Score, top-left corner
	float score{ 0.0f };
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString(std::to_string(static_cast<int>(score))); // Conversion to int to get rid of decimals
	scoreText.setPosition(15, 5);
	scoreText.setCharacterSize(50); // Default = 30
	scoreText.setColor(sf::Color::White); // Default = White

	// Timer, top-right corner
	float time_remaining{ 600.0f };
	float timer{}; // Used to count down
	sf::Text timerText;
	timerText.setFont(font);
	timerText.setString(std::to_string(static_cast<int>(time_remaining)));
	timerText.setPosition(1500, 5);
	timerText.setCharacterSize(50);
	timerText.setColor(sf::Color::White);
	sf::Clock clock; // Starts the clock

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Timer countdown
		if (time_remaining > 0.0f) {
			timer = clock.getElapsedTime().asSeconds();
			time_remaining = time_remaining - timer;
			timerText.setString(std::to_string(static_cast<int>(time_remaining)));
			clock.restart();
		}
		else {
			// Gamer over. End the game, add time_remaining to score, save if top 10
		}

		window.clear(sf::Color::Black);
		window.draw(timerText);
		window.draw(scoreText);
		window.display();
	}

	return 0;
}