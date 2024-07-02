#include "pch.h"
#include "../../task7/task7/Container.h"
#include "../../task7/task7/Figures.h"
TEST(TestFigures, FigureSphere) {
	Sphere sphere(5);
	EXPECT_EQ(sphere.getInfo(), "this is sphere. It's radius - 5");
}

TEST(TestFigures, FigureCylinder) {
	Cylinder cylinder(7, 10);
	EXPECT_EQ(cylinder.getInfo(), "this is cylinder. It's radius - 7, height - 10");
}

TEST(TestFigures, FigurePyramid) {
	Pyramid pyramid(25, 5);
	EXPECT_EQ(pyramid.getInfo(), "this is pyramid. It's base area - 25, height - 5");
}

TEST(TestContainer, Container) {
	Container<Figure> container;
	container.push_back(new Sphere(3));
	container.push_back(new Cylinder(5, 7));
	container.push_back(new Pyramid(9,2));
	EXPECT_EQ(container[0]->getInfo(), "this is sphere. It's radius - 3");
	EXPECT_EQ(container[1]->getInfo(), "this is cylinder. It's radius - 5, height - 7");
	EXPECT_EQ(container[2]->getInfo(), "this is pyramid. It's base area - 9, height - 2");
}