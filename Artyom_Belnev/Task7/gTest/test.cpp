#include "pch.h"
#include "../Task7/main.cpp"

using namespace std;

TEST(ArrayConstructorTest, DefaultConstructor) {
	Sphere sphere;
	Array<Sphere> arrayOfSpheres;
	EXPECT_EQ(arrayOfSpheres.size(), 0);

	Cylinder cylinder;
	Array<Cylinder> arrayOfCylinder;
	EXPECT_EQ(arrayOfCylinder.size(), 0);

	Pyramid pyramid;
	Array<Pyramid> arrayOfPyramid;
	EXPECT_EQ(arrayOfPyramid.size(), 0);
}

TEST(ArraySizeTest, Size) {
	Sphere sphere;
	Array<Sphere> arrayOfSpheres;
	arrayOfSpheres.add(&sphere);
	EXPECT_EQ(arrayOfSpheres.size(), 1);

	Cylinder cylinder;
	Array<Cylinder> arrayOfCylinder;
	arrayOfCylinder.add(&cylinder);
	EXPECT_EQ(arrayOfCylinder.size(), 1);

	Pyramid pyramid;
	Array<Pyramid> arrayOfPyramid;
	arrayOfPyramid.add(&pyramid);
	EXPECT_EQ(arrayOfPyramid.size(), 1);
}

TEST(ArrayGetNameTest, GetName) {
	Sphere sphere;
	Array<Sphere> arrayOfSpheres;
	arrayOfSpheres.add(&sphere);
	EXPECT_EQ(arrayOfSpheres[0].getName(), sphere.getName());

	Cylinder cylinder;
	Array<Cylinder> arrayOfCylinder;
	arrayOfCylinder.add(&cylinder);
	EXPECT_EQ(arrayOfCylinder[0].getName(), cylinder.getName());

	Pyramid pyramid;
	Array<Pyramid> arrayOfPyramid;
	arrayOfPyramid.add(&pyramid);
	EXPECT_EQ(arrayOfPyramid[0].getName(), pyramid.getName());
}