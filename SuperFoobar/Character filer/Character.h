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
	Character();
	~Character() = default;
	void move_x(int);
	void move_y(int);

	void flip_dead();
	void die();
	void flip_invulnerable();
	void flip_active();
	void set_lifes(int);
	int get_lifes();

protected:
	Character(int, int, int, int);

	int lifes{ 1 };
	
	bool dead{ false };
	bool invulnerable{ false };
	bool active{ true };
	

	struct Velocity {
		int x_velocity{};
		int y_velocity{};
	};

	Velocity velocity{};

};
//#endif



