#include <gtest/gtest.h>
#include "task_7.cpp"

TEST(FigureTest, Sphere) {
    Sphere sphere(3.8);
    ASSERT_DOUBLE_EQ(sphere.Volume(), (4.0/3.0) * 3.14 * pow(3.8, 3));
}

TEST(FigureTest, Cylinder) {
    Cylinder cylinder(4.2, 5.37);
    ASSERT_DOUBLE_EQ(cylinder.Volume(), 3.14 * pow(4.2, 2) * 5.37);
}

TEST(FigureTest, Pyramid) {
    Pyramid pyramid(26.47, 7.1);
    ASSERT_DOUBLE_EQ(pyramid.Volume(), (1.0/3.0) * 26.47 * 7.1);
}

TEST(ArrayStorageTest, AddingElements) {
    ArrayStorage<Figure> array;
    
    Sphere sphere(3.8);
    Cylinder cylinder(4.2, 5.37);
    Pyramid pyramid(26.47, 7.1);
    
    array.add_elements(&sphere);
    array.add_elements(&cylinder);
    array.add_elements(&pyramid);
    
    ASSERT_EQ(array[0]->Volume(), sphere.Volume());
    ASSERT_EQ(array[1]->Volume(), cylinder.Volume());
    ASSERT_EQ(array[2]->Volume(), pyramid.Volume());
}