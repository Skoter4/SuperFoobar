#pragma once

#include "Cluster.h"
#include "Collision_matrix.h"

class Collision_handler{

public:

	Collision_handler(int rows, int cols);
	std::shared_ptr<Map_object> move_event(std::shared_ptr<Map_object> & moving);
	void fill_cluster(std::shared_ptr<Map_object> & to_fill);
	void remove_cluster(std::shared_ptr<Map_object> to_remove);

private:
	Collision_matrix matrix{};
};
