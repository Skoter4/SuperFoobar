#include "../Block-filer/Block.h"
class Non_breakable
	: public Block
{
public:

	Non_breakable(int, int, int, int);
	void poly() override;
	void interact();
	bool interact_type(std::shared_ptr<Map_object> my_char) override;
	~Non_breakable() = default;

};
