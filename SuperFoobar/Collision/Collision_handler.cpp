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

void Collision_handler::move_event(shared_ptr<Map_object> & moving){
  for (int i = moving->get_cluster()->begin_x(); i < moving->get_cluster()->end_x(); i++){
    for (int j = moving->get_cluster()->begin_y(); j < moving->get_cluster()->end_y(); j++){
      if (matrix.get_element(i, j) != nullptr){
		cout << "Cant move here" << endl;
		if (matrix.get_element(i, j)->interact_with(moving)) {
			update_position(moving);
		}
		if (matrix.get_element(i, j)->get_cluster()->get_to_remove()) {
			remove_cluster(matrix.get_element(i, j));
		}
		if (moving->get_cluster()->get_to_remove()) {
			remove_cluster(moving);
		}
	  }
    }
  }
}

void Collision_handler::fill_cluster(shared_ptr <Map_object> & to_fill) {
  for (int i = to_fill->get_cluster()->begin_x(); i < to_fill->get_cluster()->end_x(); i++){
    for (int j = to_fill->get_cluster()->begin_y(); j < to_fill->get_cluster()->end_y(); j++){
		matrix.true_element(i, j, to_fill);
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

void Collision_handler::update_position(shared_ptr<Map_object> to_update) {
	remove_cluster(to_update);
	int new_x_pos = to_update->get_desx_pos();
	int new_y_pos = to_update->get_desy_pos();
	to_update->set_x(new_x_pos);
	to_update->set_y(new_y_pos);
	fill_cluster(to_update);
}

<<<<<<< HEAD
void Collision_handler::create_list()
{
	vector<shared_ptr<Map_object>> object_list = vector<shared_ptr<Map_object>>(2);
	shared_ptr<Map_object> break_ptr;
	break_ptr = shared_ptr<Map_object>{ new Breakable(1,1,4,4) };
	shared_ptr<Map_object> my_ptr;
	my_ptr = shared_ptr<Map_object>{ new Foobar(1,1,1,1) };
	object_list[0] = break_ptr;
	object_list[1] = my_ptr;
}

void Collision_handler::check_list(shared_ptr<Map_object> to_check)
{
	cout << "Here" << endl;
	for (size_t i = 0; i < object_list.size(); i++)
	{
		cout << "Iter" << endl;
		check_collision(object_list[i], to_check);
		cout << i << endl;
	}
}

bool Collision_handler::check_collision(shared_ptr<Map_object> to_check, shared_ptr<Map_object> reference)
{

	return false;
}


int main(){
=======
/*int main(){
>>>>>>> refs/remotes/origin/master
  cout << "Started" << endl;
  Collision_handler col = Collision_handler(10,10);
  shared_ptr<Map_object> break_ptr;
  break_ptr = shared_ptr<Map_object>{ new Breakable(1,1,4,4)};
  col.fill_cluster(break_ptr);
  shared_ptr<Map_object> my_ptr;
  my_ptr = shared_ptr<Map_object>{ new Foobar(1,1,1,1) };
  col.create_list();
  col.check_list(my_ptr);
  //auto ptr = col.move_event(my_ptr);
  //ptr->interact_with(my_ptr);
  return 0;
<<<<<<< HEAD
};
=======
};
*/
>>>>>>> refs/remotes/origin/master
