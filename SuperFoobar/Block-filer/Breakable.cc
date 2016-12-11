#include "Breakable.h"
#include "../Character filer/Foobar/Foobar.h"

using namespace std;

Breakable::Breakable(int x_pos, int y_pos, int length, int width)
  :Block(x_pos, y_pos, length, width)
{}

void Breakable::destruct()
{
  this->flip_dead();
}

std::string Breakable::type_str()
{
	return "breakable";
}

bool Breakable::interact_with(shared_ptr<Map_object> my_char) {
	cout << "In here" << endl;
	if (my_char->type_str() == "foobar") {
		cout << "Break" << endl;
		if (to_break(my_char->get_cluster()))
			interact();
			get_cluster()->set_remove(true);
			cout << "Removed" << endl;
		}
	return false;
}

bool Breakable::to_break(shared_ptr<Cluster> other_cluster) {
	int block_y = get_y_pos();
	int other_y = other_cluster->get_y();
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
  this->flip_active();
}

void Breakable::poly()
{

}

