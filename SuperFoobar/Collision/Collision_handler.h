#pragma once

#include "Cluster.h"
#include "Collision_matrix.h"

class Collision_handler{

public:

	Collision_handler(int rows, int cols);
	void move_event(std::shared_ptr<Map_object> & moving);
	void fill_cluster(std::shared_ptr<Map_object> & to_fill);
	void remove_cluster(std::shared_ptr<Map_object> to_remove);
	void update_position(std::shared_ptr<Map_object> to_update);
	void create_list();
	void check_list(std::shared_ptr<Map_object> to_check);
	bool check_collision(std::shared_ptr<Map_object> to_check, std::shared_ptr<Map_object> reference);

private:
	Collision_matrix matrix{};
	std::vector<std::shared_ptr<Map_object>> object_list;
};
