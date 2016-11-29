#pragma once
#include "../Interactable-filer/Interactable.h"
#include "../Collision/Cluster.h"

class Power_up : public Interactable
{
public:
	Power_up(float, float, float, float);
	~Power_up() = default;
};
