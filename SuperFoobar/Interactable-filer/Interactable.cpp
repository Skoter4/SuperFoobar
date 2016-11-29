#include "../Interactable-filer/Interactable.h"

using namespace std;

Interactable::Interactable(float x_pos, float y_pos, float height, float width)
	: position{ new Cluster(x_pos, y_pos, height, width) }
{}

bool Interactable::is_dead()
{
	return dead;
}

void Interactable::interact()
{
	dead = true;
}

float Interactable::get_width()
{
	return width;
}

float Interactable::get_length()
{
	return length;
}
void Interactable::flip_dead()
{
	dead = !dead;
}