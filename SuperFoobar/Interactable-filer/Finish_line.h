#pragma once
#include "Interactable.h"

class Finish_line : public Interactable
{
public:
	Finish_line(int, int, int, int);
	~Finish_line() = default;
	void interact_with(std::shared_ptr<Map_object> my_char) override;
	void interact() override;
	std::string type_str() override;
private:
	std::string type{ "finish_line" };
};
