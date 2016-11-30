#include "../Block-filer/Block.h"
#include "../Interactable-filer/Interactable.h"
class Generator
	: protected Block
{
public:
	void interact() override;

	auto generate();
	void deactivate();

	void flip_deactivated();
	void flip_generating();

	~Generator() = default;

protected:

	Generator(float, float, float, float, std::unique_ptr<Interactable>);

private:

	bool deactivated{ false };
	bool generating{ false };

	std::unique_ptr<Interactable> reward;

};
