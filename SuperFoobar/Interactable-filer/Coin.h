#pragma once
#include "Interactable.h"

class Coin : public Interactable
{
public:
	Coin(int, int, int, int);
	~Coin() = default;
};
