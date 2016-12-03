#pragma once
#include "Collision_handler.h"
//#include "Cluster.h"
//#include "Collision_matrix.h"
#include "../Block-filer/Breakable.h"
#include "../Character filer/Foobar/Foobar.h" 
#include <iostream>
#include <memory>

using namespace std;

Collision_handler::Collision_handler(int rows, int cols) 
	:matrix{rows,cols} {
}

bool Collision_handler::move_event(shared_ptr<Cluster> moving){
  Cluster collided;
  for (int i = moving->begin_x(); i < moving->end_x(); i++){
    for (int j = moving->begin_y(); j < moving->end_y(); j++){
      if (matrix.get_element(i, j) != nullptr){
		cout << "Cant move here" << endl;
		collided = *matrix.get_element(i, j);
		return false;
	  }
	  else {
		  return true;
	  }
    }
  }
  return false;
}

void Collision_handler::fill_cluster(shared_ptr<Cluster> to_fill){
  for (int i = to_fill->begin_x(); i < to_fill->end_x(); i++){
    for (int j = to_fill->begin_y(); j < to_fill->end_y(); j++){
      matrix.true_element(i,j, to_fill);
    }
  }
}

void Collision_handler::remove_cluster(shared_ptr<Cluster> to_remove){
  for (int i = to_remove->begin_x(); i < to_remove->end_x(); i++){
    for (int j = to_remove->begin_y(); j < to_remove->end_y(); j++){
      matrix.false_element(i,j);
    }
  }
}

int main(){
  Breakable break_block = Breakable(1, 4, 2, 2);
  break_block.set_x_pos(1);
  cout << "Started" << endl;
  shared_ptr<Foobar> my_ptr;
  my_ptr = shared_ptr<Foobar>{ new Foobar(1,1,1,1) };
  Collision_handler col = Collision_handler(10,10);
  break_block.interact_type(my_ptr);
  //shared_ptr<Cluster> my_ptr;
  //my_ptr = shared_ptr<Cluster>{new Cluster(1, 1, 2, 2)} ;
  //my_ptr->set_des_x(1);
  //my_ptr->set_des_y(2);
  //col.fill_cluster(my_ptr);
  //col.move_event(break_block.get_cluster
  return 0;
};
