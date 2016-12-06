#include "../Interactable-filer/Coin.h"

using namespace std;

void Coin::poly()
{
}

Coin::Coin(int x_pos, int y_pos, int height, int width)
	: Interactable(x_pos, y_pos, height, width)
{}

bool Coin::interact_type(std::shared_ptr<Map_object> my_char)
{
	return false;
}

void Coin::interact()
{
}

std::string Coin::type_str()
{
	return "coin";
}
