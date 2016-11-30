#include "Generator.h"
#include "../Interactable-filer/Interactable.h"
#include <utility>

using namespace std;

Generator::Generator(float x, float y, float height, float width,
		    std::unique_ptr<Interactable> interactable)
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

void Generator::interact()
{
	this->generate();
}