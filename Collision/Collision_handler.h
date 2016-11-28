#pragma once

#include "Cluster.h"
#include "Collision_matrix.h"



class Collision_handler{

public:

	Collision_handler(int rows, int cols);
	void move_event(Cluster moving);
	void fill_cluster(Cluster to_fill);
	void remove_cluster(Cluster to_remove);

private:
	Collision_matrix matrix;
};
