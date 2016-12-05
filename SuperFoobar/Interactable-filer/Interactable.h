#pragma once
#include <memory>
#include "../Collision/Cluster.h"

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
	Interactable(int, int, int, int); // x_pos, y_pos, height, width
	std::unique_ptr<Cluster> position;
	int width{};
	int length{};
	bool dead{ false };
};

