#pragma once
#include "../Collision/Cluster.h"

#include <memory>
#include <utility>

class Character
{
public:
	~Character() = default;
	Character(int, int, int, int)
		: position {new Cluster(x_pos, y_pos, height, width) } {}
	void move_x(int);
	void move_y(int);
	int get_x_pos();
	int get_y_pos();
	void set_x_pos(int);
	void set_y_pos(int);
	void set_width(int);
	void set_height(int);

	void flip_dead();
	void die();
	void flip_invulnerable();


protected:
	std::unique_ptr<Cluster> position{};
	int height{};
	int width{};
	int x_pos{};
	int y_pos{};
	
	bool dead{ false };
	bool invulnerable{ false };

	struct Velocity {
		int x_velocity{};
		int y_velocity{};
	};

	Velocity velocity{};

};




