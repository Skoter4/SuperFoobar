#pragma once
#include <memory>
#include "../Collision/Cluster.h"

class Interactable
{
public:
	bool is_dead(); // Returns the bool dead
	void interact(); // Sets dead = true (works as a flag)
	void flip_dead(); // Flips the bool dead
	float get_width();
	float get_length();
	~Interactable() = default;
protected:
	Interactable(float, float, float, float); // x_pos, y_pos, height, width
	std::unique_ptr<Cluster> position;
	float width{};
	float length{};
	bool dead{ false };
};

