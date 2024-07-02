#include "../../task7/task7/Container.h"
#include "../../task7/task7/Figures.h"
int main()
{
	Container<Figure> container;
	container.push_back(new Sphere(3));
	container.push_back(new Cylinder(5, 7));
	container.push_back(new Pyramid(9, 2));
	std::cout << container[1]->getInfo();
}