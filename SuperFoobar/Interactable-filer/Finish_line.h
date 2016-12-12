#pragma once
#include "Interactable.h"

class Finish_line : public Interactable
{
public:
	void poly() override;
	Finish_line(int, int, int, int);
	~Finish_line() = default;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
	std::string type_str() override;
private:
	std::string type{ "finish_line" };
};
