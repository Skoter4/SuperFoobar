#include "Generator.h"
#include "../Interactable-filer/Interactable.h"
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

std::string Generator::type_str()
{
	return "generator";
}

auto Generator::generate()
{
	this->flip_generating();
	this->flip_deactivated();

	return move(this->reward);
}

bool Generator::interact_with(std::shared_ptr<Map_object> my_char)
{
	if (my_char->type_str() == "foobar") {
		if (to_break(my_char->get_cluster())) {
			interact();
		}
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
	this->generate();
}

void Generator::poly()
{
}
