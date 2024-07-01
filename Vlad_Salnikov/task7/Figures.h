#pragma once
#include <iostream>
#include <cmath>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template <typename T>
class Array {
private:
    std::vector<T*> elements;
public:
    void add(T* element) {
        elements.push_back(element);
    }

    T* operator[](std::size_t index) {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    std::size_t size() const {
        return elements.size();
    }

    ~Array() {
        for (T* element : elements) {
            delete element;
        }
    }
};

class Figure {
public:
    virtual double volume() const = 0;
    virtual ~Figure() = default;
};

class Sphere : public Figure {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {
        if (radius < 0) {
            throw std::invalid_argument("Radius cannot be negative");
        }
    }
    double volume() const override {
        return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    }
};

class Cylinder : public Figure {
private:
    double radius;
    double height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {
        if (radius < 0 || height < 0) {
            throw std::invalid_argument("Radius and height cannot be negative");
        }
    }
    double volume() const override {
        return M_PI * std::pow(radius, 2) * height;
    }
};

class Pyramid : public Figure {
private:
    double base_area;
    double height;
public:
    Pyramid(double b, double h) : base_area(b), height(h) {
        if (base_area < 0 || height < 0) {
            throw std::invalid_argument("Base area and height cannot be negative");
        }
    }
    double volume() const override {
        return (1.0 / 3.0) * base_area * height;
    }
};


