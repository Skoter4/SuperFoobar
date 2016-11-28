#pragma once
#include <memory>

class Interactable
{
public:
	bool is_dead(); // Returns the bool dead
	void interact(); // Sets dead = true (works as a flag)
	void flip_dead(); // Flips the bool dead
	int get_width();
	int get_length();
	~Interactable() = default;
protected:
	Interactable(int, int, int, int); // x_pos, y_pos, width, length
	std::unique_ptr<Position> position;
	int width{};
	int length{};
	bool dead{ false };
};

