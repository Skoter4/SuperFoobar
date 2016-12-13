#include "../Interactable-filer/Power_up.h"

using namespace std;


Power_up::Power_up(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

void Power_up::set_type(string new_type)
{
	this->type = new_type;
}

void Power_up::interact_with(std::shared_ptr<Map_object> map_object)
{
	if (map_object->type_str() == "foobar")
		this->flip_dead();

}

void Power_up::interact()
{
}

std::string Power_up::type_str()
{
	return this->type;
}
