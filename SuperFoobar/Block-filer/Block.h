#pragma once
#include <utility>
#include <string>
#include <memory>
#include "../Collision/Cluster.h"
#include "../Map_object.h"
//#ifndef CLUSTER_H
//#define CLUSTER_H

//class Cluster;

class Block :public Map_object{
public:

	~Block() = default;
	Block() = default;

	virtual void interact() = 0;
	virtual bool interact_type(std::shared_ptr<Map_object>) = 0;

	int get_x_pos();
	int get_y_pos();
	void set_x_pos(int);
	void set_y_pos(int);
	int area();
	void flip_dead();
	std::shared_ptr<Cluster> get_cluster() override;

protected:
	Block(int, int, int, int); // Block-position and area is defined in its contructor.
	std::string block_color{};
	bool block_outline{};
	bool dead{ false };
};
//#endif // !CLUSTER_H