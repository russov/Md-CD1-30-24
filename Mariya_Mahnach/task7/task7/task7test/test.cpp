#include "pch.h"
#include "../task7/Array.h"
#include "../task7/Figure.h"
#include "../task7/Pyramid.h"
#include "../task7/Ball.h"
#include "../task7/Cylinder.h"

TEST(CreateBall, Volume)
{
	Ball ball(10);
	EXPECT_DOUBLE_EQ(ball.GetVolume(), 4188.79020);
}
TEST(CreateBall, Radius)
{
	Ball ball(10);
	EXPECT_EQ(10, ball.GetRadius());
}
TEST(CreateBall, Name)
{
	Ball ball(10);
	EXPECT_EQ("Ball",ball.GetName());
}

TEST(CreateCylinder, Volume)
{
	Cylinder cylinder(10,5);
	EXPECT_DOUBLE_EQ(cylinder.GetVolume(), 1570.79633);
}
TEST(CreateCylinder, Radius)
{
	Cylinder cylinder(10, 5);
	EXPECT_EQ(10, cylinder.GetRadius());
}
TEST(CreateCylinder, Height)
{
	Cylinder cylinder(10, 5);
	EXPECT_EQ(5, cylinder.GetH());
}
TEST(CreateCylinder, Name)
{
	Cylinder cylinder(10, 5);
	EXPECT_EQ("Cylinder", cylinder.GetName());
}

TEST(CreatePyramid, Volume)
{
	Pyramid pyramid(4,3,5);
	EXPECT_DOUBLE_EQ(pyramid.GetVolume(), 15);
}
TEST(CreatePyramid, SideNum)
{
	Pyramid pyramid(4, 3, 5);
	EXPECT_EQ(4, pyramid.GetSideNum());
}
TEST(CreatePyramid, Height)
{
	Pyramid pyramid(4, 3, 5);
	EXPECT_EQ(3, pyramid.GetH());
}
TEST(CreatePyramid, Side)
{
	Pyramid pyramid(4, 3, 5);
	EXPECT_EQ(3, pyramid.GetSide());
}
TEST(CreatePyramid, Name)
{
	Pyramid pyramid(4, 3, 5);
	EXPECT_EQ("Pyramid", pyramid.GetName());
}

TEST(Array, Create)
{
	Array<int> arr(3);
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(arr[i], nullptr);
	}
}
TEST(Array, indexOperator)
{
	Array<int> arr(3);
	int a = 1, b = 3, c = 5;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(*arr[i], i*2+1);
	}
}
TEST(Array, OutOfRangeExeption)
{
	Array<short int> arr(5);
	ASSERT_THROW(arr[6], std::out_of_range);
}