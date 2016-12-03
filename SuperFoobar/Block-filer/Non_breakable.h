#include "../Block-filer/Block.h"
class Non_breakable
	: public Block
{
public:

	Non_breakable(float, float, float, float);

	void interact();

	~Non_breakable() = default;

};
