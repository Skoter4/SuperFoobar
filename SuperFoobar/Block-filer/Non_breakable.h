#pragma once
#include "../Block-filer/Block.h"
#include "../Character filer/Enemy/Enemy_2.h"
#include "../Character filer/Enemy/Enemy_3.h"


class Non_breakable
	: public Block
{
public:

	Non_breakable(int, int, int, int);
	void poly() override;
	void interact() override;
	bool interact_with(std::shared_ptr<Map_object> my_char) override;
	~Non_breakable() = default;
	std::string type_str() override;
};
