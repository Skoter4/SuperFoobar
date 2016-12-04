#pragma once
#include <vector>
#include <memory>
#include "../Map_object.h"
class Collision_matrix {

public:
	Collision_matrix(int rows, int cols);
	Collision_matrix() = default;
	std::shared_ptr<Map_object> get_element(int row, int col);
	void false_element(int row, int col);
	void true_element(int row, int col, std::shared_ptr<Map_object> to_fill);
private:
	std::vector< std::vector<std::shared_ptr<Map_object>> > matrix;
};
