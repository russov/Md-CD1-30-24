#pragma once
#include <iostream>
#include <string>
class Figure
{
public:
    virtual std::string getInfo() const = 0;
    virtual ~Figure() = default;
};

class Sphere: public Figure
{
private:
    int radius;
public:
    Sphere(int radius)
        :radius{ radius }
    {}

    std::string getInfo() const override
    {
        return ("this is sphere. It's radius - " + std::to_string(this->radius));
    }
};


class Cylinder : public Figure
{
private:
    int radius;
    int height;
public:
    Cylinder(int radius, int height)
        :radius{ radius }, height{ height }
    {}

    std::string getInfo() const override
    {
        return ("this is cylinder. It's radius - " + std::to_string(this->radius) + ", height - " + std::to_string(this->height));
    }
};


class Pyramid : public Figure
{
private:
    int baseArea;
    int height;
public:
    Pyramid(int baseArea, int height)
        :baseArea{ baseArea }, height{ height }
    {}

    std::string getInfo() const override
    {
        return ("this is pyramid. It's base area - " + std::to_string(this->baseArea) + ", height - " + std::to_string(this->height));
    }
};

