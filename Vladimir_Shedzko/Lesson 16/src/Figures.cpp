#include "Figures.h"

#include <math.h>
#include <corecrt_math_defines.h>

float Figure::volume() const
{
    return 0.0f;
}

bool Figure::operator==(const Figure &other)
{
    return volume() == other.volume();
}

bool Figure::operator!=(const Figure &other)
{
    return !(*this == other);
}

Sphere::Sphere(const float _radius)
    : radius(_radius) {}

float Sphere::volume() const
{
    return  4/3*M_PI * pow(radius, 3);
}

Cylinder::Cylinder(const float _radius, const float _height)
    : Sphere(_radius), height(_height) {}

float Cylinder::volume() const
{
    return M_PI * pow(radius, 2) * height;
}

Pyramid::Pyramid(const float _radius, const float _height)
    : Cylinder(_radius, _height) {}

float Pyramid::volume() const
{
    return 1/3 * M_PI * pow(radius, 2) * height ;
}
