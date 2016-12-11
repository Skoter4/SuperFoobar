#pragma once
//#ifndef CLUSTER_H
//#define CLUSTER_H
#include <memory>
//#include "../Collision/Cluster.h"
#include "../Block-filer/Block.h"
#include "../Map_object.h"

//class Cluster;

class Interactable : public Map_object
{
public:
	void interact(); // Sets dead = true (works as a flag)
	~Interactable() = default;
protected:
	Interactable(int, int, int, int); // x_pos, y_pos, height, width
	std::unique_ptr<Cluster> position;
};
//#endif
