#pragma once
#include "../Block-filer/Block.h"

class Interactable;

class Generator
	: public Block
{
public:
	Generator(float, float, float, float, std::unique_ptr<Interactable>);
	void interact();

	auto generate();
	void deactivate();

	void flip_deactivated();
	void flip_generating();

	~Generator() = default;

protected:

	

private:

	bool deactivated{ false };
	bool generating{ false };

	std::unique_ptr<Interactable> reward;

};
