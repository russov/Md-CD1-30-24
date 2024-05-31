#include "Cylinder.h"

const std::string Cylinder::GetName()
{
	return name;
}

const double Cylinder::GetVolume()
{
	return 3.1415926535 * pow(radius, 2) * h;
}

const double Cylinder::GetRadius()
{
	return radius;
}

const double Cylinder::GetH()
{
	return h;
}
