#pragma once
#include "../Interactable-filer/Interactable.h"

class Coin : public Interactable
{
public:
	void poly() override;
	Coin(int, int, int, int);
	~Coin() = default;
};
