#include "../Interactable-filer/Power_up.h"

using namespace std;

void Power_up::poly()
{
}

Power_up::Power_up(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

bool Power_up::interact_with(std::shared_ptr<Map_object> my_char)
{
	return false;
}

void Power_up::interact()
{
}

std::string Power_up::type_str()
{
	return "power_up";
}
