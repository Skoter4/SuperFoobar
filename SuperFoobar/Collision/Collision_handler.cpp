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

shared_ptr<Map_object> Collision_handler::move_event(shared_ptr<Map_object> & moving){
  for (int i = moving->get_cluster()->begin_x(); i < moving->get_cluster()->end_x(); i++){
    for (int j = moving->get_cluster()->begin_y(); j < moving->get_cluster()->end_y(); j++){
      if (matrix.get_element(i, j) != nullptr){
		cout << "Cant move here" << endl;
		return matrix.get_element(i,j);
	  }
    }
  }
  return nullptr;
}

void Collision_handler::fill_cluster(shared_ptr <Map_object> & to_fill) {
	auto foobar = dynamic_cast<Foobar*>(to_fill.get());
	if (foobar == nullptr) {
		cout << "Casted in handlr lmao" << endl;
	}
  for (int i = to_fill->get_cluster()->begin_x(); i < to_fill->get_cluster()->end_x(); i++){
    for (int j = to_fill->get_cluster()->begin_y(); j < to_fill->get_cluster()->end_y(); j++){
	  auto foobar = dynamic_cast<Foobar*>(to_fill.get());
	  if (foobar == nullptr){
		  cout << "Casted in handlr" << endl;
	  }
      matrix.true_element(i,j, to_fill);
    }
  }
}

void Collision_handler::remove_cluster(shared_ptr<Map_object> to_remove){
  for (int i = to_remove->get_cluster()->begin_x(); i < to_remove->get_cluster()->end_x(); i++){
    for (int j = to_remove->get_cluster()->begin_y(); j < to_remove->get_cluster()->end_y(); j++){
      matrix.false_element(i,j);
    }
  }
}

int main(){
  cout << "Started" << endl;
  Collision_handler col = Collision_handler(10,10);
  shared_ptr<Map_object> break_ptr;
  break_ptr = shared_ptr<Map_object>{ new Breakable(1,1,4,4)};
  col.fill_cluster(break_ptr);
  shared_ptr<Map_object> my_ptr;
  my_ptr = shared_ptr<Map_object>{ new Foobar(1,1,1,1) };
  //break_ptr->set_x_pos(1);
  //break_ptr->set_y_pos(1);
  //col.fill_cluster(my_ptr);
  //auto kek = col.move_event(break_ptr);
  //kek->get_cluster()->print_x_y();
  //break_ptr->interact_type(kek);
  //break_ptr->interact_type(my_ptr);
  return 0;
};
