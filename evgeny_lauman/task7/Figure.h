#include <iostream>
#include <string>

const double PI = 3.141592653589793;

class Figure
{
private:
	const std::string type;
	const double volume;
public:
	Figure(const std::string _type, const double _volume) : type(_type), volume{ _volume } {};
	void printVolume() const
	{
		std::cout.precision(4);
		std::cout << "Figure: " << type << " Volume: " << volume << std::endl;
	}
};

class Sphere : public Figure
{
private:
	const int radius;
public:
	Sphere(const int _radius) : Figure{ "Sphere", 4.0 / 3.0 * PI * std::pow(_radius, 3) }, radius{ _radius } {};
};

class Cylinder : public Figure
{
private:
	const int radius;
	const int heigth;
public:
	Cylinder(const int _radius, const int _heigth) : Figure{ "Cylinder", PI * std::pow(_radius, 2) * _heigth }, radius{ _radius }, heigth{ _heigth } {};
};

class Pyramid : public Figure
{
private:
	const int squere_base;
	const int heigth;
public:
	Pyramid(const int _squere_base, const int _heigth) : Figure{ "Pyramid", 1.0 / 3.0 * _squere_base * _heigth }, squere_base{ _squere_base }, heigth{ _heigth } {};
};

template <class T>
class Pointers
{
private:
	const T* ptr;
	const size_t size;
public:
	Pointers(const T* _ptr, const int _size) : ptr{ _ptr }, size(_size) { };
	T operator[](int _index) const 
	{ 
		if(_index<size) return ptr[_index]; 
		else throw std::out_of_range("out");
	}
};