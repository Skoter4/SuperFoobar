#pragma once
#include "Interactable.h"

class Finish_line : public Interactable
{
public:
	void poly() override;
	Finish_line(int, int, int, int);
	~Finish_line() = default;
};
