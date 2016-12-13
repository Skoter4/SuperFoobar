#pragma once
#include <string>
#include "../Interactable-filer/Interactable.h"

class Coin : public Interactable
{
public:

	Coin(int, int, int, int);
	~Coin() = default;
	void interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;

	std::string type_str() override;
};
