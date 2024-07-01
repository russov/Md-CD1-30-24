#include "pch.h"
#include "Figures.h"

TEST(FigureTest, SphereVolume) {
    Sphere sphere(3.0);
    EXPECT_NEAR(sphere.volume(), 113.097, 0.001);

    Sphere sphere_zero(0.0);
    EXPECT_NEAR(sphere_zero.volume(), 0.0, 0.001);

    EXPECT_THROW(Sphere(-1.0).volume(), std::invalid_argument);
}

TEST(FigureTest, CylinderVolume) {
    Cylinder cylinder(2.0, 5.0);
    EXPECT_NEAR(cylinder.volume(), 62.832, 0.001);

    Cylinder cylinder_zero(0.0, 5.0);
    EXPECT_NEAR(cylinder_zero.volume(), 0.0, 0.001);

    EXPECT_THROW(Cylinder(-2.0, 5.0).volume(), std::invalid_argument);
    EXPECT_THROW(Cylinder(2.0, -5.0).volume(), std::invalid_argument);
}

TEST(FigureTest, PyramidVolume) {
    Pyramid pyramid(6.0, 4.0);
    EXPECT_NEAR(pyramid.volume(), 8.0, 0.001);

    Pyramid pyramid_zero(0.0, 4.0);
    EXPECT_NEAR(pyramid_zero.volume(), 0.0, 0.001);

    EXPECT_THROW(Pyramid(-6.0, 4.0).volume(), std::invalid_argument);
    EXPECT_THROW(Pyramid(6.0, -4.0).volume(), std::invalid_argument);
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
    EXPECT_THROW(Figures[100], std::out_of_range);
}

TEST(ArrayTest, Memory) {
    Array<Figure> Figures;
    Figures.add(new Sphere(3.0));
    Figures.add(new Cylinder(2.0, 5.0));
    Figures.add(new Pyramid(6.0, 4.0));

    Figures.~Array();
    EXPECT_EQ(Figures.size(), 0);
}