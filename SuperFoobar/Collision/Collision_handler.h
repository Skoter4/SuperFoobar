#pragma once

#include "Cluster.h"
#include "Collision_matrix.h"
#include <unordered_map>

class Collision_handler{

public:

	Collision_handler(int rows, int cols);
	bool move_event(std::shared_ptr<Cluster> moving);
	void fill_cluster(std::shared_ptr<Cluster> to_fill);
	void remove_cluster(std::shared_ptr<Cluster> to_remove);

private:
	Collision_matrix matrix;
};
