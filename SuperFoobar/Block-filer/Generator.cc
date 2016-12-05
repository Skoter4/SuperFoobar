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
	deactivated = !deactivated;
}

void Generator::flip_generating()
{
	generating = !generating;
}

auto Generator::generate()
{
	this->flip_generating();
	this->flip_deactivated();

	return move(this->reward);
}

bool Generator::interact_type(std::shared_ptr<Map_object> my_char)
{
	return false;
}

void Generator::interact()
{
	this->generate();
}

void Generator::poly()
{
}
