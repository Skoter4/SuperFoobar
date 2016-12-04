#pragma once
#include "../Block-filer/Block.h"

class Interactable;

class Generator
	: public Block
{
public:
	Generator(int, int, int, int, std::shared_ptr<Interactable>);
	void interact();

	auto generate();

	void flip_deactivated();
	void flip_generating();

	~Generator() = default;

protected:

	

private:

	bool deactivated{ false };
	bool generating{ false };

	std::shared_ptr<Interactable> reward;

};
