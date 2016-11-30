#pragma once
#include "../Collision/Cluster.h"

#include <memory>
#include <utility>

class Character
{
public:
	Character();
	virtual ~Character() = default;
	Character(int, int, int, int)
		: position {new Cluster(x_pos, y_pos, height, width) } {}
	void move_x(int);
	void move_y(int);
	int get_x_pos();
	int get_y_pos();
	void set_x_pos(int);
	void set_y_pos(int);

	void die();


protected:
	std::unique_ptr<Cluster> position{};
	float height{};
	float width{};
	float x_pos{};
	float y_pos{};


	struct Velocity {
		float x_velocity{};
		float y_velocity{};
	};

	Velocity velocity{};

};




