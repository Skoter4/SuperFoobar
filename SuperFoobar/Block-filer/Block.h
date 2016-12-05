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

	int area();
	void flip_dead();

protected:
	Block(int, int, int, int); // Block-position and area is defined in its contructor.
	std::string block_color{};
	bool block_outline{};
	bool dead{ false };
};
//#endif // !CLUSTER_H