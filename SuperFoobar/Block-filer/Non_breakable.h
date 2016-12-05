#include "../Block-filer/Block.h"
class Non_breakable
	: public Block
{
public:

	Non_breakable(int, int, int, int);

	void interact();

	~Non_breakable() = default;

};
