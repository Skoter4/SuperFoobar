#pragma once
#include "../Block-filer/Block.h"
#include "../Interactable-filer/Interactable.h"
#include "../Character filer/Foobar/Foobar.h"

class Generator
	: public Block
{
public:
	Generator(int, int, int, int, std::shared_ptr<Interactable>);
	void interact() override;
	std::shared_ptr<Interactable> & generate();
	void interact_with(std::shared_ptr<Map_object> my_char) override;
	void flip_deactivated();
	void flip_generating();
	bool is_generating();
	bool is_deactivated();
	std::string type_str() override;
	bool to_break(std::shared_ptr<Cluster> other_cluster);

	~Generator() = default;

private:

	bool deactivated{ false };
	bool generating{ false };

	std::shared_ptr<Interactable> reward;

};
