#include "Interactable.h"

using namespace std;

Interactable::Interactable(int x_pos, int y_pos, int width, int length)
	: position{ make_unique<Position>(x_pos, y_pos) }, width{ width }, length{ length }
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