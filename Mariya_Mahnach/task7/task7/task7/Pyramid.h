#pragma once
#include "Figure.h"
class Pyramid :
    public Figure
{
private:
    int sideNum;
    double h;
    double a;
public:
    Pyramid(int num, double h1, double a1) : Figure("Pyramid"), sideNum{ num }, h{ h1 }, a{ a1 }
    {
        name += num + '0';
    }
    virtual const std::string GetName() override;
    virtual const double GetVolume() override;
    const int GetSideNum();
    const double GetH();
    const double GetSide();
    virtual ~Pyramid() {}
};

