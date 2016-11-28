#include "Collision_matrix.h"
#include <iostream>
using namespace std;

Collision_matrix::Collision_matrix(int rows, int cols) {
  matrix = vector < vector <bool> > (rows, vector<bool>(cols, false));
}



bool Collision_matrix::get_element(int row, int col) {
  return matrix.at(row).at(col);
}

void Collision_matrix::true_element(int row, int col) {
  matrix.at(row).at(col) = true;
}

void Collision_matrix::false_element(int row, int col) {
  matrix.at(row).at(col) = false;
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
