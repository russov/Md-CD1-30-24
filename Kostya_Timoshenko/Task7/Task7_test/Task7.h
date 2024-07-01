#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <numbers> //Requires C++20 to be enabled for pi

class GeometricFigure { // Geometric figure class
public:
    virtual double VolumeValue() = 0; // Virtual function for volume
    virtual ~GeometricFigure() {} // Virtual destructor
};

class Sphere : public GeometricFigure { // Sphere class
private:
    double radius_sphere_;
public:
    Sphere(double radius) : radius_sphere_(radius) {}
    double VolumeValue() override {
        return (4.0 / 3.0) * std::numbers::pi * std::pow(radius_sphere_, 3);
    }
};

class Cylinder : public GeometricFigure { // Cylinder class
private:
    double radius_cylinder_;
    double height_cylinder_;
public:
    Cylinder(double radius, double height) : radius_cylinder_(radius), height_cylinder_(height) {}
    double VolumeValue() override {
        return std::numbers::pi * std::pow(radius_cylinder_, 2) * height_cylinder_;
    }
};

class Pyramid : public GeometricFigure { // Pyramid class
private:
    double grounds_pyramid_;
    double height_pyramid_;
public:
    Pyramid(double grounds, double height) : grounds_pyramid_(grounds), height_pyramid_(height) {}
    double VolumeValue() override {
        return (1.0 / 3.0) * grounds_pyramid_ * height_pyramid_;
    }
};

template <class T>
class ArrayPointers {
private:
    std::vector<T*> elements_; // A vector that will store pointers
public:
    ArrayPointers() {} // Constructor
    ~ArrayPointers() { // Destructor
        for (auto& element : elements_) {
            delete element;
        }
    }
    void Add(T* element) { // Adding elements
        elements_.push_back(element);
    }
    T* operator[](size_t index) { // Operator overloading []
        if (index >= elements_.size()) {
            throw std::out_of_range("Outside!"); // If it is outside the limits, an exception will be thrown
        }
        return elements_[index]; 
    }
    size_t Size() const { // Getting the vector size
        return elements_.size();
    }
};

int main() {
    ArrayPointers<GeometricFigure> figures; // For figures
    figures.Add(new Sphere(5));
    figures.Add(new Cylinder(3, 5));
    figures.Add(new Pyramid(10, 5));
    for (size_t i = 0; i < figures.Size(); ++i) { // We derive the volume of our three figures
        std::cout << "Volume figure " << i << ": " << figures[i]->VolumeValue() << std::endl;
    }
    ArrayPointers<int> numbers; // For numbers
    numbers.Add(new int(1));
    numbers.Add(new int(2));
    numbers.Add(new int(3));
    for (size_t i = 0; i < numbers.Size(); ++i) { // Outputting the meaning of numbers
        std::cout << "Value index " << i << ": " << *numbers[i] << std::endl;
    }
    std::cin.get();
    return 0;
}

//int main(int argc, char** argv) { //For tests
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS(); 
//}