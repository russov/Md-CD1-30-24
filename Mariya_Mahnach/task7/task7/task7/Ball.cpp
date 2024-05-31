#include "Ball.h"

const std::string Ball::GetName()
{
	return name;
}

const double Ball::GetVolume()
{
	return 4 * 3.1415926535 * pow(radius, 3)/3;
}

const double Ball::GetRadius()
{
	return radius;
}
