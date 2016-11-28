#include "Generator.h"
#include "Interactable.h"
#include <utility>

using namespace std;

Generator::Generator(int x_pos, int y_pos, 
		    int length, int width,
		    unique_ptr<Interactable> interactable)
  :Block(x_pos, y_pos, length, width), interactable{move(interactable)}
{}

auto Generator::generate()
{
  
}
