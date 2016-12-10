#pragma once
//#ifndef CLUSTER_H
//#define CLUSTER_H
//#include "../Collision/Cluster.h"
#include "../Block-filer/Block.h"
#include "../Map_object.h"
#include <memory>
#include <utility>

//class Cluster;

class Character : public Map_object{
public:
	Character() = default;
	~Character() = default;
	void move_x(int);
	void move_y(int);

	void die();
	void flip_invulnerable();
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


protected:
	Character(int, int, int, int);

	int lifes{ 1 };
	
	bool invulnerable{ false };
	bool active{ true };
	
	int gravity{ 1 };

	struct Velocity {
		int x_velocity{};
		int y_velocity{};
	};

	Velocity velocity{};

};
//#endif



