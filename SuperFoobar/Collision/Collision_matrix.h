#pragma once
#include <vector>
class Collision_matrix {

public:
	Collision_matrix(int rows, int cols);
	Collision_matrix() = default;
	bool get_element(int row, int col);
	void false_element(int row, int col);
	void true_element(int row, int col);
private:
	std::vector< std::vector<bool> > matrix;
};
