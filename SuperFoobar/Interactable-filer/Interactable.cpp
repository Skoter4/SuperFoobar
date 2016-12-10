//#include "../Collision/Cluster.h"
#include "Interactable.h"


using namespace std;

Interactable::Interactable(int x_pos, int y_pos, int height, int width)
	: Map_object(x_pos, y_pos, height, width)
{}

void Interactable::interact()
{
	this->flip_dead();
}
