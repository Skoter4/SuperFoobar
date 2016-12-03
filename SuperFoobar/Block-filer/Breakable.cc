#include "Breakable.h"
#include "../Character filer/Foobar/Foobar.h"
//#include "../Map_object.h"
#include <iostream>

using namespace std;

Breakable::Breakable(int x_pos, int y_pos, int length, int width)
  :Block(x_pos, y_pos, length, width)
{}

void Breakable::destruct()
{
  this->flip_dead();
}

bool Breakable::interact_type(shared_ptr<Map_object> my_char) {
	auto foobar = dynamic_cast<Foobar*>(my_char.get());
	if (foobar != nullptr) {
		cout << "Break" << endl;
		if (to_break(foobar->get_cluster()))
			interact();
			get_cluster()->set_remove(true);
			cout << "Removed" << endl;
			return true;
	}
	else {
		return false;
	}
}

bool Breakable::to_break(shared_ptr<Cluster> other_cluster) {
	int block_y = get_y_pos();
	int other_y = other_cluster->get_x();
	if (other_y < block_y) {
		return true;
	}
	else
	{
		return false;
	}

}

void Breakable::interact()
{ 
  this->destruct();
}

void Breakable::poly()
{

}

