#include "../Interactable-filer/Finish_line.h"

using namespace std;

void Finish_line::poly()
{
}

Finish_line::Finish_line(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

bool Finish_line::interact_type(std::shared_ptr<Map_object> my_char)
{
	return false;
}

void Finish_line::interact()
{
}

std::string Finish_line::type_str()
{
	return "finish_line";
}
