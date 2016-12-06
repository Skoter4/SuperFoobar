#pragma once
#include "../Block-filer/Block.h"

class Interactable;

class Generator
	: public Block
{
public:
	Generator(int, int, int, int, std::shared_ptr<Interactable>);
	void interact() override;
	void poly() override;
	auto generate();
	bool interact_type(std::shared_ptr<Map_object> my_char) override;
	void flip_deactivated();
	void flip_generating();
	std::string type_str() override;

	~Generator() = default;

private:

	bool deactivated{ false };
	bool generating{ false };

	std::shared_ptr<Interactable> reward;

};
