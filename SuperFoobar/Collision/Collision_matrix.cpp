#include "Collision_matrix.h"
#include "Cluster.h"
#include "../Character filer/Foobar/Foobar.h"
#include <memory>
#include <iostream>
using namespace std;

Collision_matrix::Collision_matrix(int rows, int cols)
	:matrix(rows, vector<shared_ptr<Map_object>>(cols, nullptr))
	{}
	//matrix = vector < vector <shared_ptr<Cluster>> >(rows, vector<shared_ptr<Cluster>>(cols, false));


shared_ptr<Map_object> Collision_matrix::get_element(int row, int col) {
		return matrix.at(row).at(col);
}

void Collision_matrix::true_element(int row, int col, shared_ptr<Map_object> to_fill) {
	matrix.at(row).at(col) = to_fill;
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
