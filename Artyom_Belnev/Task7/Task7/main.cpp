#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14;


template<typename T>
class Array {
private:
	vector<T*> elements;

public:
	Array() {}

	void add(T* object) {
		elements.push_back(object);
	}

	int size() {
		return elements.size();
	}

	T* operator[](int index) {
		if (index >= elements.size()) throw out_of_range("Index out of range");

		return elements[index];
	}

	virtual ~Array() {}
};

class Figure {
public:
	virtual double Square() const = 0;

	virtual ~Figure() {}
};

class Sphere : public Figure {
private:
	double radius;
public:
	Sphere(double radius) : radius(radius) {}

	double Square() const override {
		return 4 * PI * pow(radius, 2);
	}
};

class Cylinder : public Figure {
private:
	double radius;
	double height;
public:
	Cylinder(double radius, double height) : radius(radius), height(height) {}

	double Square() const override {
		return 2 * PI * radius * height;
	}
};

class Pyramid : public Figure {
private:
	double side;
	double apothem;
public:
	Pyramid(double side, double apothem) : side(side), apothem(apothem) {}

	double Square() const override {
		return pow(side, 2) + 2 * side * apothem;
	}
};
