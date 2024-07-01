#include "pch.h"
#include "Task7.h"

TEST(GeometricFigureTest, SphereVolumeValue) {
	Sphere sphere(10);
	double check_volume = (4.0 / 3.0) * std::numbers::pi * std::pow(10, 3);
	EXPECT_NEAR(check_volume, sphere.VolumeValue(), 1e-7);
}

TEST(GeometricFigureTest, CylinderVolumeValue) {
	Cylinder cylinder(10, 15);
	double check_volume = std::numbers::pi * std::pow(10, 2) * 15;
	EXPECT_NEAR(check_volume, cylinder.VolumeValue(), 1e-7);
}

TEST(GeometricFigureTest, PyramidVolumeValue) {
	Pyramid pyramid(15, 10);
	double check_volume = (1.0 / 3.0) * 15 * 10;
	EXPECT_NEAR(check_volume, pyramid.VolumeValue(), 1e-7);
}

TEST(GeometricFigureTest, AllOnceVolumeValue) {
	ArrayPointers<GeometricFigure> figures; 
	figures.Add(new Sphere(20));
	figures.Add(new Cylinder(20, 30));
	figures.Add(new Pyramid(30, 20));
	double check_volume0 = (4.0 / 3.0) * std::numbers::pi * std::pow(20, 3);
	double check_volume1 = std::numbers::pi * std::pow(20, 2) * 30;
	double check_volume2 = (1.0 / 3.0) * 30 * 20;
	EXPECT_NEAR(check_volume0, figures[0]->VolumeValue(), 1e-7);
	EXPECT_NEAR(check_volume1, figures[1]->VolumeValue(), 1e-7);
	EXPECT_NEAR(check_volume2, figures[2]->VolumeValue(), 1e-7);
}

TEST(ArrayPointersTest, FigureIndexInside) {
	ArrayPointers<GeometricFigure> figures;
	figures.Add(new Sphere(20));
	figures.Add(new Cylinder(20, 30));
	figures.Add(new Pyramid(30, 20));
	EXPECT_NO_THROW({
		GeometricFigure* value1 = figures[0];
		GeometricFigure* value2 = figures[1];
		GeometricFigure* value3 = figures[2];
		});
}

TEST(ArrayPointersTest, FigureIndexOut) {
	ArrayPointers<GeometricFigure> figures;
	figures.Add(new Sphere(20));
	figures.Add(new Cylinder(20, 30));
	figures.Add(new Pyramid(30, 20));
	EXPECT_THROW({
		GeometricFigure* value = figures[3];}, 
		std::out_of_range
		);
}