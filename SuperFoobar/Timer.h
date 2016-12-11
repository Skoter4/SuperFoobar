#pragma once
#include "SFML/Graphics.hpp"

class Timer {
public:
	Timer() = default;
	~Timer() = default;
	float get_time_remaining();
	void set_time_remaining(float);
	void countdown();

protected:
	float time_remaining{ 600.0f };
	float temp_counter{ 0.0f };
	sf::Clock clock;
};