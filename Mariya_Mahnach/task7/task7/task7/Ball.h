#pragma once
#include <cmath>
#include "Figure.h"
class Ball :
    public Figure
{
private:
    double radius;
public:
    Ball(double rad) : Figure("ball"), radius{ rad } {}
    virtual const std::string GetName() override;
    virtual const double GetVolume() override;
    const double GetRadius();
    virtual ~Ball() {}
};
