#pragma once
#include "../Interactable-filer/Interactable.h"

class Coin : public Interactable
{
public:
	Coin(int, int, int, int);
	~Coin() = default;
};
