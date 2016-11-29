#pragma once
#include "../Interactable-filer/Interactable.h"

class Coin : public Interactable
{
public:
	Coin(float, float, float, float);
	~Coin() = default;
};
