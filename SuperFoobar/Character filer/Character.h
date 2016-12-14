#pragma once
#include "../Map_object.h"
#include <memory>
#include <utility>


class Character : public Map_object{
public:
	Character() = default;
	~Character() = default;
	void move_x(int);
	void move_y(int);

	void die();
	void flip_active();
	void set_lifes(int);
	int get_lifes();

	void set_velocity(int, int);
	void set_x_velocity(int);
	void set_y_velocity(int);
	int get_x_velocity();
	int get_y_velocity();	
	int get_gravity();
	void set_gravity(int);
	
	void flip_x_velocity();

	void set_max_speed_x(int);
	int get_max_speed_x();
	void set_max_speed_y(int);
	int get_max_speed_y();
	bool get_on_ground();
	void flip_on_ground();

protected:
	Character(int, int, int, int);

	int lifes{ 1 };
	bool active{ true };
	
	int gravity{ 1 };

	int max_speed_x{ 5 };
	int max_speed_y{ 5 };

	bool on_ground{ false };

	struct Velocity {
		int x_velocity{3};
		int y_velocity{3};
	};

	Velocity velocity{};

};




