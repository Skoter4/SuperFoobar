#include "Collision_handler.h"
#include "Cluster.h"
#include "Collision_matrix.h"
#include <iostream>

using namespace std;

Collision_handler::Collision_handler(int rows, int cols){
  matrix = Collision_matrix(rows, cols); 
}

void Collision_handler::move_event(Cluster moving){ 
  for (int i = moving.begin_x(); i < moving.end_x(); i++){
    for (int j = moving.begin_y(); j < moving.end_y(); j++){
      if (matrix.get_element(i, j))
	cout << "Cant move here" << endl;
    }
  }
}

void Collision_handler::fill_cluster(Cluster to_fill){
  for (int i = to_fill.begin_x(); i < to_fill.end_x(); i++){
    cout << i << endl;
    for (int j = to_fill.begin_y(); j < to_fill.end_y(); j++){
      cout << j << endl;
      matrix.true_element(i,j);
    }
  }
}

void Collision_handler::remove_cluster(Cluster to_remove){
  for (int i = to_remove.begin_x(); i < to_remove.end_x(); i++){
    for (int j = to_remove.begin_y(); j < to_remove.end_y(); j++){
      matrix.true_element(i,j);
    }
  }
}

int main(){
  Cluster clust = Cluster(1, 1, 2, 2);
  clust.set_des_x(1);
  clust.set_des_y(1);
  Collision_handler col = Collision_handler(10,10);
  col.fill_cluster(clust);
  col.move_event(clust);
  return 0;
};
