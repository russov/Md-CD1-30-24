#pragma once
#include "Figure.h"
class Cylinder :
    public Figure
{
private:
    double radius;
    double h;
public:
    Cylinder(double rad, double h1) : Figure("Cylinder"), radius{ rad }, h{ h1 } {}
    virtual const std::string GetName() override;
    virtual const double GetVolume() override;
    const double GetRadius();
    const double GetH();
    virtual ~Cylinder() {}
};

