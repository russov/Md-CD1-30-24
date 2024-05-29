#include "pch.h"
#include "Figures.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(FigureTest, SphereVolume) {
    Sphere sphere(3.0);
    EXPECT_NEAR(sphere.volume(), 113.097, 0.001);
}

TEST(FigureTest, CylinderVolume) {
    Cylinder cylinder(2.0, 5.0);
    EXPECT_NEAR(cylinder.volume(), 62.832, 0.001);
}

TEST(FigureTest, PyramidVolume) {
    Pyramid pyramid(6.0, 4.0);
    EXPECT_NEAR(pyramid.volume(), 8.0, 0.001);
}

TEST(ArrayTest, AddAndRetrieveElements) {
    Array<Figure> Figures;
    Figures.add(new Sphere(3.0));
    Figures.add(new Cylinder(2.0, 5.0));
    Figures.add(new Pyramid(6.0, 4.0));

    EXPECT_NEAR(Figures[0]->volume(), 113.097, 0.001);
    EXPECT_NEAR(Figures[1]->volume(), 62.832, 0.001);
    EXPECT_NEAR(Figures[2]->volume(), 8.0, 0.001);
}

TEST(ArrayTest, OutOfRangeAccess) {
    Array<Figure> Figures;
    Figures.add(new Sphere(3.0));

    EXPECT_THROW(Figures[1], std::out_of_range);
}