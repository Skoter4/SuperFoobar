#pragma once
#include "../Interactable-filer/Interactable.h"
#include "../Collision/Cluster.h"

class Power_up : public Interactable
{
public:
	void poly() override;
	Power_up(int, int, int, int);
	~Power_up() = default;

	void set_type(std::string);
	bool interact_with(std::shared_ptr<Map_object> my_char) override;

	void interact() override;

	std::string type_str() override;

private:
	std::string type{ "powerup" };
};
