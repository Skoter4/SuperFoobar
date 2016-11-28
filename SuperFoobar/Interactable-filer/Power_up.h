#pragma once
#include "../Interactable-filer/Interactable.h"
#include "../Collision/Cluster.h"

class Power_up : public Interactable
{
public:
	Power_up(int, int, int, int);
	~Power_up() = default;
};
