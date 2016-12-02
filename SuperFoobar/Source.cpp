#include "SFML/Graphics.hpp"
#include <iostream> //std::cout
#include <string> //std::to_string
#include <vector> //std::static_cast
#include "Scoreboard.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML");

	// Load font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error loading from file" << std::endl;
	}

	// Score, top-left corner
	Score score;
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setPosition(15, 5);
	scoreText.setCharacterSize(50);
	scoreText.setString("0");

	// Timer, top-right corner
	Timer timer;
	sf::Text timerText;
	timerText.setFont(font);
	timerText.setPosition(1500, 5);
	timerText.setCharacterSize(50);

	Scoreboard scoreboard;

	bool gameover{ false }; // Hur ska game-over hanteras? Gjorde detta som en temporär lösning
	bool first_time{ true }; // Förhindrar att kvarvarande tid adderas till score flera gånger vid game-over

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (!gameover) {

			// Timer countdown
			if (timer.get_time_remaining() > 0.0f) {
				timer.countdown();
				timerText.setString(std::to_string(static_cast<int>(timer.get_time_remaining())));
			}
			else {
				gameover = true; // Timer hits 0 => game-over
			}

		}
		else if (first_time) {
			score.time_to_score(timer);
			scoreText.setString(std::to_string(static_cast<int>(score.get_score())));
			scoreboard.write(std::to_string(static_cast<int>(score.get_score())));
			first_time = false;
		}

		window.clear(sf::Color::Black);
		window.draw(timerText);
		window.draw(scoreText);
		window.display();
	}

	return 0;
}