#include <gtest/gtest.h>
#include <math.h>

#include "Container.h"
float truncate(float n, int precision) {
    float remainder = static_cast<float>((int)floor((n - floor(n)) * precision) % precision) / static_cast<float>(precision);
    return floor(n) + remainder;
}

TEST(FigureConstructor, sphere) {
    Sphere sphere {5};
    EXPECT_EQ(truncate(sphere.volume(), 9), truncate(4/3*M_PI*pow(5, 3), 9));
}

TEST(FigureConstructor, cylinder) {
    Cylinder cylinder {5, 10};
    EXPECT_EQ(truncate(cylinder.volume(), 9), truncate(10*M_PI*pow(5, 2), 9));
}

TEST(FigureConstructor, pyramid) {
    Pyramid pyramid {5, 10};
    EXPECT_EQ(truncate(pyramid.volume(), 9), truncate(1/3*10*M_PI*pow(5, 2), 9));
}

TEST(ContainerConstructor, emptyConstructor) {
    Container cont {};
    EXPECT_EQ(cont.size(), 0);
    EXPECT_EQ(cont.capacity(), 0);
}

TEST(ContainerEmpty, empty) {
    Container cont {};
    EXPECT_TRUE(cont.empty());
}

TEST(ContainerPushBack, pushBack) {
    Container<Pyramid> cont {};
    Pyramid pyramid {5, 10};

    cont.push_back(pyramid);
    EXPECT_EQ(cont.size(), 1);
}

TEST(ContainerPopBack, popBack) {
    Container<Cylinder> cont {};
    Cylinder cylinder1 {5, 10};
    Cylinder cylinder2 {15, 10};

    cont.push_back(cylinder1);
    cont.push_back(cylinder2);
    EXPECT_EQ( truncate(cont.pop_back().volume(), 9), truncate(cylinder2.volume(), 9));
    EXPECT_EQ(cont.size(), 1);
}

TEST(ContainerIndex, index) {
    Container<Pyramid> cont{};
    
    Pyramid pyramid1 {5, 10};
    Pyramid pyramid2 {10, 10};
    Pyramid pyramid3 {10, 20};

    cont.push_back(pyramid1);
    cont.push_back(pyramid2);
    cont.push_back(pyramid3);
    
    EXPECT_EQ(truncate(cont[0].volume(), 9), truncate(pyramid1.volume(), 9));
    EXPECT_EQ(truncate(cont[1].volume(), 9), truncate(pyramid2.volume(), 9));
    EXPECT_EQ(truncate(cont[2].volume(), 9), truncate(pyramid3.volume(), 9));

    EXPECT_THROW(cont[5], std::out_of_range);
}
