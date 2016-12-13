#include "../Interactable-filer/Finish_line.h"

using namespace std;


Finish_line::Finish_line(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

void Finish_line::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
	{
		interact();
	}
}

void Finish_line::interact()
{
	flip_dead();
}
std::string Finish_line::type_str()
{
	return this->type;
}
