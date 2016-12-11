#include "Generator.h"
#include <utility>

using namespace std;

Generator::Generator(int x, int y, int height, int width,
		    std::shared_ptr<Interactable> interactable)
  :Block(x, y, height, width), reward(std::move(interactable))
{}

void Generator::flip_deactivated()
{
	this->deactivated = !deactivated;
}

void Generator::flip_generating()
{
	this->generating = !generating;
}

bool Generator::is_generating()
{
	return this->generating;
}

bool Generator::is_deactivated()
{
	return this->deactivated;
}

std::string Generator::type_str()
{
	return "generator";
}

std::shared_ptr<Interactable> & Generator::generate()
{
	this->flip_generating();
	this->flip_deactivated();

	return move(this->reward);
}

bool Generator::interact_with(std::shared_ptr<Map_object> map_object)
{
	if ((map_object->type_str() == "foobar") && !(this->is_deactivated()) && 
		((map_object->get_old_y()) >= this->get_height() + this->get_y_pos()))
		{
			interact();
		}
	return false;
}

bool Generator::to_break(shared_ptr<Cluster> other_cluster) {
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

void Generator::interact()
{
	this->flip_generating();
}

void Generator::poly()
{
}
