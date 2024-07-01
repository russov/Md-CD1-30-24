#include "pch.h"
#include "../Task7/main.cpp"


using namespace std;

TEST(TestFigures, Figures) {
    Sphere sphere(5.1);
    EXPECT_EQ(sphere.Square(), 4 * 3.14 * pow(5.1, 2));

    Cylinder cylinder(6.22, 6.44);
    EXPECT_EQ(cylinder.Square(), 2 * 3.14 * 6.22 * 6.44);

    Pyramid pyramid(7.3, 3.69);
    EXPECT_EQ(pyramid.Square(), pow(7.3, 2) + 2 * 7.3 * 3.69);
}


TEST(ArrayTest, AddObject) {
    Array<Figure> array;

    Sphere sphere(5.1);
    Cylinder cylinder(6.22, 6.44);
    Pyramid pyramid(7.3, 3.69);

    array.add(&sphere);
    array.add(&cylinder);
    array.add(&pyramid);

    EXPECT_EQ(array[0]->Square(), sphere.Square());
    EXPECT_EQ(array[1]->Square(), cylinder.Square());
    EXPECT_EQ(array[2]->Square(), pyramid.Square());
}





