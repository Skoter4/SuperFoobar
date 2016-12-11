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

bool Breakable::interact_with(shared_ptr<Map_object> map_object) 
{
	if (map_object->type_str() == "foobar" && ((map_object->get_old_y()) >= this->get_height() + this->get_y_pos()))
		this->destruct();

	return false;
}

bool Breakable::to_break(shared_ptr<Cluster> other_cluster) {
	int block_y = this->get_y_pos();
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

