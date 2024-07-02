#include "Figure.h"

const void Figure::Print()
{
	std::cout << this->GetName() << ": " << this->GetVolume()<<'\n';
}