#include <iostream>
#include "Figure.h"
#include "Pyramid.h"
#include "Ball.h"
#include "Cylinder.h"
#include "Array.h"
int main()
{
	Ball b1(35),b2(3),b3(12);
	Cylinder c1(5, 20),c2(3,6),c3(2,8);
	Pyramid p1(4, 7,2),p2(3,4,5),p3(5,7,10);
	
	const int size = 3;

	Array<Ball> balls(size) ;
	balls[0] = &b1;
	balls[1] = &b2;
	balls[2] = &b3;

	Array<Cylinder> cylinders(size);
	cylinders[0] = &c1;
	cylinders[1] = &c2;
	cylinders[2] = &c3;

	Array<Pyramid> pyramides(size);
	pyramides[0] = &p1;
	pyramides[1] = &p2;
	pyramides[2] = &p3;
	
	for (int i = 0; i < size; i++)
	{
		balls[i]->Print();
		cylinders[i]->Print();
		pyramides[i]->Print();
	}
	

	std::cout << "Balls:\n";
	b1.Print(); b2.Print(); b3.Print();
	std::cout << "\nCylinders:\n";
	c1.Print(); c2.Print(); c3.Print();
	std::cout << "\nPyramides:\n";
	p1.Print(); p2.Print(); p3.Print();
}

