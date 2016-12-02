#pragma once
#include "../Collision/Cluster.h"

#include <memory>
#include <utility>

class Character
{
public:
	~Character() = default;
	Character(float, float, float, float)
		: position {new Cluster(x_pos, y_pos, height, width) } {}
	void move_x(float);
	void move_y(float);
	float get_x_pos();
	float get_y_pos();
	void set_x_pos(float);
	void set_y_pos(float);
	void set_width(float);
	void set_height(float);

	void flip_dead();
	void die();
	void flip_invulnerable();


protected:
	std::unique_ptr<Cluster> position{};
	float height{};
	float width{};
	float x_pos{};
	float y_pos{};
	
	bool dead{ false };
	bool invulnerable{ false };

	struct Velocity {
		float x_velocity{};
		float y_velocity{};
	};

	Velocity velocity{};

};




