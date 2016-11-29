#pragma once
#include "Interactable.h"

class Finish_line : protected Interactable
{
public:
	Finish_line(float, float, float, float);
	~Finish_line() = default;
};
