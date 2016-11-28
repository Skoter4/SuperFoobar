#pragma once
#include "Interactable.h"

class Power_up : public Interactable
{
public:
	Power_up(int, int, int, int);
	~Power_up() = default;
};
