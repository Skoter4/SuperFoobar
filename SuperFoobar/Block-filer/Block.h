#pragma once
#include <memory>
#include "../Collision/Cluster.h"
#include "../Map_object.h"

class Block :public Map_object{
public:
	~Block() = default;
	Block() = default;

	virtual void interact() = 0;

protected:
	Block(int, int, int, int);
};
