#pragma once
#include "Interactable.h"

class Finish_line : protected Interactable
{
public:
	Finish_line(int, int, int, int);
	~Finish_line() = default;
};
