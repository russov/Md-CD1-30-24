#include "pch.h"
#include "../Figure.h"

TEST(TestFigure, Constructor) 
{
	EXPECT_NO_THROW(Figure("Cube", 1.0));
}

TEST(TestFigure, PrintVolume)
{
	Figure c ("Cube", 1.0);
	EXPECT_NO_THROW(c.printVolume());
}

TEST(TestSphere, Constructor)
{
	EXPECT_NO_THROW(Sphere( 1 ));
}

TEST(TestSphere, PrintVolume)
{
	Sphere s(1);
	EXPECT_NO_THROW(s.printVolume());
}

TEST(TestCylinder, Constructor)
{
	EXPECT_NO_THROW(Cylinder( 1, 1 ));
}

TEST(TestCylinder, PrintVolume)
{
	Cylinder c( 1, 1 );
	EXPECT_NO_THROW(c.printVolume());
}

TEST(TestPyramid, Constructor)
{
	EXPECT_NO_THROW(Pyramid(1, 1));
}

TEST(TestPyramid, PrintVolume)
{
	Pyramid p( 1, 1 );
	EXPECT_NO_THROW(p.printVolume());
}

TEST(TestPointer, ConstructorSphere)
{
	const Sphere s_ptr[3]{ Sphere{1}, Sphere{2}, Sphere{3} };
	EXPECT_NO_THROW(Pointers<Sphere>( s_ptr, 3 ));
}

TEST(TestPointer, ConstructorCylinder)
{
	const Cylinder c_ptr[3]{ Cylinder{1,5}, Cylinder{2,10}, Cylinder{3,7} };
	EXPECT_NO_THROW(Pointers<Cylinder> cylinder_ptr( c_ptr, 3 ));
}

TEST(TestPointer, ConstructorPyramid)
{
	const Pyramid p_ptr[3]{ Pyramid{23,5}, Pyramid{10,1}, Pyramid{5,5} };
	EXPECT_NO_THROW(Pointers<Pyramid> pyramid_ptr( p_ptr, 3 ));
}

TEST(TestPointer, Index)
{
	const Pyramid p_ptr[3]{ Pyramid{23,5}, Pyramid{10,1}, Pyramid{5,5} };
	const Pointers<Pyramid> pyramid_ptr{ p_ptr, 3 };
	EXPECT_NO_THROW(Pyramid * p = &pyramid_ptr[0]);
}

TEST(TestPointer, outIndex1)
{
	const Pyramid p_ptr[3]{ Pyramid{23,5}, Pyramid{10,1}, Pyramid{5,5} };
	const Pointers<Pyramid> pyramid_ptr{ p_ptr, 3 };
	EXPECT_THROW(Pyramid* p = &pyramid_ptr[4], std::out_of_range);
}

TEST(TestPointer, outIndex2)
{
	const Pyramid p_ptr[3]{ Pyramid{23,5}, Pyramid{10,1}, Pyramid{5,5} };
	const Pointers<Pyramid> pyramid_ptr{ p_ptr, 3 };
	EXPECT_THROW(Pyramid * p = &pyramid_ptr[-1], std::out_of_range);
}


