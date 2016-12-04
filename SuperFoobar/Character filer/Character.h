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
	virtual ~Character() = default;
	void move_x(int);
	void move_y(int);
	int get_x_pos();
	int get_y_pos();
	void set_x_pos(int);
	void set_y_pos(int);
	void set_height(int);
	void set_width(int);
	std::shared_ptr<Cluster> get_cluster() override;

	void flip_dead();
	void die();
	void flip_invulnerable();


protected:
	Character(int, int, int, int);
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
//#endif



