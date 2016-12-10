#include "../Interactable-filer/Coin.h"

using namespace std;

void Coin::poly()
{
}

Coin::Coin(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

bool Coin::interact_with(std::shared_ptr<Map_object> map_object)
{
		if (map_object->type_str() == "foobar")
		{
			interact();
		}
		return false;
}

void Coin::interact()
{
	this->flip_dead();
}

std::string Coin::type_str()
{
	return "coin";
}
