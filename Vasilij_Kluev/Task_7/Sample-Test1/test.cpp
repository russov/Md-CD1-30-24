#include "pch.h"
#include <iostream>
#include "../Task_8/figure.h"
#include "../Task_8/TemplateClass.h"
#include "..//Task_8/figure.cpp"

TEST(Testing_Ball, Constructor_test) {
	Ball a;
	Ball* pointer_a = &a;
	EXPECT_TRUE(pointer_a != NULL);
}
TEST(Testing_Pyramid, Constructor_test) {
	Pyramid b;
	Pyramid* pointer_b = &b;
	EXPECT_TRUE(pointer_b != NULL);
}
TEST(Testing_Cylinder, Constructor_test) {
	Cylinder c;
	Cylinder* pointer_c = &c;
	EXPECT_TRUE(pointer_c != NULL);
}
TEST(Testing_TemplateClass, Constructor_test) {
	TemplateClass<Figure> figures;
	TemplateClass<Figure>* pointer = &figures;
	EXPECT_TRUE(pointer != NULL);
}
TEST(Testing_TemplateClass, Add_Function_test) {
	TemplateClass<Figure> f;
	Ball* ball = new Ball;
	f.add(ball);
	EXPECT_EQ(f[0],ball);
}
TEST(Testing_TemplateClass, Add_Function_test_Type_of_object_and_breaksOperator) {
	TemplateClass<Figure> f;
	Ball* ball = new Ball;
	f.add(ball);
	EXPECT_EQ(typeid(*(f[0])), typeid(Ball));
}
