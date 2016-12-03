//#include "../Collision/Cluster.h"
#include "Interactable.h"


using namespace std;

Interactable::Interactable(int x_pos, int y_pos, int height, int width)
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

int Interactable::get_width()
{
	return width;
}

int Interactable::get_length()
{
	return length;
}
void Interactable::flip_dead()
{
	dead = !dead;
}