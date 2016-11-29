#include "Collision_matrix.h"
#include "Cluster.h"
#include <memory>
#include <iostream>
using namespace std;

Collision_matrix::Collision_matrix(int rows, int cols) {
	matrix = vector < vector <shared_ptr<Cluster>> >(rows, vector<shared_ptr<Cluster>>(cols, false));
}



shared_ptr<Cluster> Collision_matrix::get_element(int row, int col) {
	if (matrix.at(row).at(col) == nullptr) {
		return nullptr;
	}
	else {
		return matrix.at(row).at(col);
	}
}

void Collision_matrix::true_element(int row, int col, shared_ptr<Cluster> to_fill) {
	shared_ptr<Cluster> my_ptr = to_fill;
	matrix.at(row).at(col) = my_ptr;
}

void Collision_matrix::false_element(int row, int col) {
	matrix.at(row).at(col) = nullptr;
}
/*
int main(){
  bool cool2 = false;
  Collision_matrix my_matrx = Collision_matrix(2,2);
  my_matrx.true_element(1,1);
  bool cool = my_matrx.get_element(1, 1);
  cout << cool << endl;
  cout << "Hmmm" << endl;
  return 0;
};
*/
