#pragma once
#include "../Interactable-filer/Interactable.h"

class Coin : public Interactable
{
public:
	void poly() override;
	Coin(int, int, int, int);
	~Coin() = default;
	bool interact_type(std::shared_ptr<Map_object> my_char) override;

	void interact() override;

	std::string type_str() override;
};
