#include "../Interactable-filer/Finish_line.h"

using namespace std;

void Finish_line::poly()
{
}

Finish_line::Finish_line(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

bool Finish_line::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		interact();
	}
	return false;
}

void Finish_line::interact()
{
	//flip_activated();
	flip_dead();
}
/*
bool Finish_line::is_activated()
{
	return this->activated;
}

void Finish_line::flip_activated()
{
	this->activated = !(this->activated);
}
*/
std::string Finish_line::type_str()
{
	return this->type;
}
