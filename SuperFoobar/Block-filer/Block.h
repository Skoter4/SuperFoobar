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
	virtual bool interact_with(std::shared_ptr<Map_object>) = 0;

	int area();
	bool get_active();
	void flip_active();

protected:
	Block(int, int, int, int); // Block-position and area is defined in its contructor.
	std::string block_color{};
	bool block_outline{};
	bool active{ true };
};
//#endif // !CLUSTER_H